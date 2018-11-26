#include "../header.h"

//Verifica se uma dada matriz é simétrica
//Interpretação do retorno da variável fora da função
//Entrada: uma struct Mat
//Saida: um numero inteiro
int simetrica(Mat x){
  //Verificando se a matriz x é quadrada
  if (x.w == x.h){
    //Atribuindo a uma nova matriz y o mesmo valor da matriz transposta de x
    Mat y = transpo(x);
    //Retornando a verificação de igualdade entre a matriz x e a sua transposta y
    return iguais(x, y);
  } else {
    //Caso as dimensões sejam diferentes, a função e encerrada
    printf("Dimensões incompatíveis\n");
    return -1;
  }
}
