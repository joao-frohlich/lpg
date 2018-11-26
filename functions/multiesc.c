#include "../header.h"

//Função para multiplicar uma matriz x por um escalar esc
//Entrada: uma struct Mat; um numero inteiro
//Saida: uma struct Mat
Mat multiesc(Mat x, int esc){
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
      //Atribuindo ao elemento MRij a multiplicação do elemento Xij pelo escalar esc
      mr.m[i][j] = x.m[i][j] * esc;
    }
  }
  //Retorna mr
  return mr;
}
