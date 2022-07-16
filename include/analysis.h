#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QDialog>

namespace Ui {
class Analysis;
}

class Analysis : public QDialog
{
    Q_OBJECT

public:
    explicit Analysis(QWidget *parent = nullptr);
    ~Analysis();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Analysis *ui;
};

#endif // ANALYSIS_H
