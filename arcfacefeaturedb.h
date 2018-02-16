#ifndef ARCFACEFEATUREDB_H
#define ARCFACEFEATUREDB_H

#include <bits/stdc++.h>
#include "inc/arcsoft_fsdk_face_recognition.h"
#include "userinformation.h"

using namespace std;

class ARCFaceFeatureDB
{
public:
    ARCFaceFeatureDB();
    int add(const AFR_FSDK_FACEMODEL & model ,const UserInformation & info);
    const vector<LPAFR_FSDK_FACEMODEL>* getDB();
private:
    vector<LPAFR_FSDK_FACEMODEL> db;
};

#endif // ARCFACEFEATUREDB_H
