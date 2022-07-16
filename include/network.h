#ifndef NETWORK_H
#define NETWORK_H

#include <QDialog>

namespace Ui {
class Network;
}

class Network : public QDialog
{
    Q_OBJECT

public:
    explicit Network(QWidget *parent = nullptr);
    ~Network();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Network *ui;
};

#endif // NETWORK_H
