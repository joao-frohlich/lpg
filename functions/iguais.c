#include "../header.h"

//Função de verificação de igualdade
//Interpretação do retorno da variável fora da função
//Entrada: duas structs do tipo Mat
//Saida: um numero inteiro
int iguais(Mat x, Mat y){
  //Verificando se as dimensões da matriz x é igual às dimensões da matriz y
  if (x.w == y.w && x.h == y.h){
    int i, j;
    //Percorrendo as duas matrizes simultaneamente
    For(i,x.w){
      For(j,x.h){
        //Verificando a existencia de valores diferentes na mesma posição
        if (x.m[i][j] != y.m[i][j]){
          //Caso algum elemento da matriz seja diferente, a função retorna 0 e é encerrada
          return 0;
        }
      }
    }
    //Caso a função ainda esteja executando, significa que não foram identificados
    //Elementos diferentes em uma mesma posição nas duas matrizes
    //Logo as matrizes são iguais e a função retorna 1
    return 1;
  } else {
    //Caso as dimensões sejam diferentes, a função e encerrada
    printf("Dimensões incompatíveis\n");
    return -1;
  }
}
