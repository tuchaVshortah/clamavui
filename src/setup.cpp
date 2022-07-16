#include "../include/setup.h"

int result = 0;
unsigned int signo = 0;

cl_engine* setupEngine(unsigned int options){
    cl_engine *engine = nullptr;
    if((result = cl_init(CL_INIT_DEFAULT)) != CL_SUCCESS) {
        printf("cl_init() error: %s\n", cl_strerror(result));
    }else if(!(engine = cl_engine_new())) {
        printf("Can't create new engine\n");
    }else if((result = cl_load(cl_retdbdir(), engine, &signo, options)) != CL_SUCCESS) {
        printf("cl_init() error: %s\n", cl_strerror(result));
        cl_engine_free(engine);
        return nullptr;
    }else if((result = cl_engine_compile(engine)) != CL_SUCCESS) {
        printf("cl_engine_compile() error: %s\n", cl_strerror(result));
        cl_engine_free(engine);
        return nullptr;
    }
    return engine;
}
