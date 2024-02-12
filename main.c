#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"
#define DIM 1000

typedef enum{inversion=1, colorear, escalado, rotacion, reducir, combinar, combinar_i, volteado}Transformaciones;

int main(int argc, char const *argv[]) {

int i, k, l; //i=bucle for de ARGV y aux bucles j= aux bucles
int **matriz, **inversa, **color1, **escalada;
char *tipo; // cadena de caracteres que guarda las primeras palabras de la imagen
char fichero[DIM]; // Cadena de caracteres que guarda el nombre del fichero
int  w, h; //para la lectura de la matriz_entrada
int max; //max=tono maximo de color
FILE *pgm, *salida_inversa; //puntero de tipo file que se usa para abrir los archivos
int mode, multiplicador, grados;// para elegir el modo en switch, multiplicador= por cuanto se aumentara el tamaño de la foto, grados=elegir grados de rotacion
double escalar1;

/* Esto te mide los argumentos de la función main que otorga la terminal
Argc te indica el numero de argumentos pasados desde la terminal
Argv se relaciona con Argc ya que este es un array que te imprime el nombre del
argumento*/


if(argc!=2){
      printf("Reinicia el programa y introduce dos argumentos, el ejecutable y el nombre del archivo .pgm a leer \nDeja un espacio entre ambos\n");
      return -1;
    }//Prueba para introducir mas de un argumento*/

/*if(argc<1){
    printf("Argc, el numero de argumentos de entrada ha de ser mayor o igual a 1 \n");
}*/


  printf("*PRUEBA DE ARGC: \nSe ha ejecutado un programa con %d argumentos\n**FIN DE LA PRUEBA ARGC**\n", argc);
for (i=0; i < argc; i++) {
  printf ("*PRUEBA ARGV:\nArgumento %d: %s\n**FIN PRUEBA ARGV**\n\n", i, argv[i]); }

//**Lectura de la imagen .pgm

/*printf("**Lectura de la imagen**\nIntroduce el nombre de la imagen pgm que quieres leer:\n ");
 scanf("%s", fichero);*/

 tipo = (char *)malloc(sizeof(char)); //reserva de memoria de la cadena que guardara el fomato Px de la primera linea de la imagen

 pgm = fopen(argv[1], "r"); //usamos el puntero pgm para abrir el fichero que es la imagen pgm
 if(pgm == NULL){
   printf("Error al abrir el archivo %s\n", argv[1]);
   return 0;
 }  //comprobacion de la apertura del fichero .pgm

 printf("Se ha abierto el fichero %s de forma correcta\n", argv[1]);

 if(fscanf(pgm, "%s", tipo) == 0){
   printf("Error en la lectura del archivo\n");
   return -1;
 }// esta forma de scanf nos permite escanear y comprobar a la vez

printf("--lectura correcta de tipo--\n");

 if(fscanf(pgm, "%d", &w) == 0){
   printf("Error en la lectura del archivo\n");
   return -1;
 }

printf("--lectura correcta de columnas--\n");

 if(fscanf(pgm, "%d", &h) == 0){
   printf("Error en la lectura del archivo\n");
   return -1;
 }

printf("--lectura corrcta de filas--\n");

 if(fscanf(pgm, "%d", &max) == 0){
   printf("Error en la lectura del archivo\n");
   return -1;
 }

printf("--lectura correcta de tono maximo--\n");

 matriz = malloc(h * sizeof(int *));
 if(matriz == NULL){
   printf("Error al asignar la memoria");
   return -1;
 }//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

 for(k = 0; k < h; k++){
   matriz[k] = malloc(w * sizeof(int));
   if(matriz[k] == NULL){
     printf("Error al asignar la memoria\n");
     return -1;
   }
 }//reserva dinamica de las columnas de la matriz

 for(k = 0; k < h; k++){
   for(l = 0; l < w; l++){
     if(fscanf(pgm,"%d", &matriz[k][l]) == 0){
       printf("Error al asignar la memoria");
       return -1;
     }
   }
 } // escaneo de los elementos de la matriz

 printf("El archivo es de tipo: %s\n", tipo);
 printf("El archivo tiene las siguientes dimensiones: %d columnas por %d filas\n", w, h);
 printf("Como valor máximo en la escala de grises el archivo tiene: %d\n", max);
 printf("\nEl archivo %s se ha leido de forma correcta\n", fichero);

 /*for(k=0;k<h;k++){
   for(l=0;l<w;l++){
     printf("%d ",matriz[k][l]);
   }
   printf("\n");
 } // impresion de la matriz por pantalla, esto solo se hace para comprobar que lo halla leido bien
*/




printf("\nElige el numero de la opcion del programa que vas a usar:\n1.Invertir La Imagen.\n2.Colorear La Imagen.\n3.Aumentar la imagen.\n4.Rotacion.\n5.Reducir la imagen\n6.Combinar\n7.Combinar al reves\n8.Voltear\nSeleccion:");
  scanf("%d",&mode);

switch(mode){
  case inversion:
//**LLamada a la funcion invertir

inversa = malloc(h * sizeof(int *));
if(inversa == NULL){
  printf("Error al asignar la memoria");
  return -1;
}//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

for(k = 0; k < h; k++){
  inversa[k] = malloc(w * sizeof(int));
  if(inversa[k] == NULL){
    printf("Error al asignar la memoria\n");
    return -1;
  }
}//reserva dinamica de las columnas de la matriz


inversa=invertir(matriz,h,w,max);// llamada a la funcion que invierte la matrix de color
printf("\n Comprobacion de la llegada a main de la funcion inversa:\n");
for(k=0;k<h;k++){
  for(l=0;l<w;l++){
    printf("%d ",inversa[k][l]);
  }
  printf("\n");
}//comprobacion de que la matriz inversa ha llegado a main

salida_inversa=fopen("Imagen_Invertida.pgm","w");//apertura del archivo que contentra la imagen inversa
if(salida_inversa==NULL){
  printf("Error al abrir Imagen_Invertida\n");
  return -1;
} //comprobacion de la apertura del archivo

fprintf(salida_inversa, "%s\n", tipo);// estos fprintf escriben en el fichero linea a linea el tipo Px, las columnas, las filas y el tono maximo
fprintf(salida_inversa, "%d %d\n", w, h);
fprintf(salida_inversa, "%d\n",max);

for(k=0;k<h;k++){
  for(l=0;l<w;l++){
    fprintf(salida_inversa, "%d ",inversa[k][l] );
  }
  fprintf(salida_inversa, "\n");
} //bucle que escribe en el archivo de salida cada numero de la matriz inversa
break;

case colorear:
//****Cambio de color****

color1 = malloc(h * sizeof(int *));
if(color1 == NULL){
  printf("Error al asignar la memoria");
  return -1;
}//reserva del vector fila de la matriz, el siguiente for sera para la reserva dinamica a partir de el vector fila

for(k = 0; k < h; k++){
  color1[k] = malloc(w * sizeof(int));
  if(color1[k] == NULL){
    printf("Error al asignar la memoria\n");
    return -1;
  }
}//reserva dinamica de las columnas de la matriz
//inversa=invertir(matriz,h,w,max);
color1=cambio_de_color(matriz,h,w,max);

printf("\n***Matriz de imagen coloreada****\n");
for(k=0;k<h;k++){
  for(l=0;l<w;l++){
    printf("%d ",color1[k][l]);
  }
  printf("\n");
}//comprobacion de que la matriz color ha llegado a main

break;


//***Funcion escalar***
case escalado:
printf("\nIntroduce por cuanto quieres aumentar el tamaño de la imagen: x");
scanf("%d",&multiplicador);
escalar(matriz, h, w, max, multiplicador);

break;

case rotacion:

printf("Cuantos grados quieres girar la imagen:\n");
scanf("%d",&grados);
if(grados!=0)
  rotar(matriz, h, w, max, grados);
else
  return -1;



break;


case reducir:

printf("\nIntroduce por cuanto quieres reducir el tamaño de la imagen:");
scanf("%lf",&escalar1);
printf("%lf\n", escalar1);
reduccion(matriz, h, w, max, escalar1);
break;


case combinar:
creacion(max);
break;

case combinar_i:
creacion_inversa(max);
break;

case volteado:

voltear(matriz, h, w, max);



break;

}

 free(tipo);
 free(matriz);
 fclose(pgm);

 return 1;
}
