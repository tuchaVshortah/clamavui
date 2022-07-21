#include "analysis.h"
#include "ui_analysis.h"

Analysis::Analysis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Analysis)
{
    ui->setupUi(this);
}

Analysis::~Analysis()
{
    delete ui;
}

void Analysis::on_buttonBox_accepted()
{
    hide();
}


void Analysis::on_buttonBox_rejected()
{
    hide();
}

