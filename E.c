#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"
#define DIM 1000

int **E(int maximo){
  int matrix[5][4]={{maximo, maximo, maximo, maximo},{maximo, 0, 0, 0},{maximo, maximo, maximo, 0},{maximo, 0, 0, 0},{maximo, maximo, maximo, maximo}};
  int **matriz_envio;
  int k, l;
  int filas=5, columnas=4;

  matriz_envio = malloc((filas) * sizeof(int *));
  if(matriz_envio == NULL){
    printf("Error al asignar la memoria");
    return NULL;
  }//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

  for(k = 0; k < filas; k++){
    matriz_envio[k] = malloc((columnas) * sizeof(int));
    if(matriz_envio[k] == NULL){
      printf("Error al asignar la memoria\n");
      return NULL;
    }
  }//reserva dinamica de las columnas de la matriz

  printf("Impresion de la matriz E\n");
  for(k=0;k<5;k++){
    for(l=0;l<4;l++){
      printf("%d ",matrix[k][l]);
    }
      printf("\n");
  }

  for(k=0;k<5;k++){
    for(l=0;l<4;l++){
    matriz_envio[k][l]=matrix[k][l];
    }
  }

  /*printf("Impresion de la matriz envio E\n");

  for(k=0;k<5;k++){
    for(l=0;l<4;l++){
      printf("%d ",matriz_envio[k][l]);
    }
      printf("\n");
  }
*/
return matriz_envio;



}
