#ifndef ARCFACEENGINE_H
#define ARCFACEENGINE_H
#define WORKSIZE (40*1024*1024)
#include <bits/stdc++.h>
#include "inc/merror.h"
#include "inc/arcsoft_fsdk_face_detection.h"
#include "inc/arcsoft_fsdk_face_recognition.h"
#include "key.h"
#include "arcfacefeaturedb.h"
class ARCFaceEngine
{
public:
    ARCFaceEngine();
    int InitEngine();
    int UninitialEngine();
    int getFaceInputImg(unsigned char* data , int width , int height , MUInt32 format, ASVLOFFSCREEN & inputImg );
    int getFeature(unsigned char* data , int width , int height , MUInt32 format , LPAFR_FSDK_FACEMODEL localmodel);
    int addFeature(unsigned char* data , int width , int height ,MUInt32 format);
    int compareFeature(unsigned char* data , int width , int height ,MUInt32 format);
    int setDB(ARCFaceFeatureDB* _pdb);
private:
    MHandle FDEngine;
    MHandle FREngine;
    MByte *pFDWorkBUF;
    MByte *pFRWorkBUF;
    ARCFaceFeatureDB* pdb;
};

#endif // ARCFACEENGINE_H
