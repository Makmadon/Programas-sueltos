#include <stdio.h>
#include <stdlib.h>

int num_vertices;

char aristas[100][10];

char cruces[100][5];

struct grafo {
  int V; // Number of vertices
  int E; // Number of edges
  int adj[100][100]; // Adjacency matrix
};
struct grafo* crea_grafo(int V) {
  struct grafo* grafo = (struct grafo*)malloc(sizeof(struct grafo));
  grafo->V = V;
  grafo->E = 0;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      grafo->adj[i][j] = 0;
    }
  }
  return grafo;
}

void crea_arista(struct grafo* grafo, int u, int v) {
  grafo->adj[u][v] = 1;
  grafo->adj[v][u] = 1;
  grafo->E++;
}

void coloracion(struct grafo* grafo, int colores[]) {
  for (int i = 0; i < grafo->V; i++) {
    colores[i] = 0;
  }

  for (int i = 0; i < grafo->V; i++) {
    int color = 1;
    for (int j = 0; j < i; j++) {
      if (grafo->adj[i][j] == 1 && colores[j] == color) {
        color++;
      }
    }
    colores[i] = color;
  }
}

void read(char *archivo){
    FILE *fp;
    if((fp=fopen(archivo,"r"))==NULL){
		fprintf(stderr,"Error al abrir %s\n",archivo);
		exit(1);
	}
    fscanf(fp,"%d", &num_vertices);
    for(int i=0;i<num_vertices;i++)
        fscanf(fp,"%s",cruces[i]);
    for(int i=0;!EOF;i++){
        scanf(fp,"%s",aristas[i]);
    }
    
}


