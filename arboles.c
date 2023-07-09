#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arbol{
	char dato;
	struct arbol *derecho,*izquierdo;
}Arbol;

Arbol *arbol;


int inserta(Arbol **arbol, char elemento){
	if(*arbol==NULL){
		*arbol=(Arbol*)malloc(sizeof(Arbol));
		(*arbol)->dato=elemento;
		return 1;
		(*arbol)->izquierdo=NULL;
		(*arbol)->derecho=NULL;
	return 1;
	}
	if((*arbol)->dato==elemento)
		return 0;
	else
	if((*arbol)->dato<elemento)
		return inserta(&(*arbol)->izquierdo,elemento);
	else
	return	inserta(&(*arbol)->derecho,elemento);
}


int cuentah(Arbol *arbol){
	if (!arbol)
		return 0;
	if(arbol->izquierdo==NULL && arbol->derecho==NULL)
		return 1;
	return cuentah(arbol->izquierdo)+cuentah(arbol->derecho);

}


int profundidad(Arbol *arbol){
	int alti=0,altd=0;
	if (!arbol)
		return 0;
	if(arbol->izquierdo)
		alti=1+profundidad(arbol->izquierdo);
	if(arbol->derecho)
		altd=1+profundidad(arbol->derecho);
	if(alti>altd)
		return alti;
	return altd;
}



int peso(Arbol *arbol){
	if(!arbol)
		return 0;
	return peso(arbol->izquierdo)+peso(arbol->derecho)+1;

}

void preorden(Arbol *arbol){
	if(arbol==NULL)
		return;
	printf("%c",arbol->dato);
	preorden(arbol->izquierdo);
	preorden(arbol->derecho);
}

int iguales(Arbol* a, Arbol *b){
	if(!a && !b)
		return 1;
	if(!a || !b)
		return 0;
	if(a->dato==b->dato){
		if(iguales(a->izquierdo,b->izquierdo))
			return iguales(a->derecho,b->derecho);
	}
}



char b[]={'b','a','c','d','e','f','g'};

Arbol *arbol=NULL;

int main(){
	for(int i=0;i<7;i++)
		inserta(&arbol,b[i]);
	printf("\nTiene %d hojas", cuentah(arbol));
	printf("\nTiene %d de peso", peso(arbol));
	printf("\nTiene %d de profundidad\n", profundidad(arbol));
return 0;
}
