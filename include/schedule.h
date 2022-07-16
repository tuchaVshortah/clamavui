#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QDialog>

namespace Ui {
class Schedule;
}

class Schedule : public QDialog
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = nullptr);
    ~Schedule();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Schedule *ui;
};

#endif // SCHEDULE_H
