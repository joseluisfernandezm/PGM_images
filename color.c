#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"
#define DIM 1000

int **cambio_de_color(int **matrizOri, int filas, int columnas, int maximo){
FILE *apertura;// puntero empleado para abrir el archivo donde se va a imprimir
char *linea;// donde se guardara que color queremos emplear
int k,l;//contadores aux para los bucles

printf("\n\n\n***Entrando en la funcion color***\n");
/*printf("--Comprobacion de la mariz recibida--\n");
for(k=0;k<filas;k++){
  for(l=0;l<columnas;l++){
    printf("%d ",matrizOri[k][l]);
  }
  printf("\n");
}//comprobacion de que la matriz color ha llegado color
*/

linea=(char*)malloc(sizeof(char));

printf("Selecciona rojo, azul o verde:\n");
scanf("%s", linea);

apertura=fopen("Imagen_Color.ppm","w");//apertura del archivo
if (apertura==NULL){
  printf("Error al abrir Imagen_Color\n");

}//comprobacion de apertura del archivo


if(strcmp(linea,"verde")==0){
  fprintf(apertura, "P3\n");
  fprintf(apertura, "%d %d\n", columnas, filas);
  fprintf(apertura, "%d\n",maximo);
  for(k=0;k<filas;k++){
    for(l=0;l<columnas;l++){
      fprintf(apertura,"0 %d 0  ",matrizOri[k][l]);
    }
    fprintf(apertura, "\n");
  }

}

 else if(strcmp(linea,"rojo")==0){
  fprintf(apertura, "P3\n");
  fprintf(apertura, "%d %d\n", columnas, filas);
  fprintf(apertura, "%d\n",maximo);
  for(k=0;k<filas;k++){
    for(l=0;l<columnas;l++){
      fprintf(apertura,"%d 0 0  ",matrizOri[k][l]);
    }
    fprintf(apertura, "\n");
  }
}
  else if(strcmp(linea,"azul")==0){
    fprintf(apertura, "P3\n");
    fprintf(apertura, "%d %d\n", columnas, filas);
    fprintf(apertura, "%d\n",maximo);
    for(k=0;k<filas;k++){
      for(l=0;l<columnas;l++){
        fprintf(apertura,"0 0 %d  ",matrizOri[k][l]);
      }
      fprintf(apertura, "\n");
    }
}
else {
    printf("El color no es RGB, elige uno válido, entre rojo, azul o verde\n");
    return NULL;

  }

printf("\n****Saliendo de la funcion Color****\n\n\n");
fclose(apertura);
return matrizOri;
}
