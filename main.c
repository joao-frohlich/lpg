//Incluindo a biblioteca string, usada para comparação de strings e para saber o tamanho delas
#include <string.h>
//Incluindo biblioteca usada em todos os códigos do sistema, onde estão as chamadas de função, a struct Mat e a chamada da biblioteca stdio
#include "header.h"

int main(int argc, char *argv[]){
  //Verificação de erro
  //A chamada do programa so pode ter entre 3 e 5 parametros
  //Se o erro acontecer, é escrito no console Erro e o programa é encerrado
  if (argc < 3 || argc > 5){
      printf("Erro!\n");
      return 0;
  }
  //Nos 5 IFs seguintes, é verificado qual o tipo de operação a ser realizado

  //strcmp(argv[1],"operação") == 0: Verifica diretamente qual a operação
  //transpo = transposta da matriz
  //multiesc = multiplicação por escalar
  //iguais = igualdade entre matrizes
  //simetrica = verifica se uma matriz é simetrica

  //argc == 5: Verifica a quantidade de parametros, onde 5 parametros podem ser usados em:
  //Multiplicação, soma e subtração de matrizes, que usam o mesmo padrão(dois arquivos de entrada, um arquivo de saida)
  //Multiplicação por escalar, que é definido anteriormente

  //Não será explicado a mesma operação em todos os IFs, assim, será explicado a abertura e fechamento de arquivos,
  //o uso do inteiro na "multiesc", e as comparações utilizadas em "iguais" e "simetrica" e as comparações feitas
  //onde o usa a comparação "argc == 5"
  if (strcmp(argv[1],"transpo") == 0){
      //Verificação da quantidade de argumentos para a operação
      //Usada em todas as operações, mudando apenas o numero de comparação (3,4 ou 5)
      if (argc < 4){
          printf("Parametros insuficientes\n");
      } else {
          //Criação de duas variáveis para manipulação de arquivos
          //f1 = arquivo de entrada
          //fo = arquivo de saida
          FILE *f1, *fo;
          //Abrindo o arquivo de entrada para leitura
          //Chama a função path passando como parametros o terceiro parametro do argv e o tamanho desse parametro
          f1 = fopen(path(argv[2], strlen(argv[2])),"r");
          //Verifica se o arquivo realmente foi aberto
          if (f1 != NULL){
              //Cria uma matriz para ser usada na operação
              Mat m1;
              //Insere os elementos na matriz criada com os valores contidos no arquivo
              inicia_matriz(&m1, f1);
              //Abrindo o arquivo de saida para escrita
              fo = fopen(path(argv[3], strlen(argv[3])),"w");
              //Escreve a matriz resultado da função transpo dentro do arquivo de saida
              escreve_matriz(transpo(m1), fo);
              //Desalocando a matriz utilizada
              desaloca_mat(&m1);
          }
          //Fechando os arquivos
          fclose(f1);
          fclose(fo);
      }
  }  else if (strcmp(argv[1],"multiesc") == 0){
      if (argc < 5){
          printf("Parametros insuficientes\n");
      } else {
          FILE *f1, *fo;
          f1 = fopen(path(argv[2], strlen(argv[2])),"r");
          if (f1 != NULL){
              Mat m1;
              //Cria um inteiro para ser utilizado na função
              int esc;
              inicia_matriz(&m1, f1);
              //Pega o valor do inteiro através do parametro 4 passado na chamada do programa
              sscanf(argv[3],"%d",&esc);
              fo = fopen(path(argv[4], strlen(argv[4])),"w");
              escreve_matriz(multiesc(m1, esc), fo);
              desaloca_mat(&m1);
          }
          fclose(f1);
          fclose(fo);
      }
  } else if (argc == 5){
      FILE *f1, *f2, *fo;
      f1 = fopen(path(argv[2], strlen(argv[2])),"r");
      f2 = fopen(path(argv[3], strlen(argv[3])),"r");
      if (f1 != NULL && f2 != NULL){
          Mat m1, m2;
          inicia_matriz(&m1, f1);
          inicia_matriz(&m2, f2);
          fo = fopen(path(argv[4], strlen(argv[4])),"w");
          //Verifica qual a operação a ser realizada
          //No caso da soma e subtração, a constante passada como terceiro parametro da função soma_sub
          //remete a operação que vai ser realizada dentro da função
          //Caso nenhuma comparação esteja correta, significa que o usuario informou a operação incorreta
          if (strcmp(argv[1],"soma") == 0) {
              escreve_matriz(soma_sub(m1, m2, 0), fo);
          } else if (strcmp(argv[1],"sub") == 0) {
              escreve_matriz(soma_sub(m1, m2, 1), fo);
          } else if (strcmp(argv[1],"multi") == 0) {
              escreve_matriz(multi(m1,m2),fo);
          } else {
            printf("Operação invalida\n");
          }
          desaloca_mat(&m1);
          desaloca_mat(&m2);
      }
      fclose(f1);
      fclose(f2);
      fclose(fo);
  } else if (strcmp(argv[1],"iguais") == 0){
      if (argc < 4){
          printf("Parametros insuficientes\n");
      } else {
          FILE *f1, *f2;
          f1 = fopen(path(argv[2], strlen(argv[2])),"r");
          f2 = fopen(path(argv[3], strlen(argv[3])),"r");
          if (f1 != NULL && f2 != NULL){
              Mat m1, m2;
              //Cria um inteiro que vai ser utilizado como saida da função iguais
              int v;
              inicia_matriz(&m1, f1);
              inicia_matriz(&m2, f2);
              v = iguais(m1,m2);
              //Verificação do valor
              //Utilização de else if no lugar de apenas else devido à possibilidade de erro, que gera
              //retorno "-1"
              if (v == 1)
                printf("Matrizes iguais\n");
              else if (v == 0)
                printf("Matrizes diferentes\n");
              desaloca_mat(&m1);
              desaloca_mat(&m2);
          }
          fclose(f1);
          fclose(f2);
      }
  } else if (strcmp(argv[1],"simetrica") == 0){
      if (argc < 3){
          printf("Parametros insuficientes\n");
      } else {
          FILE *f1;
          f1 = fopen(path(argv[2], strlen(argv[2])),"r");
          if (f1 != NULL){
              Mat m1;
              int v;
              inicia_matriz(&m1, f1);
              v = simetrica(m1);
              if (v == 1)
                printf("Matriz simetrica\n");
              else if (v == 0)
                printf("Matriz nao simetrica\n");
              desaloca_mat(&m1);
          }
          fclose(f1);
      }
  }
  return 0;
}
