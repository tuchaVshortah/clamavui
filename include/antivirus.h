#ifndef ANTIVIRUS_H
#define ANTIVIRUS_H

#include <QObject>
#include <QThread>
#include <QtConcurrent>
#include <KAuth/ActionReply>
#include <KAuth/HelperSupport>
#include "clamav.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "libfreshclam.h"

#ifdef __cplusplus
}
#endif

using namespace KAuth;

class Antivirus: public QObject
{
    Q_OBJECT

public:
    Antivirus();
    Antivirus(const Antivirus&);
    Antivirus(unsigned int options);
    ~Antivirus();
    static ActionReply updateSigs();
signals:
    void resultReady(unsigned int value);
private:
    static unsigned int init(unsigned int options);
    static cl_engine *engine;

};

#endif // ANTIVIRUS_H
