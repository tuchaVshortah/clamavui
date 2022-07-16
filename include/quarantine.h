#ifndef QUARANTINE_H
#define QUARANTINE_H

#include <QDialog>

namespace Ui {
class Quarantine;
}

class Quarantine : public QDialog
{
    Q_OBJECT

public:
    explicit Quarantine(QWidget *parent = nullptr);
    ~Quarantine();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Quarantine *ui;
};

#endif // QUARANTINE_H
