#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"
#define DIM 1000

void **reduccion(int **matrizOri, int filas, int columnas, int maximo, double escalar2){

  FILE *apertura;// puntero empleado para abrir el archivo donde se va a imprimir
  int **matrizReducida;//matriz en la que guardaremos la imagen escalada
  int k, l, i, j, m , n, aux;//contadores aux para los bucles
  int suma=0, media=0;
  int *media1;


media1=(int*)malloc(sizeof(int));

  printf("\n\n\n***Entrando en la funcion escalar2***\n");
  //printf("--Comprobacion de la mariz recibida--\n");
  /*for(k=0;k<filas;k++){
    for(l=0;l<columnas;l++){
      printf("%d ",matrizOri[k][l]);
    }
    printf("\n");
  }//comprobacion de que la matriz escalar2 ha llegado escalar2
*/


  apertura=fopen("Imagen_Reducida.pgm","w");//apertura del archivo
  if (apertura==NULL){
    printf("Error al abrir Imagen_Reducida\n");

  }//comprobacion de apertura del archivo





printf("Filas Original:%d\n",filas );
i= round(filas/escalar2);
printf("Filas Reducida:%d\n", i );
printf("Columnas Original:%d\n",columnas );
j=round(columnas/escalar2);
printf("Columnas Reducida:%d\n", j );



matrizReducida = malloc( i * sizeof(int *));
if(matrizReducida == NULL){
  printf("Error al asignar la memoria");
  return NULL;
}//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

for(k = 0; k < filas; k++){
  matrizReducida[k] = malloc(j * sizeof(int));
  if(matrizReducida[k] == NULL){
    printf("Error al asignar la memoria\n");
    return NULL;
  }
}//reserva dinamica de las columnas de la matriz


  fprintf(apertura, "P2\n");
  fprintf(apertura, "%d %d\n", j, i);
  fprintf(apertura, "%d\n",maximo);

  for (int x = 0; x < i; x++) {
      for (int y = 0; y < j/escalar2; y++) {
          suma = 0;
          for (k = 0; k < escalar2; k++) {
              for (l = 0; l < escalar2; l++) {
                  int cord1=round(x * escalar2 + k);
                  int cord2=round(y * escalar2* escalar2 + l);
                  suma += matrizOri[cord1][cord2];
              }
          media = suma / (escalar2 * escalar2);
          fprintf(apertura, "%d ", media);

      }
  }
        fprintf(apertura, "\n");
}

fclose(apertura);
printf("\nReducion en factor %2.lf relizado con éxito\n", escalar2);
printf("\n****Saliendo de la funcion reducir****\n\n\n");


}
