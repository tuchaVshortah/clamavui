#include "../include/scandirectory.h"
#include "ui_scandirectory.h"

ScanDirectory::ScanDirectory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScanDirectory)
{
    ui->setupUi(this);
}

ScanDirectory::~ScanDirectory()
{
    delete ui;
}

void ScanDirectory::on_buttonBox_accepted()
{
    hide();
}


void ScanDirectory::on_buttonBox_rejected()
{
    hide();
}

