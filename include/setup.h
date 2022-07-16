#ifndef SETUP_H
#define SETUP_H
#include <clamav.h>

extern int result;
extern unsigned int signo;

cl_engine* setupEngine(unsigned int options=CL_DB_STDOPT);
#endif // SETUP_H
