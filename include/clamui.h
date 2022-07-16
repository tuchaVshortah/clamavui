#ifndef CLAMUI_H
#define CLAMUI_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QObject>
#include <filesystem>
#include "clamav.h"
#include "settings.h"
#include "whitelist.h"
#include "schedule.h"
#include "history.h"
#include "quarantine.h"
#include "update.h"
#include "scan.h"
#include "analysis.h"
#include "setup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ClamUI; }
QT_END_NAMESPACE

class ClamUI : public QMainWindow
{
    Q_OBJECT

public:
    ClamUI(QWidget *parent = nullptr);
    ~ClamUI();

private slots:
    void on_settingsButton_clicked();

    void on_whitelistButton_clicked();

    void on_scheduleButton_clicked();

    void on_historyButton_clicked();

    void on_quarantineButton_clicked();

    void on_updateButton_clicked();

    void on_analysisButton_clicked();

    void on_scanFileButton_clicked();

    void on_scanDirectoryButton_clicked();

    void on_scanSystemButton_clicked();

private:
    Ui::ClamUI *ui = nullptr;
    cl_engine *engine = nullptr;
    QString home = getenv("HOME");
};
#endif // CLAMUI_H
