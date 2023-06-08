/*
 *   UCAB - Guayana
 *   Algoritmos y Programaci�n II
 *   Practica 05 - Actividad 03
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REG 25
#define N_INDICES 4

struct info_persona{
	int  carnet;
	char apellido[16];
	char nombre[16];
	int  ingreso;
} registros[MAX_REG];

int indice[N_INDICES][MAX_REG];

int n_reg=0;

// Imprime el encabezado para los registros

void imprime_titulo(void){
	printf("Carnet  Apellido        Nombre          Ingreso\n");
	printf("-----------------------------------------------\n");
}

// Imprime el registro de la posicion i

void imprime_registro(int reg){
	if(reg<0 || reg >= n_reg){
		fprintf(stderr,"Registro no encontrado\n");
		return;
	}
	printf("%7d %-15s %-15s %4d\n",
		registros[reg].carnet,registros[reg].apellido,
		registros[reg].nombre,registros[reg].ingreso);
}

// Lee los registros de un archivo

void leer_registros(char *nombre){
	FILE *fp;

	if((fp=fopen(nombre,"r"))==NULL){
		fprintf(stderr,"leer_registros: No se puede abrir %s\n",nombre);
		return;
	}
	while(fscanf(fp,"%d %s %s %d",&registros[n_reg].carnet,registros[n_reg].apellido,
         registros[n_reg].nombre,&registros[n_reg].ingreso)!=EOF)
		n_reg++;
	fclose(fp);
}

// Funciones que compara los elementos de regitros por un campo
// referenciados por i y j en el indice k

int cmp_carnet(int k,int i,int j){
	return registros[indice[k][i]].carnet<registros[indice[k][j]].carnet;
}

int cmp_apellido(int k,int i,int j){
	return strcmp(registros[indice[k][i]].apellido,registros[indice[k][j]].apellido)<0;
}

int cmp_nombre(int k,int i,int j){
	return strcmp(registros[indice[k][i]].nombre,registros[indice[k][j]].nombre)<0;
}

int cmp_AN(int k,int i, int j){
	return strcmp(registros[indice[k][i]].apellido,registros[indice[k][j]].apellido)==0?  //verifica que los apellidos sean distintos, 
	cmp_nombre(k,i,j):cmp_apellido(k,i,j);  	//si son distintos solo comparara los apellidos, si son iguales, comparara los nombres
}
// Construye el indice K usando la funcion de comparacion cmp


void construye_indice(int k, int (*cmp)(int,int,int)){
    int i,j;
	 for(i=0;i<n_reg;i++)                     // inicializa el indice
		indice[k][i]=i;
    for(i=1;i<n_reg;i++){
    	for(j=i; j>0 && (*cmp)(k,j,j-1); j--){ //  array[j]<array[j-1]
    	   int t=indice[k][j];                 // Intercambiar

			indice[k][j]=indice[k][j-1];
			indice[k][j-1]=t;
		}
    }
}

int main(void) {
	
	int i,opcion;
	int (*funciones_cmp[])(int,int,int)={cmp_carnet,cmp_apellido,cmp_nombre,cmp_AN};

	leer_registros("personas.dat");
	imprime_titulo();
	for(i=0;i<n_reg;i++)
		imprime_registro(i);
	for(i=0;i<N_INDICES;i++)
		construye_indice(i,funciones_cmp[i]);
	while(1){
		printf("\nImprimir ordenados por:");
		printf("\n\t1-Carnet 2-Apellidos 3-Nombres 4-Apellidos y Nombres\n\t0-Salir\n\nOpcion (0-3) => ");
		scanf("%d",&opcion);
		if(opcion==0)
			break;
		if(opcion>=1 && opcion <=N_INDICES){
			imprime_titulo();
			for(i=0;i<n_reg;i++)
				imprime_registro(indice[opcion-1][i]);
		}
		else
			printf("Error en opcion\n");
	}
	return EXIT_SUCCESS;
}
