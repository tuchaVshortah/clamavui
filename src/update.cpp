#include "update.h"
#include "ui_update.h"

Update::Update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);
    readLogs();
}

Update::~Update()
{
    delete ui;
}

void Update::on_buttonBox_accepted()
{
    hide();
}


void Update::on_buttonBox_rejected()
{
    hide();
}

void Update::on_checkUpdates_clicked()
{
    Action updateAction("org.tuchavshortah.clamavui.antivirus.updatesigs");
    updateAction.setHelperId("org.tuchavshortah.clamavui.antivirus");

    ExecuteJob *job = updateAction.execute();

    connect(job, &ExecuteJob::result, this, &Update::on_updates);
    job->start();
}

void Update::on_updates(KJob *kjob){
    KAuth::ExecuteJob *job = (KAuth::ExecuteJob *)kjob;
    if(job->error()){
        QMessageBox::critical(this, tr("Something bad happened"), tr("Error: ") + job->errorText().toStdString().c_str());
    } else if(job->data()["init_result"].toUInt() != CL_SUCCESS){
        QMessageBox::warning(this, tr("Libclamav error"), cl_strerror(job->data()["init_result"].toUInt()));
    } else if(job->data()["update_result"].toUInt() != FC_SUCCESS){
        QMessageBox::warning(this, tr("Libfreshclam error"), tr("Error: ") + fc_strerror(static_cast<fc_error_t>(job->data()["update_result"].toInt())));
    }
}

void Update::readLogs(){
    QFile logFile(logs);
    QString contents;

    if(!logFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Error"), logFile.errorString());
    }

    QTextStream textStream(&logFile);

    while (true){

        QString line = textStream.readLine();

        if (line.isNull()) {
            break;
        }else {
            contents.append(line);
        }
    }

    ui->logsTextEdit->setText(contents);
}
