#include "../header.h"

Mat soma_sub(Mat x, Mat y, int tipo){
  if (x.w == y.w && x.h == y.h){
    Mat mr;
    int i, j;
    mr.w = x.w;
    mr.h = x.h;
    aloca_matriz(&mr);
    For(i,x.w){
      For(j,x.h){
        if (tipo == 0){
          mr.m[i][j] = x.m[i][j] + y.m[i][j];
        } else {
          mr.m[i][j] = x.m[i][j] - y.m[i][j];
        }
      }
    }
    return mr;
  } else {
    Mat err;
    gera_erro(&err);
    printf("Dimensões incompatíveis\n");
  }
}
