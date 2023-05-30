#include <stdio.h>




void read_file(char *archivo){
    FILE *fp;
    if((fp=fopen(archivo,"r"))==NULL){
		fprintf(stderr,"Error al abrir %s\n",archivo);
		exit(1);
	}
    
}