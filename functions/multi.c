#include "../header.h"

//Função para multiplicar duas matrizes
//Entrada: duas structs Mat
//Saida: uma struct Mat
Mat multi(Mat x, Mat y){
  //Verificando dimensões da matriz
  //Numero de colunas de x deve ser igual ao numero de linhas de y
  if (x.h == y.w){
    //Criação de uma struct Mat, que será utilizada na saida
    Mat mr;
    int i, j, k;
    //Atribuindo as dimensões da nova matriz mr
    //Numero de linhas da matriz mr = Numero de linhas da matriz x
    //Numero de colunas da matriz mr = Numero de colunas da matriz y
    mr.w = x.w;
    mr.h = y.h;
    //Alocando a matriz mr usando as dimensões definidas anteriormente
    aloca_matriz(&mr);
    //Percorrendo a matriz mr
    For(i,mr.w){
      For(j,mr.h){
        //Atribuindo um valor fixo para poder utilizar o operador +=
        mr.m[i][j] = 0;
        //Percorrendo a linha i da matriz x e a coluna j da matriz y simultaneamente
        For(k, x.h){
          mr.m[i][j] += x.m[i][k] * y.m[k][j];
        }
      }
    }
    //Retornando a matriz mr
    return mr;
  } else {
    //Gera uma matriz de erro para retorno
    Mat err;
    gera_erro(&err);
    //Printa o erro
    printf("Dimensões incompatíveis\n");
    //Retorna a matriz gerada anteriormente
    return err;
  }
}
