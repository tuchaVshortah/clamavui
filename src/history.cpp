#include "history.h"
#include "ui_history.h"

History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::on_buttonBox_accepted()
{
    hide();
}


void History::on_buttonBox_rejected()
{
    hide();
}

