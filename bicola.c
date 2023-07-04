#include <stdio.h>
#define tamaño_bicola 10


typedef struct bicola{
	int primero,ultimo;
	int cola[tamaño_bicola];
	int cantidad;
}Bicola;


void CrearBicola(Bicola *cola){
	cola->primero=cola->cantidad=cola->ultimo=0;
	return ;
}

int BicolaVacia(Bicola cola){
	return cola.cantidad;
}

int PonerFrente(Bicola* cola,int elemento){
	if(cola->cantidad<tamaño_bicola-1){
		cola->cola[cola->primero--]=elemento;
		cola->cantidad++;
		return 1;
	}
	return 0;
}

int PonerFinal(Bicola *cola,int elemento){
	if(cola->cantidad<tamaño_bicola-1){
		cola->cola[cola->ultimo++]=elemento;
		cola->cantidad++;
		return 1;
	}
	return 0;
}

int QuitarFrente(Bicola* cola,int *elemento){
	if(cola->cantidad>0){
		*elemento=cola->cola[cola->primero++];
		cola->cantidad--;
		return 1;
	}
	return 0;
}

int QuitarFinal(Bicola *cola,int *elemento){
	if(cola->cantidad>0){
		*elemento=cola->cola[cola->ultimo--];
		cola->cantidad--;
		return 1;
	}
	return 0;
}

int Frente(Bicola cola, int *elemento){
	if(cola.cantidad>0){
		*elemento=cola.cola[cola.primero];
		return 1;
	}
	return 0;
}

int Final(Bicola cola,int *elemento){
	if(cola.cantidad>0){
		*elemento=cola.cola[cola.ultimo];
		return 1;
	}
	return 0;
}

int a[]={5,10,15,20,25,30,35};

Bicola cola;

int main(){
CrearBicola(&cola);
	for(int i=0;i<7;i++){
	printf("%d",i);
	if(i%2){
		if(!PonerFrente(&cola,a[i]))
			break;
	}else{
		if(!PonerFinal(&cola,a[i]))
			break;
	}
}

int elemento;
while(QuitarFrente(&cola,&elemento)){
	printf("->%d", &elemento);
}




return 0;
}
