#include "antivirus.h"

Antivirus::Antivirus(unsigned int options) {


    init_result = cl_init(CL_INIT_DEFAULT);

    if(!(init_result != CL_SUCCESS) && !(engine = cl_engine_new())){
        init_result = CL_ERROR;
    }else if((init_result = cl_load(cl_retdbdir(), engine, &signo, options)) != CL_SUCCESS){
        cl_engine_free(engine);
    }else if((init_result = cl_engine_compile(engine)) != CL_SUCCESS) {
        cl_engine_free(engine);
    }else if ((init_result = cl_engine_compile(engine)) != CL_SUCCESS) {
        cl_engine_free(engine);
    }
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

    if(init_result == CL_SUCCESS) {
        update_result = fc_initialize(&config);
    }

    reply.addData("init_result", init_result);
    reply.addData("update_result", update_result);

    return reply;
}

KAUTH_HELPER_MAIN("org.tuchavshortah.clamavui.antivirus", Antivirus)
