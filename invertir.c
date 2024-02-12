#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"
#define DIM 1000

int **invertir(int **matrizOri, int filas, int columnas, int maximo){
int k,l;
printf("\n\n\n**Entrando en la funcion invertir**\n\n");
printf("\nComprobacion de llegada de argumentos:\n-Columnas:%d\n-Filas:%d\n-Color Maximo:%d\n ", columnas, filas, maximo );
printf("Matriz original:\n");
for(k=0;k<filas;k++){
  for(l=0;l<columnas;l++){
    printf("%d ",matrizOri[k][l]);
  }
  printf("\n");
}//comprobacion de que la matriz ha llegado correctamente

for(k=0;k<filas;k++){
  for(l=0;l<columnas;l++){
    matrizOri[k][l]= (maximo)-matrizOri[k][l]; //igual hay que restar a maximo 1 por aquello de empezar en el elemento 0
  }
}

printf("\n**Comprobacion de la matriz invertida:**\n");
for(k=0;k<filas;k++){
  for(l=0;l<columnas;l++){
    printf("%d ",matrizOri[k][l]);
  }
  printf("\n");
}//comprobacion de que la matriz se ha invertido

printf("\n\n **Saliendo de la funcion invertir -> Volviendo a main**\n\n");

return matrizOri;
}
