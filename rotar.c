#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"
#define PI 3.141592
#define DIM 1000

void **rotar(int **matrizOri, int filas, int columnas, int maximo, int grados){
  FILE *apertura;// puntero empleado para abrir el archivo donde se va a imprimir
  int **matrizRotada, **escala, **matrizProducto;//matriz en la que se guardara la imagen rotada
  int matrizgrados[2][2];
  //int *escala_grises;
  int k,l,centro;//contadores aux para los bucles

//grados= atoi(grados*(3.1416 / 180));// SI QUITAS EL ATOY FUNCIONA

grados= grados*(3.1416/180);

printf("\n\n\n***Entrando en la funcion rotar***\n");


apertura=fopen("Imagen_Rotada.pgm","w");//apertura del archivo
if (apertura==NULL){
  printf("Error al abrir Imagen_Escalada\n");

}//comprobacion de apertura del archivo

matrizRotada = malloc(filas * sizeof(int *));
if(matrizRotada == NULL){
  printf("Error al asignar la memoria");
  return NULL;
}//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

for(k = 0; k < filas; k++){
  matrizRotada[k] = malloc(columnas* sizeof(int));
  if(matrizRotada[k] == NULL){
    printf("Error al asignar la memoria\n");
    return NULL;
  }
}//reserva dinamica de las columnas de la matrizRotada

int centro_x=filas/2;
int centro_y=columnas/2;
int k_nueva;
int l_nueva;

for(k=0;k<filas;k++){
  for(l=0;l<columnas;l++){
    k_nueva=round(cos(grados)*(k-centro_x)+sin(grados)*(l-centro_y)+centro_x);
    l_nueva=round(-sin(grados)*(k-centro_x)+cos(grados)*(l-centro_y)+centro_y);

    if(k_nueva>=0 && k_nueva<filas && l_nueva>=0 && l_nueva<columnas){
      matrizRotada[k][l]=matrizOri[k_nueva][l_nueva];
    }
    else
      matrizRotada[k][l]=0;
  }

}



printf("Impresion matriz rotada;\n");

for(k=0;k<2;k++){
  for(l=0;l<columnas;l++){
    printf("%d ",matrizRotada[k][l]);
  }
    printf("\n");
}

fprintf(apertura, "P2\n");
fprintf(apertura, "%d %d\n", columnas, filas);
fprintf(apertura, "%d\n",maximo);
for(k=0;k<filas;k++){
  for(l=0;l<columnas;l++){
    fprintf(apertura,"%d ",matrizRotada[k][l]);
  }
  fprintf(apertura, "\n");
}



fclose(apertura);
printf("\n****Saliendo de la funcion rotar****\n\n\n");


}
