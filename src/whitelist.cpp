#include "../include/whitelist.h"
#include "ui_whitelist.h"

Whitelist::Whitelist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Whitelist)
{
    ui->setupUi(this);
}

Whitelist::~Whitelist()
{
    delete ui;
}

void Whitelist::on_buttonBox_accepted()
{
    hide();
}


void Whitelist::on_buttonBox_rejected()
{
    hide();
}

