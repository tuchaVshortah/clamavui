#ifndef SCANDIRECTORY_H
#define SCANDIRECTORY_H

#include <QDialog>

namespace Ui {
class ScanDirectory;
}

class ScanDirectory : public QDialog
{
    Q_OBJECT

public:
    explicit ScanDirectory(QWidget *parent = nullptr);
    ~ScanDirectory();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ScanDirectory *ui;
};

#endif // SCANDIRECTORY_H
