#ifndef CUDAVALIDATION_H
#define CUDAVALIDATION_H
#define checkCUDATErrors(val) check_cuda((val,#val,__FILE__,__LINE__))
#include "Validation.h"
void validationCUDAFunction(cudaError_t result,const  char* const funcName,const char* const file,int const line)
{
    result ? printf("CUDA error = %d at file %s line %i in function %s",(unsigned int)result,file,line,funcName) : void();
    result ? cudaDeviceReset() : void();
    assert(result==0)
}
#endif