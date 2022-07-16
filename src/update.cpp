#include "../include/update.h"
#include "ui_update.h"

Update::Update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);
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

