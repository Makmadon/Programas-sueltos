#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	char dato;
	struct nodo* lista,*next;
}Nodo;


Nodo* creaNodo(char dato){
	Nodo* newp;
	if((newp=(Nodo*)malloc(sizeof(Nodo)))==NULL)
		return NULL;
	newp->dato=dato;
	newp->next=NULL;
	newp->lista=NULL;
	return newp;
}

Nodo* AddLista(Nodo *lista,Nodo* newp){
	Nodo *p=lista;
	if(!lista)
		return newp;
	while(p->lista)
		p=p->lista;
	p->lista=newp;
	return lista;
}

Nodo* AddDato(Nodo *lista, char dato){
	Nodo *newp=creaNodo(dato),*p=lista;
	if(!lista)
		return newp;
	while(p->next)
		p=p->next;
	p->next=newp;
	return lista;
}


void vacia(Nodo* lista){
	if(!lista)
		return;
	while(lista){
	if(lista->lista){
		vacia(lista->lista);
	}
	free(lista);
	}
	
}



void imprime(Nodo* lista){
	printf("(");
	while(lista){
		printf("%c,",lista->dato);
	if(lista->lista){
		imprime(lista->lista);
		printf(")");
	}
	lista=lista->next;
	}
	printf(")");
}

char caracter;
int opcion;
Nodo *lista,*lista2;

int main(){
	while(1){
		while(1){
			printf("Ingrese los elementos de la lista\nIngrese 0 para crear otra lista\n");
			scanf("%c", &caracter);
			if(caracter=='0')
				break;
			lista=AddDato(lista,caracter);
			while(getchar() != '\n');
		}
	lista2=AddLista(lista2,lista);
	while(getchar() != '\n');
	printf("Desea añadir mas listas?\nNo:0\n");
	scanf("%c", &caracter);
	if(caracter=='0')
		break;
	while(getchar() != '\n');
}
imprime(lista2);
return 0;
}
