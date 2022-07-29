#include "antivirus.h"

Antivirus::Antivirus(): Antivirus(CL_INIT_DEFAULT) {}

Antivirus::Antivirus(unsigned int options) {
    unsigned int signo = 0, result = 0;
    if((result = cl_init(CL_INIT_DEFAULT)) != CL_SUCCESS){
        emit resultReady(result);
    }else if(!(engine = cl_engine_new())){
        emit resultReady(CL_ERROR);
    }else if((result = cl_load(cl_retdbdir(), engine, &signo, options)) != CL_SUCCESS){
         cl_engine_free(engine);
    }else if((result = cl_engine_compile(engine)) != CL_SUCCESS) {
         cl_engine_free(engine);
    }else if ((result = cl_engine_compile(engine)) != CL_SUCCESS) {
        cl_engine_free(engine);
    }
    emit resultReady(result);
}

Antivirus::Antivirus(const Antivirus& clamav) {
    engine = clamav.engine;
}

Antivirus::~Antivirus() {
    cl_engine_free(engine);
}

ActionReply Antivirus::updatesigs() {
    //Perform default updates
    ActionReply reply;

    fc_error_t result = fc_initialize(&config);

    reply.addData("result", result);

    return reply;
}

KAUTH_HELPER_MAIN("org.tuchavshortah.clamavui.antivirus", Antivirus)
