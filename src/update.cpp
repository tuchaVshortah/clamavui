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

    connect(job, &KJob::result, this, &Update::on_updates);
    job->start();
}

void Update::on_updates(){
    readLogs();
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
