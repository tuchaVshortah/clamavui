#include "scan.h"
#include "ui_scanfile.h"

ScanFile::ScanFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScanFile)
{
    ui->setupUi(this);
}

ScanFile::~ScanFile()
{
    delete ui;
}

void ScanFile::on_buttonBox_accepted()
{
    hide();
}


void ScanFile::on_buttonBox_rejected()
{
    hide();
}

