#include "test.h"

Test::Test()
{

}

void Test::gao()
{
    QString filename = "/home/huangyc/0/2.bmp";
    QImage img(filename);
    uchar* bits =  img.bits();
    int cnt = 100;
    while (cnt--) {
        fprintf(stderr , "%02x\n" , *bits);
        bits++;
    }
}
