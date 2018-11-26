#include "../header.h"

//Função para somar ou subtrair duas matrizes
//Entrada: duas structs Mat; um numero inteiro
//Saida: uma struct Mat
Mat soma_sub(Mat x, Mat y, int tipo){
  //Verificando se as duas matrizes possuem dimensões iguais
  if (x.w == y.w && x.h == y.h){
    //Criação de uma struct Mat, que será utilizada na saida
    Mat mr;
    int i, j;
    //Atribuindo as dimensões da nova matriz mr
    //Comprimento da matriz mr = comprimento da matriz x
    //Altura da matriz mr = altura da matriz x
    mr.w = x.w;
    mr.h = x.h;
    //Aloca a matriz mr usando as dimensões definidas anteriormente
    aloca_matriz(&mr);
    //Percorrendo a matriz x
    For(i,x.w){
      For(j,x.h){
        //Verificação do inteiro tipo definido na entrada da função
        //Caso tipo seja igual a 0, as matrizes são somadas, caso contrário, as matrizes são subtraídas
        if (tipo == 0){
          mr.m[i][j] = x.m[i][j] + y.m[i][j];
        } else {
          mr.m[i][j] = x.m[i][j] - y.m[i][j];
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
