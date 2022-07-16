#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_checkBoxScanForPuas_stateChanged(int arg1);

    void on_checkBoxUseHeuristicScanning_stateChanged(int arg1);

    void on_checkBoxScanDotFiles_stateChanged(int arg1);

    void on_checkBoxScanBigFiles_stateChanged(int arg1);

    void on_checkBoxScanRecursively_stateChanged(int arg1);

    void on_checkBoxUpdates_stateChanged(int arg1);

    void on_autoUpdatesButton_clicked(bool checked);

    void on_manualUpdatesButton_clicked(bool checked);

    void on_noProxy_clicked();

    void on_systemProxy_clicked();

    void on_manualProxy_clicked();

private:
    Ui::Settings *ui;
    QSettings settings;
};

#endif // SETTINGS_H
