#include <stdio.h>
#define mid(a,b) ((a+b)>>1)  //macro para calcular la mitad del arreglo

int Bbinaria(int valor, int arr[], int size){
    int bajo=0, alto=size, medio;

    while(bajo<=alto){
        medio=mid(bajo,alto); //si el valor es iglual al almacenado a la mitad se retorna su posicion


        if(arr[medio]==valor)  //se ubica en que mitad es mas probable que se encuentre el valor
            return medio;
        if(valor>arr[medio]){
            alto=medio-1;   //en caso de ser mayor, se busca en el lado inferior
        }else{
            bajo=medio+1;   //en caso de ser menor, se busca en el lado superior
        }
    }
    return -1; //si no lo encuentra se retorna -1
}

//arreglo descendente
int l[]={50,45,40,35,30,25,20,15,10,5,0};

int main(){
//verificacion del funcionamiento del algoritmo
    if(Bbinaria(40,l,sizeof(l)/sizeof(int))>=0)
        printf("Encontrado");

    return 0;
}