#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>
#include <QString>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <KAuth/Action>
#include <KAuth/ActionReply>
#include <KAuth/ExecuteJob>
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

    void on_updates();

private:
    Ui::Update *ui;
    QString logs = "/var/log/clamav/freshclam.log";

    void readLogs();
};

#endif // UPDATE_H
