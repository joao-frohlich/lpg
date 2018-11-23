#include <stdio.h>
#define For(x,y) for (x = 0; x < y; x++)

typedef struct{
  int w, h;
  float **m;
} Mat;

void le_dimensoes(Mat *x, FILE *fp);
void aloca_matriz(Mat *x);
void le_matriz(Mat *x, FILE *fp);
void escreve_matriz(Mat x, FILE *fp);
void inicia_matriz(Mat *x, FILE *fp);
void gera_erro(Mat *x);
Mat soma_sub(Mat x, Mat y, int tipo);
Mat transpo(Mat x);
Mat multi(Mat x, Mat y);
Mat multiesc(Mat x, int esc);
int iguais(Mat x, Mat y);
int simetrica(Mat x);
