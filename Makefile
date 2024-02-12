resultado: main.o invertir.o color.o escalar.o rotar.o reductor.o creacion.o F.o E.o P.o creacion_invertida.o voltear.o
	gcc -o resultado main.o invertir.o color.o escalar.o rotar.o reductor.o creacion.o F.o E.o P.o creacion_invertida.o voltear.o

main.o: main.c main.h
	gcc -c main.c

invertir.o: invertir.c main.h
	gcc -c invertir.c

color.o: color.c main.h
	gcc -c color.c

escalar.o: escalar.c main.h
	gcc -c escalar.c

rotar.o: rotar.c main.h
	gcc -c rotar.c

reductor.o: reductor.c main.h
	gcc -c reductor.c

creacion.o: creacion.c main.h
	gcc -c creacion.c

F.o: F.c main.h
	gcc -c F.c

E.o: E.c main.h
	gcc -c E.c

P.o: P.c main.h
	gcc -c P.c

creacion_invertida.o: creacion_invertida.c main.h
	gcc -c creacion_invertida.c

voltear.o: voltear.c main.h
	gcc -c voltear.c

atom: main.c main.h invertir.c color.c escalar.c rotar.c reductor.c creacion.c F.c E.c P.c creacion_invertida.c voltear.c Makefile
	atom main.c main.h invertir.c color.c escalar.c rotar.c reductor.c creacion.c F.c E.c P.c creacion_invertida.c voltear.c Makefile


valgrind:
		valgrind --leak-check=full ./resultado

clean:
		rm -f *.o  core resultado
