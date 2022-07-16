#include "../include/schedule.h"
#include "ui_schedule.h"

Schedule::Schedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Schedule)
{
    ui->setupUi(this);
}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::on_buttonBox_accepted()
{
    hide();
}


void Schedule::on_buttonBox_rejected()
{
    hide();
}

