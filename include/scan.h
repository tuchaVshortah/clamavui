#ifndef SCAN_H
#define SCAN_H

#include <QDialog>

namespace Ui {
class ScanFile;
}

class ScanFile : public QDialog
{
    Q_OBJECT

public:
    explicit ScanFile(QWidget *parent = nullptr);
    ~ScanFile();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ScanFile *ui;
};

#endif // SCAN_H
