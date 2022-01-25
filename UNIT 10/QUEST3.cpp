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

int main(void) {
  int tam = 5;
  char l[5][MAX] = {"ZBC","dEF","XHI","JKL","MNO"};

  insertionSort(l, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%s ",l[i]);
  return 0;
}