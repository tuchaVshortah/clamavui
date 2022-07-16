#ifndef WHITELIST_H
#define WHITELIST_H

#include <QDialog>

namespace Ui {
class Whitelist;
}

class Whitelist : public QDialog
{
    Q_OBJECT

public:
    explicit Whitelist(QWidget *parent = nullptr);
    ~Whitelist();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Whitelist *ui;
};

#endif // WHITELIST_H
