#include <stdio.h>
#include <stdlib.h>
#include "../header.h"


void le_dimensoes(Mat *x, FILE *fp){
  fscanf(fp,"%d", &x->w);
  fscanf(fp,"%d", &x->h);
}

void aloca_matriz(Mat *x){
  x->m = malloc(x->w*sizeof(float *));
  int i;
  for (i = 0; i < x->w; i++){
    x->m[i] = malloc(x->h*sizeof(float));
  }
}

void le_matriz(Mat *x, FILE *fp){
  int i, j;
  for (i = 0; i < x->w; i++){
    for (j = 0; j < x->h; j++){
      fscanf(fp,"%f", &x->m[i][j]);
    }
  }
}

void inicia_matriz(Mat *x, FILE *fp){
  le_dimensoes(x, fp);
  aloca_matriz(x);
  le_matriz(x, fp);
}

void escreve_matriz(Mat x, FILE *fp){
  int i, j;
  for (i = 0; i < x.w; i++){
    for (j = 0; j < x.h; j++){
      fprintf(fp,"%.2f ", x.m[i][j]);
    }
    fprintf(fp,"\n");
  }
  fprintf(fp,"\n");
}

void gera_erro(Mat *x){
  x->w = 1;
  x->h = 1;
  aloca_matriz(x);
  x->m[0][0] = 0;
  x->w = -1;
  x->h = -1;
}
