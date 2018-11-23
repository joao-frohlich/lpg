#include <stdio.h>
#include "../header.h"

Mat multi(Mat x, Mat y){
  if (x.h == y.w){
    Mat mr;
    int i, j, k;
    mr.w = x.w;
    mr.h = y.h;
    aloca_matriz(&mr);
    For(i,mr.w){
      For(j,mr.h){
        mr.m[i][j] = 0;
        For(k, x.h){
          mr.m[i][j] += x.m[i][k] * y.m[k][j];
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
