#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodo{
	int dato;
	struct nodo *next;
}Nodo;

typedef struct arbol{
	int dato;
	struct arbol *derecho,*izquierdo;
}Arbol;

Arbol *arbol;



Arbol *arbol=NULL;


Nodo* creaNodo(int dato){
	Nodo* newp;
	if((newp=(Nodo*)malloc(sizeof(Nodo)))==NULL)
		return NULL;
	newp->dato=dato;
	newp->next=NULL;
	return newp;
}

Nodo* AddLista(Nodo *lista,Nodo* newp){
	Nodo *p=lista;
	if(!lista)
		return newp;
	while(p->next)
		p=p->next;
	p->next=newp;
	return lista;
}

Nodo* AddDato(Nodo *lista, char dato){
	Nodo *newp=creaNodo(dato),*p=lista;
	return AddLista(lista,newp);
}


int inserta(Arbol **arbol, int elemento){
	if(*arbol==NULL){
		*arbol=(Arbol*)malloc(sizeof(Arbol));
		(*arbol)->dato=elemento;
		(*arbol)->izquierdo=NULL;
		(*arbol)->derecho=NULL;
		return 1;
	}
	if((*arbol)->dato==elemento)
		return 0;
	else
	if(((*arbol)->dato)<elemento)
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

Nodo* Rama(Arbol *arbol){
	int alti=0,altd=0;
	Nodo* lista;
	if (!arbol)
		return NULL;
	lista=AddDato(lista,arbol->dato);
	if(arbol->izquierdo)
		alti=1+profundidad(arbol->izquierdo);
	if(arbol->derecho)
		altd=1+profundidad(arbol->derecho);
	if(alti>altd)
		return AddLista(lista,Rama(arbol->izquierdo));
	return AddLista(lista,Rama(arbol->derecho));
}

int peso(Arbol *arbol){
	if(!arbol)
		return 0;
	return peso(arbol->izquierdo)+peso(arbol->derecho)+1;

}

Arbol* Espejo(Arbol* a){
	Arbol* aux;
	if(!a)
		return	NULL;
	aux=Espejo(a->derecho);
	a->derecho=Espejo(a->izquierdo);
	a->izquierdo=aux;
	return a;
}


void preorden(Arbol *arbol){
	if(arbol==NULL)
		return;
	printf("%d ",arbol->dato);
	preorden(arbol->izquierdo);
	preorden(arbol->derecho);
}

void imprime(Nodo* lista){
	while(lista){
		printf("->%d",lista->dato);
		lista=lista->next;
	}
	printf("\n");
}

int a[]={4,2,8,1,3,6,5,7};

int main(){
	for (int i=0;i<8;i++)
		inserta(&arbol,a[i]);
	printf("Rama mas larga:");
	imprime(Rama(arbol));
	preorden(arbol);
	printf("\n");
	preorden(Espejo(arbol));
return 0;
}
