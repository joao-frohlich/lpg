#include <stdio.h>
#include <string.h>
#include "header.h"

int main(int argc, char *argv[]){
  if (argc < 3){
      printf("Erro!\n");
      return 0;
  }
  if (strcmp(argv[2],"transpo") == 0){
      if (argc < 4){
          printf("Parametros insuficientes\n");
          return 0;
      } else {
          FILE *f1, *fo;
          char path1[16];
          strcpy(path1,"io/");
          strcat(path1,argv[3]);
          f1 = fopen(path1,"r");
          if (f1 != NULL){
              Mat m1;
              inicia_matriz(&m1, f1);
              fo = fopen(argv[4],"w");
              escreve_matriz(transpo(m1), fo);
          }
          fclose(f1);
          fclose(fo);
      }
  } else if (strcmp(argv[2],"soma") == 0 || strcmp(argv[2], "sub") == 0){
    if (argc < 5){
        printf("Parametros insuficientes\n");
        return 0;
    } else {
        FILE *f1, *f2, *fo;
        char path1[16], path2[16];
        strcpy(path1,"io/");
        strcpy(path2,"io/");
        strcat(path1,argv[3]);
        strcat(path2,argv[4]);
        f1 = fopen(path1,"r");
        f2 = fopen(path2,"r");
        if (f1 != NULL && f2 != NULL){
            Mat m1, m2;
            inicia_matriz(&m1, f1);
            inicia_matriz(&m2, f2);
            fo = fopen(argv[5],"w");
            if (strcmp(argv[2],"soma") == 0){
                escreve_matriz(soma_sub(m1, m2, 0), fo);
            } else {
                escreve_matriz(soma_sub(m1, m2, 1), fo);
            }
        }
        fclose(f1);
        fclose(f2);
        fclose(fo);
    }
  } else if (strcmp(argv[2],"multi") == 0){
      if (argc < 5){
          printf("Parametros insuficientes\n");
          return 0;
      } else {
          FILE *f1, *f2, *fo;
          char path1[16], path2[16];
          strcpy(path1,"io/");
          strcpy(path2,"io/");
          strcat(path1,argv[3]);
          strcat(path2,argv[4]);
          f1 = fopen(path1,"r");
          f2 = fopen(path2,"r");
          if (f1 != NULL && f2 != NULL){
              Mat m1, m2;
              inicia_matriz(&m1, f1);
              inicia_matriz(&m2, f2);
              fo = fopen(argv[5],"w");
              escreve_matriz(multi(m1, m2), fo);
          }
          fclose(f1);
          fclose(f2);
          fclose(fo);
      }
  } else if (strcmp(argv[2],"multiesc") == 0){
      if (argc < 5){
          printf("Parametros insuficientes\n");
          return 0;
      } else {
          FILE *f1, *fo;
          char path1[16];
          strcpy(path1,"io/");
          strcat(path1,argv[3]);
          f1 = fopen(path1,"r");
          if (f1 != NULL){
              Mat m1;
              int esc;
              inicia_matriz(&m1, f1);
              sscanf(argv[4],"%d",&esc);
              fo = fopen(argv[5],"w");
              escreve_matriz(multiesc(m1, esc), fo);
          }
          fclose(f1);
          fclose(fo);
      }
  } else if (strcmp(argv[2],"iguais") == 0){
      if (argc < 4){
          printf("Parametros insuficientes\n");
          return 0;
      } else {
          FILE *f1, *f2;
          char path1[16], path2[16];
          strcpy(path1,"io/");
          strcpy(path2,"io/");
          strcat(path1,argv[3]);
          strcat(path2,argv[4]);
          f1 = fopen(path1,"r");
          f2 = fopen(path2,"r");
          if (f1 != NULL && f2 != NULL){
              Mat m1, m2;
              int v;
              inicia_matriz(&m1, f1);
              inicia_matriz(&m2, f2);
              v = iguais(m1,m2);
              if (v == 1)
                printf("Matrizes iguais\n");
              else if (v == 0)
                printf("Matrizes diferentes\n");
          }
          fclose(f1);
          fclose(f2);
      }
  } else if (strcmp(argv[2],"simetrica") == 0){
      if (argc < 3){
          printf("Parametros insuficientes\n");
          return 0;
      } else {
          FILE *f1;
          char path1[16];
          strcpy(path1,"io/");
          strcat(path1,argv[3]);
          f1 = fopen(path1,"r");
          if (f1 != NULL){
              Mat m1;
              int v;
              inicia_matriz(&m1, f1);
              v = simetrica(m1);
              if (v == 1)
                printf("Matriz simetrica\n");
              else if (v == 0)
                printf("Matriz nao simetrica\n");
          }
          fclose(f1);
      }
  }
}
