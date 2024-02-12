#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"
#define DIM 1000

void **escalar(int **matrizOri, int filas, int columnas, int maximo, int multiplicador){

  FILE *apertura;// puntero empleado para abrir el archivo donde se va a imprimir
  int **matrizAumentada;//matriz en la que guardaremos la imagen escalada
  int k,l,i,j;//contadores aux para los bucles

  printf("\n\n\n***Entrando en la funcion escalar***\n");
  /*printf("--Comprobacion de la mariz recibida--\n");
  for(k=0;k<filas;k++){
    for(l=0;l<columnas;l++){
      printf("%d ",matrizOri[k][l]);
    }
    printf("\n");
  }//comprobacion de que la matriz escalar ha llegado escalar
*/


  apertura=fopen("Imagen_Escalada.pgm","w");//apertura del archivo
  if (apertura==NULL){
    printf("Error al abrir Imagen_Escalada\n");

  }//comprobacion de apertura del archivo

matrizAumentada = malloc((filas*multiplicador) * sizeof(int *));
if(matrizAumentada == NULL){
  printf("Error al asignar la memoria");
  return NULL;
}//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

for(k = 0; k < filas; k++){
  matrizAumentada[k] = malloc((columnas*multiplicador) * sizeof(int));
  if(matrizAumentada[k] == NULL){
    printf("Error al asignar la memoria\n");
    return NULL;
  }
}//reserva dinamica de las columnas de la matriz

for(k=0;k<filas;k++){
  for(l=0;l<columnas;l++){
      matrizAumentada[k][l]=matrizOri[k][l];
  }

}

  fprintf(apertura, "P2\n");
  fprintf(apertura, "%d %d\n", (columnas*multiplicador), (filas*multiplicador));
  fprintf(apertura, "%d\n",maximo);
  for(k=0;k<filas;k++){
    for(j=0;j<multiplicador;j++){
      for(l=0;l<columnas;l++){
        for(i=0;i<multiplicador;i++){
            fprintf(apertura,"%d ",matrizAumentada[k][l]);
        }
      }
            fprintf(apertura, "\n");
    }
  }
fclose(apertura);
printf("\n****Saliendo de la funcion escalar****\n\n\n");


}
