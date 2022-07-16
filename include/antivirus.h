#ifndef ANTIVIRUS_H
#define ANTIVIRUS_H

#include <QObject>
#include <QThread>
#include <QtConcurrent>
#include <clamav.h>

class Antivirus: public QObject
{
    Q_OBJECT

public:
    Antivirus();
    Antivirus(const Antivirus&);
    Antivirus(unsigned int options);
    ~Antivirus();
signals:
    void resultReady(unsigned int value);
private:
    static unsigned int init(unsigned int options);
    static cl_engine *engine;

};

#endif // ANTIVIRUS_H
