#include "../include/settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    if(settings.value("settings/puas").toBool()){
        ui->checkBoxScanForPuas->setCheckState(Qt::Checked);
    }
    if(settings.value("settings/heuristics").toBool()){
        ui->checkBoxUseHeuristicScanning->setCheckState(Qt::Checked);
    }
    if(settings.value("settings/scanDotFiles").toBool()){
        ui->checkBoxScanDotFiles->setCheckState(Qt::Checked);
    }
    if(settings.value("settings/scanBigFiles").toBool()){
        ui->checkBoxScanBigFiles->setCheckState(Qt::Checked);
    }
    if(settings.value("settings/scanDirectoriesRecursively").toBool()){
        ui->checkBoxScanRecursively->setCheckState(Qt::Checked);
    }
    if(settings.value("settings/softwareUpdates").toBool()){
        ui->checkBoxUpdates->setCheckState(Qt::Checked);
    }
    if(settings.value("settings/signatureUpdates").toBool()){
        ui->autoUpdatesButton->setChecked(Qt::Checked);
    }
}

Settings::~Settings()
{
    delete ui;
    settings.sync();
}


void Settings::on_buttonBox_accepted()
{
    settings.sync();
    close();
}


void Settings::on_buttonBox_rejected()
{
    close();
}


void Settings::on_checkBoxScanForPuas_stateChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Unchecked){
        settings.setValue("settings/puas", false);
    }else if(arg1 == Qt::CheckState::Checked){
        settings.setValue("settings/puas", true);
    }
}


void Settings::on_checkBoxUseHeuristicScanning_stateChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Unchecked){
        settings.setValue("settings/heuristics", false);
    }else if(arg1 == Qt::CheckState::Checked){
        settings.setValue("settings/heuristics", true);
    }
}


void Settings::on_checkBoxScanDotFiles_stateChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Unchecked){
        settings.setValue("settings/scanDotFiles", false);
    }else if(arg1 == Qt::CheckState::Checked){
        settings.setValue("settings/scanDotFiles", true);
    }
}


void Settings::on_checkBoxScanBigFiles_stateChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Unchecked){
        settings.setValue("settings/scanBigFiles", false);
    }else if(arg1 == Qt::CheckState::Checked){
        settings.setValue("settings/scanBigFiles", true);
    }
}


void Settings::on_checkBoxScanRecursively_stateChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Unchecked){
        settings.setValue("settings/scanDirectoriesRecursively", false);
    }else if(arg1 == Qt::CheckState::Checked){
        settings.setValue("settings/scanDirectoriesRecursively", true);
    }
}


void Settings::on_checkBoxUpdates_stateChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Unchecked){
        settings.setValue("settings/softwareUpdates", false);
    }else if(arg1 == Qt::CheckState::Checked){
        settings.setValue("settings/softwareUpdates", true);
    }
}





void Settings::on_autoUpdatesButton_clicked(bool checked)
{
    if(checked){
        settings.setValue("settings/signatureUpdates", true);
        if(ui->manualUpdatesButton->isChecked()){
            ui->manualUpdatesButton->animateClick();
        }
    }
}


void Settings::on_manualUpdatesButton_clicked(bool checked)
{
    if(checked){
        settings.setValue("settings/signatureUpdates", false);
        if(ui->autoUpdatesButton->isChecked()){
            ui->autoUpdatesButton->animateClick();
        }
    }
}
void Settings::on_noProxy_clicked()
{
    ui->AddressEdit->setEnabled(false);
    ui->PortEdit->setEnabled(false);
}


void Settings::on_systemProxy_clicked()
{
    ui->AddressEdit->setEnabled(false);
    ui->PortEdit->setEnabled(false);
}


void Settings::on_manualProxy_clicked()
{
    ui->AddressEdit->setEnabled(true);
    ui->PortEdit->setEnabled(true);
}

