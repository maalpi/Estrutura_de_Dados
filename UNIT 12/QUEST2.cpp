#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void insertionSort(char l[][MAX], int tam){
  for (int i = 1 ; i < tam ; i++) {
    char eleito[tam];
    strcpy(eleito,l[i]);
    int j = i - 1;  
    
    while (j >= 0 && strcmp(l[j],eleito)> 0) {
      
      strcpy(l[j+1],l[j]);
      j = j - 1;
    }
    strcpy(l[j+1],eleito);

  }
}

int buscaBin(char l[][MAX], int tam, char* dado) {
  int ini = 0, fim = tam -1;
  int meio = (ini + fim) / 2;

  while (ini <= fim) {
    if (strcmp (l[meio], dado) == 0)
      return meio;
    else {
      if (strcmp (dado , l[meio]) < 0)
        fim = meio - 1;
      else
        ini = meio + 1;
        meio = (ini + fim) / 2;
    }
  }
  return -1;
}

int main(void) {
  int tam = 5;
  char l[5][MAX] = {"Z","d","X","J","M"};


  insertionSort(l, tam);

  printf("Achei Z em %d \n",buscaBin(l, tam, "Z"));
  printf("Achei d em %d \n",buscaBin(l, tam, "d"));

  for (int i = 0 ; i < tam ; i++)
    printf("%s ",l[i]);

  return 0;
}