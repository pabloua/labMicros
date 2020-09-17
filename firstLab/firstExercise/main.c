/* Laboratorio de Microprocesadores y Ensamblador

///////////////////////		Primer problema		/////////////////////// 

Autores:

- Katerine Lotero. 

- Pablo A. Uribe.

- Wilson D. Machado.

Profesor: Fabio Rivadeneira.

Ingeniería Electrónica.

Universidad del Valle. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "funcs.h"
#include "funcs.c"


int main(int argc, char* argv[]) {
	
	int i,n;
	int cols = 2; // Como son parejas, la matriz donde se almacenarán tendrán 2 columnas y n filas (n parejas). TUve que volver a cols una variable para poder trabajar con punteros.

	double** pairs; // Matrix de n x 2 para almacenar las parejas

	printf("Introduzca el número de parejas que desea ingresar: ");
	scanf("%d", &n);

	pairs = (double**)malloc(n*sizeof(double*)); // Le añado la cantidad de filas a la matriz.

	// En la línea anterior me faltó un asterisco 'sizeof(double *)', ya que lo que se busca crear es un puntero de punteros.
		
	for(i = 0; i < n; i = i+1){ // Le añado la cantidad de columnas la matriz

		pairs[i] = 	(double*)malloc(cols*sizeof(double)); 					
	}

	printf("Introduzca las parejas, con cada valor separado por espacio (e.j: x y): \n");

	for(i = 0; i < n; i = i+1){				// Introduzco los valores de la matriz

		scanf("%lf", &pairs[i][0]);		
		scanf("%lf", &pairs[i][1]); 

		printf("\n");		
	}	

	printf("La matriz introducida es: \n"); 
	
	for(i = 0; i < n; i = i+1){				// Imprimo la matriz de las parejas para saber cómo quedaron
		
		printf("%.2f ", pairs[i][0]);
		printf("%.2f \n", pairs[i][1]); 					
	}

	printf("\n");

	// Aquí se ha implementado el llamado a la función sum, la cual recibe un arreglo y su longitud
	// para sumar los elementos que contiene dicho arreglo. A manera de prueba, solo se suman
	// los elementos de la primera fila. Sin embargo, esto podría hacerse en general con cualquier arreglo.

	printf("La suma de los elementos de la primera fila (sin usar apuntadores) es: %.2f \n", sum(pairs[0], cols));
	
	// Aquí se ha implementado el llamado a la función sumWithPointer, la cual recibe un arreglo y su longitud
	// haciendo uso de punteros para sumar los elementos que contiene dicho arreglo. A manera de prueba, solo se suman
	// los elementos de la primera fila. Sin embargo, esto podría hacerse en general con cualquier arreglo.

	// NOTA: '&variable' significa que apunto a la dirección de memoria de la variable.

	printf("La suma de los elementos de la segunda fila (usando apuntadores) es: %.2f \n", sumWithPointer(&pairs[0][0], &cols));

	printf("\n");

	system("pause");    
	
	return 0;
}
 