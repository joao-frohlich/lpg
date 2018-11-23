#include "../header.h"

int iguais(Mat x, Mat y){
  if (x.w == y.w && x.h == y.h){
    int i, j;
    For(i,x.w){
      For(j,x.h){
        if (x.m[i][j] != y.m[i][j]){
          return 0;
        }
      }
    }
    return 1;
  } else {
    printf("Dimensões incompatíveis\n");
    return -1;
  }
}
