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
    Antivirus(const Antivirus&);
    Antivirus(unsigned int options=CL_INIT_DEFAULT);
    ~Antivirus();
    ActionReply updatesigs();
private:
    cl_engine *engine = nullptr;
    fc_config config;
    fc_error_t update_result;
    unsigned int signo = 0, init_result = 0;
};

#endif // ANTIVIRUS_H
