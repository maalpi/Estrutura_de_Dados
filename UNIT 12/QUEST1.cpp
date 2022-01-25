#include <stdio.h>
#include <stdlib.h>

int buscaBin(int l[], int tam, int num) {
  int ini = 0, fim = tam -1;
  int meio = (ini + fim) / 2;

  while (ini <= fim) {
    if (l[meio] == num)
      return meio;
    else {
      if (num > l[meio])
        fim = meio - 1;
      else
        ini = meio + 1;
      meio = (ini + fim) / 2;
    }
  }
  return -1;
}

int main(){
  int l[] = {11,9,7,5,3,1}, tam = 6;
  
  printf("Achei 1 em %d \n",buscaBin(l, tam, 1));
  printf("Achei 11 em %d \n",buscaBin(l, tam, 11));
  
  return 0;
}