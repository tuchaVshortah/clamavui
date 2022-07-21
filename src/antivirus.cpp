#include "antivirus.h"

unsigned int Antivirus::init(unsigned int options){
     unsigned int signo = 0, result = 0;
    if((result = cl_init(CL_INIT_DEFAULT)) != CL_SUCCESS){
        return result;
    }else if(!(engine = cl_engine_new())){
        return CL_ERROR;
    }else if((result = cl_load(cl_retdbdir(), engine, &signo, options)) != CL_SUCCESS){
         cl_engine_free(engine);
    }else if((result = cl_engine_compile(engine)) != CL_SUCCESS) {
         cl_engine_free(engine);
    }else if ((result = cl_engine_compile(engine)) != CL_SUCCESS) {
        cl_engine_free(engine);
    }
    return result;
}

Antivirus::Antivirus()
{
    QFuture<unsigned int> future = QtConcurrent::run(init, CL_INIT_DEFAULT);
    emit resultReady(future.result());
}

Antivirus::Antivirus(unsigned int options){
    QFuture<unsigned int> future = QtConcurrent::run(init, options);
    emit resultReady(future.result());
}

Antivirus::Antivirus(const Antivirus& clamav){
    engine = clamav.engine;
}

Antivirus::~Antivirus(){
    cl_engine_free(engine);
}

unsigned int Antivirus::updateSigs() {
    //Perform default updates
    fc_error_t result;
    fc_config config;

    result = fc_initialize(&config);

    return result;
}
