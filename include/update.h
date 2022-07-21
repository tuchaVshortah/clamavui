#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>
#include <QMessageBox>
#include "antivirus.h"

namespace Ui {
class Update;
}

class Update : public QDialog
{
    Q_OBJECT

public:
    explicit Update(QWidget *parent = nullptr);
    ~Update();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_checkUpdates_clicked();

private:
    Ui::Update *ui;
};

#endif // UPDATE_H
