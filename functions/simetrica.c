#include "../header.h"

int simetrica(Mat x){
  if (x.w == x.h){
    Mat y = transpo(x);
    return iguais(x, y);
  } else {
    printf("Dimensões incompatíveis\n");
    return -1;
  }
}
