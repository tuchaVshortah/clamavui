#ifndef UPDATEASSISTANT_H
#define UPDATEASSISTANT_H

#include <QDialog>

namespace Ui {
class UpdateAssistant;
}

class UpdateAssistant : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateAssistant(QWidget *parent = nullptr);
    ~UpdateAssistant();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::UpdateAssistant *ui;
};

#endif // UPDATEASSISTANT_H
