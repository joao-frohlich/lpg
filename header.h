//Biblioteca usada em todos os arquivos
#include <stdio.h>
//Simplificação do for
#define For(x,y) for (x = 0; x < y; x++)

//Criação da struct
typedef struct{
  //Declarando dois inteiros: Numero de linhas(w) e Numero de colunas(h)
  int w, h;
  //Declarando uma matriz de float como ponteiro de ponteiro para alocação dinâmica
  float **m;
} Mat;

//Declaração de todas as funções utilizadas no código
//Explicação sobre o uso das funções dentros dos arquivos contendo as funções


//Arquivo op_basicas.c
void le_dimensoes(Mat *x, FILE *fp);
void aloca_matriz(Mat *x);
void le_matriz(Mat *x, FILE *fp);
void escreve_matriz(Mat x, FILE *fp);
void inicia_matriz(Mat *x, FILE *fp);
void gera_erro(Mat *x);
void desaloca_mat(Mat *x);
char *path(char *s, int l);

//Arquivo soma_sub.c
Mat soma_sub(Mat x, Mat y, int tipo);

//Arquivo transpo.c
Mat transpo(Mat x);

//Arquivo multi.c
Mat multi(Mat x, Mat y);

//Arquivo multiesc.c
Mat multiesc(Mat x, int esc);

//Arquivo iguais.c
int iguais(Mat x, Mat y);

//Arquivo simetrica.c
int simetrica(Mat x);
