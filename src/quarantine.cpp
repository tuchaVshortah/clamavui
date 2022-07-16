#include "../include/quarantine.h"
#include "ui_quarantine.h"

Quarantine::Quarantine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Quarantine)
{
    ui->setupUi(this);
}

Quarantine::~Quarantine()
{
    delete ui;
}

void Quarantine::on_buttonBox_accepted()
{
    hide();
}


void Quarantine::on_buttonBox_rejected()
{
    hide();
}

