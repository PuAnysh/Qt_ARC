#include "arcfaceengine.h"

ARCFaceEngine::ARCFaceEngine()
{
    FREngine = nullptr;
    FDEngine = nullptr;
    pFDWorkBUF = nullptr;
    pFRWorkBUF = nullptr;
}

int ARCFaceEngine::InitEngine()
{
    /*
     * check  engines before create
    */
    if(FREngine != nullptr || FDEngine != nullptr ||
            pFDWorkBUF != nullptr || pFRWorkBUF != nullptr){
        fprintf(stderr , "the engine may be running");
        return -1;
    }
    /*
     * initilize the FD engine
    */
    pFDWorkBUF = (MByte*)malloc(WORKSIZE);
    if(pFDWorkBUF == nullptr) {
        fprintf(stderr , "fail to malloc FDWorkbuf\r\n");
        return -1;
    }
    int ret_FD = AFD_FSDK_InitialFaceEngine(APPID , FD_SDKKEY , pFDWorkBUF , WORKSIZE , &FDEngine , AFD_FSDK_OPF_0_HIGHER_EXT , 16 , 1);
    if(ret_FD != MOK) {
        fprintf(stderr , "fail to AFD_FSDK_InitialFaceEngine(): 0x%x\r\n" , ret_FD);
        free(pFDWorkBUF);
        return -1;
    }
    /*
     * initilize the FR engine
    */
    pFRWorkBUF  = (MByte*)malloc(WORKSIZE);
    if(pFRWorkBUF == nullptr){
        fprintf(stderr , "fail to malloc FRWorkbuf");
        return -1;
    }
    int ret_FR = AFR_FSDK_InitialEngine(APPID , FR_SDKKEY , pFRWorkBUF , WORKSIZE , &FREngine);
    if(ret_FR != MOK){
        fprintf(stderr , "fail to AFD_FSDK_InitialEngine(): 0x%x\r\n" , ret_FR);
        free(pFRWorkBUF);
        return -1;
    }
    return 0;
}

int ARCFaceEngine::UninitialEngine()
{
    /*
     * unintall the FD engine
    */
    int FDret = AFD_FSDK_UninitialFaceEngine(FDEngine);
    if(FDret == MOK){
        free(pFDWorkBUF);
        pFDWorkBUF = nullptr;
        FDEngine = nullptr;
    }
    else{
        fprintf(stderr , "fail to AFD_FSDK_UninitialFaceEngine(): 0x%x\r\n" , FDret);
    }

    /*
     * unintall the FR engine
    */
    int FRret = AFR_FSDK_UninitialEngine(FREngine);
    if(FRret == MOK){
        free(pFRWorkBUF);
        pFRWorkBUF = nullptr;
        FREngine = nullptr;
    }
    else{
        fprintf(stderr , "fail to AFD_FSDK_UninitialEngine() 0x%x\r\n" , FRret);
    }
    /*
     * return flag
    */
    if(FRret !=MOK || FDret != MOK){
        return -1;
    }
    else{
        return 0;
    }
}
