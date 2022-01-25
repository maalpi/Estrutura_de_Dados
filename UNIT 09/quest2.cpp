#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void troca(char *a, char *b) {
  char *t;
  strcpy(t,a);
  strcpy(a, b);
  strcpy(b,t);
}

void bubbleSort(char l[][MAX], int tam){
  for (int i = 0 ; i < tam ; i++){
    for (int j = 0 ; j < tam - 1 - i; j++){
      if (strcmp(l[j],l[j+1])>0){
      troca(l[j],l[j+1]);
      }
}
  }
}

int main(void) {
  int tam = 5;
  char strings[5][MAX] = {"ZBC","dEF","XHI","JKL","MNO"};

  bubbleSort(strings, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%s ",strings[i]);
  return 0;
}

