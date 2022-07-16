#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

class Worker: public QObject
{
    Q_OBJECT

public slots:
    void scanFile(QString filename);

signals:
    void resultReady();
};

#endif // WORKER_H
