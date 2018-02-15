#ifndef ARCFACEENGINE_H
#define ARCFACEENGINE_H
#define WORKSIZE (40*1024*1024)
#include <bits/stdc++.h>
#include "inc/merror.h"
#include "inc/arcsoft_fsdk_face_detection.h"
#include "inc/arcsoft_fsdk_face_recognition.h"
#include "key.h"
class ARCFaceEngine
{
public:
    ARCFaceEngine();
    int InitEngine();
    int UninitialEngine();
private:
    MHandle FDEngine;
    MHandle FREngine;
    MByte *pFDWorkBUF;
    MByte *pFRWorkBUF;
};

#endif // ARCFACEENGINE_H
