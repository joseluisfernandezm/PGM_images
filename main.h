#ifndef __MAIN_H__
#define __MAIN_H__

int **invertir(int **matrizOri, int filas, int columnas, int maximo);
int **cambio_de_color(int **matrizOri, int filas, int columnas, int maximo);
void **escalar(int **matrizOri, int filas, int columnas, int maximo, int multiplicador);
void **rotar(int **matrizOri, int filas, int columnas, int maximo, int grados);
void **reduccion(int **matrizOri, int filas, int columnas, int maximo, double escalar2);
void creacion(int max);
int **F(int maximo);
int **E(int maximo);
int **P(int maximo);
void creacion_inversa(int max);
void **voltear(int **matrizOri, int filas, int columnas, int maximo);





#endif
