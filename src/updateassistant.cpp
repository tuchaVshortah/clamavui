#include "../include/updateassistant.h"
#include "ui_updateassistant.h"

UpdateAssistant::UpdateAssistant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateAssistant)
{
    ui->setupUi(this);
}

UpdateAssistant::~UpdateAssistant()
{
    delete ui;
}

void UpdateAssistant::on_buttonBox_accepted()
{
    hide();
}


void UpdateAssistant::on_buttonBox_rejected()
{
    hide();
}

