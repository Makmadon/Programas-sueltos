/*
 *   UCAB - Guayana
 *   Algoritmos y Programacion II
 *   Practica 05 - Actividad 02
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 25

int cant_prod = 0;

struct registro{
	int   codigo;
	char  descripcion[20];
	char  ubicacion[6];
	float costo_unitario;
	int   cantidad;
} inventario[MAX_PRODUCTOS];

void imprime_producto(int i){
	if(i<0 || i>= cant_prod){
		printf("Producto No encontrado");
		return;
	}
	printf("Codigo:     %4d\n",inventario[i].codigo);
	printf("Decripcion: %s\n",inventario[i].descripcion);
	printf("Ubicacion:  %s\n",inventario[i].ubicacion);
	printf("Costo/Unit: %.2f\n",inventario[i].costo_unitario);
	printf("Cantidad:   %d\n\n",inventario[i].cantidad);
}

void leer_productos(char *archivo){
	FILE *fp;
	int i;

	if((fp=fopen(archivo,"r"))==NULL){
		fprintf(stderr,"leer_productos: no se pudo abrir %s\n",archivo);
		exit(1);
	}
	fscanf(fp,"%d",&cant_prod);
	for(i=0;i<cant_prod;i++)
		fscanf(fp,"%d %s %s %f %d",&inventario[i].codigo,inventario[i].descripcion,
			inventario[i].ubicacion,&inventario[i].costo_unitario,&inventario[i].cantidad);
	fclose(fp);
}

void sort1(){ 
    int i,j; 

    for(i=0; i<MAX_PRODUCTOS-1; i++) 
		for(j=i+1; j<MAX_PRODUCTOS; j++) 
			if(inventario[i].codigo>inventario[j].codigo){ 
				struct registro t; // intercambiar 
				t=inventario[i]; 
				inventario[i]=inventario[j]; 
				inventario[j]=t; 
			} 
}

void sort2(){ 
    int e,i,j; 

    for(i=0; i<MAX_PRODUCTOS-1; i++){ 
		e=i; 
		for(j=i+1; j<MAX_PRODUCTOS; j++){
			if(inventario[e].codigo>inventario[j].codigo) 
				e=j; 
		}
			if(i!=e){ 
        		struct registro t; //
        		t=inventario[i]; 	//
        		inventario[i]=inventario[e]; //
        		inventario[e]=t; //
			} 
    } 
}

void sort3(){ 
    int i,j; 
	struct registro t;
	
    for(i=1;i<MAX_PRODUCTOS;i++){ 
		t=inventario[i]; 
		for(j=i; j>0 && t.codigo<inventario[j-1].codigo; j--) 
			inventario[j]=inventario[j-1]; 
		inventario[j]=t; 
    } 
}

void swap(int a,int b){ 
	struct registro t; 
	t=inventario[b]; 
	inventario[b]=inventario[a]; 
	inventario[a]=t; 
}

int particion(int inicio, int fin){ 
	int  inferior=inicio+1, superior=fin; 
	struct registro pivote;
	pivote=inventario[inicio]; 
	do{ 
		while(inventario[inferior].codigo>=pivote.codigo && inferior<=superior) 
			inferior++; 
		while(inventario[superior].codigo<pivote.codigo && inferior<=superior) 
			superior--; 
	if(inferior <= superior){ 
		swap(inferior,superior); 
		inferior++; 
		superior--; 
	} 
	}while(inferior<=superior); 
	swap(inicio,superior); 
	return superior; 
}

void quicksort(int inicio, int fin){ 
int p; 
	if(inicio<fin){ 
		p=particion(inicio,fin); 
		quicksort(inicio,p-1); 
		quicksort(p+1,fin); 
	} 
}

int buscar_por_codigo(int codigo){
	register int i;

	for(i=0;i<cant_prod;i++)
		if(inventario[i].codigo==codigo)
			return i;
	return -1;
}

int main(void) {
	int i;

	leer_productos("productos.dat");
	quicksort(0,MAX_PRODUCTOS);
	//sort1();
	for(i=0;i<cant_prod;i++)
		imprime_producto(i);
	printf("Codigo a buscar:");
	scanf("%d",&i);
	imprime_producto(buscar_por_codigo(i));
	return EXIT_SUCCESS;
}
