#include "arcfacefeaturedb.h"

ARCFaceFeatureDB::ARCFaceFeatureDB()
{

}

int ARCFaceFeatureDB::add(const AFR_FSDK_FACEMODEL &model, const UserInformation &info)
{
    LPAFR_FSDK_FACEMODEL pFacemodel = (LPAFR_FSDK_FACEMODEL) malloc(sizeof(AFR_FSDK_FACEMODEL));
    pFacemodel->lFeatureSize = model.lFeatureSize;
    pFacemodel->pbFeature = (MByte*) malloc(model.lFeatureSize);
    memcpy(pFacemodel->pbFeature , model.pbFeature , model.lFeatureSize);
    db.push_back(pFacemodel);
    return 0;
}

const vector<LPAFR_FSDK_FACEMODEL>* ARCFaceFeatureDB::getDB()
{
    return &(this->db);
}
