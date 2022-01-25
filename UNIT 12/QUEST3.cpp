#include <stdio.h>
#include <stdlib.h>

int buscaBin(int l[], int ini,int fim, int num) {
  int meio = (ini + fim) / 2;

  while (ini <= fim) {
    if (l[meio] == num)
      return meio;
    else {
      if (num < l[meio])
        return buscaBin(l,ini,meio - 1,num);
      else
        return buscaBin(l,meio + 1,fim,num);
    }
  }
  return -1;
}

int main(){
  int l[] = {1,3,5,7,9,11}, tam = 6;
  
  printf("Achei 3 em %d \n",buscaBin(l, 0,tam-1, 3));
  printf("Achei 9 em %d \n",buscaBin(l, 0,tam-1, 9));
  
  return 0;
}