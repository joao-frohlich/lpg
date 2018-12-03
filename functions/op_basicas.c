#include <stdlib.h>
#include <string.h>
#include "../header.h"

//Função para ler dimensões
//Entrada: Um ponteiro da struct do tipo Mat; um ponteiro de arquivo
//Saida: Vazio, pois a função escreve diretamente na primeira variável de entrada
void le_dimensoes(Mat *x, FILE *fp){
  //Leitura das dimensões via arquivo
  fscanf(fp,"%d", &x->w);
  fscanf(fp,"%d", &x->h);
}

//Função para alocar matriz
//Entrada: Um ponteiro da struct do tipo Mat
//Saida: Vazio, pois a função escreve diretamente na variável de entrada
void aloca_matriz(Mat *x){
  //Aloca cada linha da matriz
  x->m = malloc(x->w*sizeof(float *));
  int i;
  //Percorre as linhas da matriz
  for (i = 0; i < x->w; i++){
    //Aloca cada elemento da linha que está sendo percorrida
    x->m[i] = malloc(x->h*sizeof(float));
  }
}

//Função para ler dimensões
//Entrada: Um ponteiro da struct do tipo Mat; um ponteiro de arquivo
//Saida: Vazio, pois a função escreve diretamente na primeira variável de entrada
void le_matriz(Mat *x, FILE *fp){
  int i, j;
  //Percorrendo cada posição da matriz
  For(i,x->w){
    For(j,x->h){
      //Leitura dos elementos da matriz através do arquivo
      fscanf(fp,"%f", &x->m[i][j]);
    }
  }
}

//Função para iniciar uma matriz
//Entrada: Um ponteiro da struct do tipo Mat; um ponteiro de arquivo
//Saida: Vazio, pois a função escreve diretamente na primeira variável de entrada
void inicia_matriz(Mat *x, FILE *fp){
  //Chama 3 funções para alocar e inserir valores nas matrizes
  le_dimensoes(x, fp);
  aloca_matriz(x);
  le_matriz(x, fp);
}

//Função para escrever uma matriz dentro do arquivo
//Entrada: Uma struct do tipo Mat; um ponteiro de arquivo
//Saida: Vazio, pois a função escreve diretamente na segunda variável de entrada
void escreve_matriz(Mat x, FILE *fp){
  int i, j;
  //Percorrendo cada elemento da matriz
  For(i,x.w){
    For(j,x.h){
      //Escreve o valor do elemento no arquivo
      fprintf(fp,"%.2f ", x.m[i][j]);
    }
    fprintf(fp,"\n");
  }
  fprintf(fp,"\n");
}

//Função para gerar uma matriz de erro para retorno
//Entrada: Um ponteiro da struct do tipo Mat
//Saida: Vazio, pois a função escreve diretamente na segunda variável de entrada
void gera_erro(Mat *x){
  //Atribui 1 para o numero de linhas e colunas
  x->w = 1;
  x->h = 1;
  //Aloca a matriz de erro
  aloca_matriz(x);
  //Atribui 0 ao unico elemento da matriz
  x->m[0][0] = 0;
}

//Função para desalocar a matriz
//Entrada: Um ponteiro da struct do tipo Mat
//Saida: Vazio, pois a função escreve diretamente na variável de entrada
void desaloca_mat(Mat *x){
  int i;
  //Percorre cada linha da matriz
  For(i,x->w){
    //Desaloca cada elemento da linha da matriz
    free(x->m[i]);
  }
  //Desaloca as linhas da matriz
  free(x->m);
}

//Função para definir o caminho padrão de um arquivo
//Entrada: Um ponteiro de char; um numero inteiro
//Saida: Um ponteiro de char
char *path(char *s, int l){
  //Cria um ponteiro de char, utilizado na saida
  char *r;
  //Aloca r dinamicamente
  //Tamanho definido pelo tamanho da string sendo utilizada com adição de 3 caracteres "io/"
  r = malloc(l+3);
  //Define o inicio do caminho do arquivo para a pasta "io"
  strcpy(r,"io/");
  //Copia ao final da string r o nome do arquivo passado pelo parametro s
  strcat(r,s);
  //Retorna r
  return r;
}
