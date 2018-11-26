#include "../header.h"

//Função para gerar a matriz transposta de uma matriz x
//Entrada: uma struct Mat
//Saida: uma struct Mat
Mat transpo(Mat x){
  //Criação de uma struct Mat, que será utilizada na saida
  Mat mr;
  int i, j;
  //Atribuindo as dimensões da nova matriz mr
  //Comprimento da matriz mr = altura da matriz x
  //Altura da matriz mr = comprimento da matriz x
  mr.w = x.h;
  mr.h = x.w;
  //Aloca a matriz mr usando as dimensões definidas anteriormente
  aloca_matriz(&mr);
  //Percorrendo a matriz mr
  For(i,mr.w){
    For(j,mr.h){
      //Atribuindo aos elementos MRij o mesmo valor de Xji
      mr.m[i][j] = x.m[j][i];
    }
  }
  //Retorna mr
  return mr;
}
