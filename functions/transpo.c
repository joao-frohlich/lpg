#include "../header.h"

Mat transpo(Mat x){
  Mat mr;
  int i, j;
  mr.w = x.h;
  mr.h = x.w;
  aloca_matriz(&mr);
  For(i,mr.w){
    For(j,mr.h){
      mr.m[i][j] = x.m[j][i];
    }
  }
  return mr;
}
