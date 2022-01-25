#include <stdio.h>
#include <math.h>

void EXPLICA_PROGRAMA(){
  printf("RAMIRO PEREIRA DA SILVA NETO\n");
  printf("04933716307-F3\n");
  printf("Depois de muita luta e internet caindo, consegui fazer o código que desenvolve a diferença de duas sequencias dadas pelas entradas, com auxilio de funções, para poder enxugar um pouco o código. ");
  
}

int CALCULA_TERMO(int prim, int sec){
  int novoTermo = prim + sec;

  return novoTermo;
}

int CALCULA_DIFERENCA(int prim, int sec){
  int diferenca = abs(prim - sec);
  
  return diferenca;
}

void IMPRIME_RESULTADOS(int cont,int UK,int TK,int somaU,int somaT,int SomaAcumulada){
  printf("------------------------------\n");
  printf("UNIDADE - %d\n",cont);
  printf("termo U%d = %d || termo T%d = %d\n",cont,UK,cont,TK);
  printf("Distancia entre U e T da unidade = %d\n",CALCULA_DIFERENCA(UK,TK));
  printf("Distancia acumulada de U e T: %d %d\n",(somaU ),(somaT));
  printf("Diferenca da distancia acumulada %d\n",(SomaAcumulada + CALCULA_DIFERENCA(somaU, somaT)));

}


int main(){
  int vaU0, vaT0,vaU1, vaT1, disMax;
  int dis0, dis1;

  int erro = 0;

  EXPLICA_PROGRAMA();
 
  do{
    printf("\nDigite dois valores positivos diferentes e separados por um espaco (Lembre-se o primeiro numero tem que ser maior q o segundo) U:");
    scanf("%d %d", &vaU0, &vaU1 );
    erro = 0;

  if (vaU0 > vaU1 || vaU0 < 0 || vaU1 < 0 || vaU0 == vaU1){
    printf("\nDados errado,insira novamente.\n");
    erro++;
    }
  }while (erro > 0);

  do{
    printf("\nDigite dois valores positivos diferentes e separados por um espaco (Lembre-se o primeiro numero tem que ser maior q o segundo) T:");
    scanf("%d %d", &vaT0, &vaT1 );
    erro = 0;

    if (vaT0 > vaT1 || vaT0 < 0 || vaT1 < 0 || vaT0 == vaT1){
      printf("\nDados errados,insira novamente.\n");
      erro++;
      }
  }while (erro > 0);

  do{
  printf("\nDigite a distancia maxima(ate 300.000):");
    scanf("%d", &disMax);
    erro = 0;
    if (disMax > 300000 || disMax <0){
      erro++;
      printf("\nDistancia errada errada,insira novamente.\n");
    }   
    }while (erro > 0);


    int somaAcumuladaU = 0,somaAcumuladaT = 0, disSomaAcumulada = 0;
    int somaU = 0,somaT = 0;
    
    int cont = 0;

   do{

      if (cont == 0){
        somaU = vaU0;
        somaT = vaT0;
        somaAcumuladaU = vaU0;
        somaAcumuladaT = vaT0;
        IMPRIME_RESULTADOS(cont,vaU0,vaT0,somaU,somaT,0);
        disSomaAcumulada = disSomaAcumulada + CALCULA_DIFERENCA(somaU,somaT);

      }else if (cont == 1){
        
        somaU = somaU + vaU1;
        somaT = somaT + vaT1;
        somaAcumuladaU = somaAcumuladaU + vaU1;
        somaAcumuladaT = somaAcumuladaT + vaT1;
        IMPRIME_RESULTADOS(cont,vaU1,vaT1,somaU,somaT,0);
        disSomaAcumulada = disSomaAcumulada + abs(somaU - somaT);
        
        
        
      }else{
          IMPRIME_RESULTADOS(cont,somaU,somaT,somaAcumuladaU,somaAcumuladaT,disSomaAcumulada);

          somaAcumuladaU = somaAcumuladaU + vaU1;
          somaAcumuladaT = somaAcumuladaT + vaT1;
          
          somaU = CALCULA_TERMO(somaU,vaU1);
          somaT = CALCULA_TERMO(somaT,vaT1);
          
          vaU1 = somaU - vaU1;
          vaT1 = somaT - vaT1;
          
      } 

      printf("Distancia acumulada: %d\n", disSomaAcumulada);
      
      cont++;
      
    }while( disMax > disSomaAcumulada);

    return 0 ;
}

  