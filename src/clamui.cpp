#include "clamui.h"
#include "ui_clamui.h"


ClamUI::ClamUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClamUI)
{
    ui->setupUi(this);
    engine = setupEngine();

    QCoreApplication::setOrganizationName("deltaForce");
    QCoreApplication::setApplicationName("Clamav UI");
    QIcon settingsicon = QIcon::fromTheme("settings-configure");
    QIcon whitelisticon = QIcon::fromTheme("answer");
    QIcon scheduleicon = QIcon::fromTheme("view-time-schedule-edit");
    QIcon historyicon = QIcon::fromTheme("deep-history");
    QIcon quarantineicon = QIcon::fromTheme("error");
    QIcon noupdateicon = QIcon::fromTheme("update-none");
    QIcon lowupdateicon = QIcon::fromTheme("update-low");
    QIcon mediumupdateicon = QIcon::fromTheme("update-medium");
    QIcon highupdateicon = QIcon::fromTheme("update-high");
    QIcon updateassistanticon = QIcon::fromTheme("games-config-custom");
    QIcon scanfileicon = QIcon::fromTheme("document-scan");
    QIcon scansystemicon = QIcon::fromTheme("security-high-symbolic");
    QIcon scandirectoryicon = QIcon::fromTheme("system-file-manager");
    QIcon analysisicon = QIcon::fromTheme("search");

    ui->settingsButton->setIcon(settingsicon);
    ui->whitelistButton->setIcon(whitelisticon);
    ui->scheduleButton->setIcon(scheduleicon);
    ui->historyButton->setIcon(historyicon);
    ui->quarantineButton->setIcon(quarantineicon);
    ui->updateButton->setIcon(noupdateicon);
    ui->scanFileButton->setIcon(scanfileicon);
    ui->scanDirectoryButton->setIcon(scandirectoryicon);
    ui->scanSystemButton->setIcon(scansystemicon);
    ui->analysisButton->setIcon(analysisicon);

}

ClamUI::~ClamUI()
{
    delete ui;
}


void ClamUI::on_settingsButton_clicked()
{
    Settings settings;
    settings.exec();
}


void ClamUI::on_whitelistButton_clicked()
{
    Whitelist whitelist;
    whitelist.exec();
}

void ClamUI::on_scheduleButton_clicked()
{
    Schedule schedule;
    schedule.exec();
}


void ClamUI::on_historyButton_clicked()
{
    History history;
    history.exec();
}


void ClamUI::on_quarantineButton_clicked()
{
    Quarantine quarantine;
    quarantine.exec();
}


void ClamUI::on_updateButton_clicked()
{
    Update update;
    update.exec();
}


void ClamUI::on_analysisButton_clicked()
{
    Analysis analysis;
    analysis.exec();
}



void ClamUI::on_scanFileButton_clicked()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Choose a file"), home);
    for (int i = 0; i < filenames.size(); ++i){
        qDebug() << filenames.at(i).toLocal8Bit().constData() << Qt::endl;
    }
}


void ClamUI::on_scanDirectoryButton_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    home,
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
}


void ClamUI::on_scanSystemButton_clicked(){
    hide();
}
