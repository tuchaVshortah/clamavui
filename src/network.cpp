#include "../include/network.h"
#include "ui_network.h"

Network::Network(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Network)
{
    ui->setupUi(this);
}

Network::~Network()
{
    delete ui;
}

void Network::on_buttonBox_accepted()
{
    hide();
}


void Network::on_buttonBox_rejected()
{
    hide();
}

