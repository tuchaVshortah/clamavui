#ifndef INIT_H
#define INIT_H

#include <QObject>
#include <QThread>

class Init: public QObject
{
    Q_OBJECT

public slots:
    Init(); //add more constructors with different parameters

signals:
    void success();
    void error();
};

#endif // INIT_H
