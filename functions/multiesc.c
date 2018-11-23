#include "../header.h"

Mat multiesc(Mat x, int esc){
  Mat mr;
  int i, j;
  mr.w = x.w;
  mr.h = x.h;
  aloca_matriz(&mr);
  For(i,x.w){
    For(j,x.h){
      mr.m[i][j] = x.m[i][j] * esc;
    }
  }
  return mr;
}
