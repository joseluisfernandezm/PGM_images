#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"
#define DIM 1000

void creacion(int max){
FILE *apertura;// puntero empleado para abrir el archivo donde se va a imprimir
int **imagen, **matriz_P, **matriz_E, **matriz_F;//matriz en la que guardaremos la imagen creada
int k,l, longitud;
char *nombre_archivo, *cadena_creacion;

printf("\n\n***Entrando en la funcion creacion***\n");

nombre_archivo= (char *)malloc(sizeof(char));
cadena_creacion = (char *)malloc(sizeof(char));

printf("Introduce las letras que quieres que salgan en tu imagen .pgm, solo puedes usar F, E y P\n");
scanf("%s", cadena_creacion);
longitud= strlen(cadena_creacion);

printf("Introduce el nombre que tendrá el archivo .pgm\n");
scanf("%s", nombre_archivo);


apertura=fopen(nombre_archivo,"w");//apertura del archivo
if (apertura==NULL){
  printf("Error al abrir creacion de imagen\n");
}

matriz_F = malloc(5 * sizeof(int *));
if(matriz_F == NULL){
  printf("Error al asignar la memoria");

}//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

for(k = 0; k < 5; k++){
  matriz_F[k] = malloc(4 * sizeof(int));
  if(matriz_F[k] == NULL){
    printf("Error al asignar la memoria\n");

  }
}//reserva dinamica de las 4 de la matriz


matriz_E = malloc((5) * sizeof(int *));
if(matriz_E == NULL){
  printf("Error al asignar la memoria");

}//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

for(k = 0; k < 5; k++){
  matriz_E[k] = malloc((4) * sizeof(int));
  if(matriz_E[k] == NULL){
    printf("Error al asignar la memoria\n");

  }
}//reserva dinamica de las 4 de la matriz

matriz_P = malloc((5) * sizeof(int *));
if(matriz_P == NULL){
  printf("Error al asignar la memoria");

}//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

for(k = 0; k < 5; k++){
  matriz_P[k] = malloc((4) * sizeof(int));
  if(matriz_P[k] == NULL){
    printf("Error al asignar la memoria\n");

  }
}//reserva dinamica de las 4 de la matriz

matriz_F=F(max);
matriz_E=E(max);
matriz_P=P(max);

imagen = malloc((5) * sizeof(int *));
if(imagen == NULL){
  printf("Error al asignar la memoria");

}//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

int anchura=(4*longitud);

for(k = 0; k < 5; k++){
  imagen[k] = malloc(anchura * sizeof(int));
  if(imagen[k] == NULL){
    printf("Error al asignar la memoria\n");

  }
}//reserva dinamica de las 4 de la matriz



fprintf(apertura, "P2\n");
fprintf(apertura, "%d 5\n", anchura);
fprintf(apertura, "%d\n",max);

int aux=0, x=0, y=0;


for (k=0;k<longitud; k++) {

    printf("%c\n", cadena_creacion[k] );
   printf("%d\n",aux);
  if(cadena_creacion[k]=='f' || cadena_creacion[k]=='F'){

    for (x = 0; x < 5; x++) {
        for (y = 0; y < 4; y++) {
    imagen[x][y+aux]=matriz_F[x][y];

    }
        }
  }
  else if(cadena_creacion[k]=='e' || cadena_creacion[k]=='E'){
    for (x = 0; x < 5; x++) {
        for (y = 0; y < 4; y++) {
    imagen[x][y+aux]=matriz_E[x][y];

    }
        }
  }
  else if(cadena_creacion[k]=='p' || cadena_creacion[k]=='P'){
    for (x = 0; x < 5; x++) {
        for (y = 0; y < 4; y++) {
    imagen[x][y+aux]=matriz_P[x][y];


    }
        }
  }
  aux+=4;
}



for(k=0;k<5;k++){
  for(l=0;l<anchura;l++){
    fprintf(apertura,"%d ",imagen[k][l]);
  }
    fprintf(apertura,"\n");
}

fclose(apertura);

}
