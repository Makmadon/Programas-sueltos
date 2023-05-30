#include <stdio.h>
#include <stdlib.h>

int num_vertices;

char cruces[100][5];

struct Graph {
  int V; // Number of vertices
  int E; // Number of edges
  int adj[100][100]; // Adjacency matrix
};

struct Graph* createGraph(int V) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = 0;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      graph->adj[i][j] = 0;
    }
  }
  return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
  graph->adj[u][v] = 1;
  graph->adj[v][u] = 1;
  graph->E++;
}

void greedyColoring(struct Graph* graph, int* colors) {
  for (int i = 0; i < graph->V; i++) {
    colors[i] = 0;
  }

  for (int i = 0; i < graph->V; i++) {
    int color = 1;
    for (int j = 0; j < i; j++) {
      if (graph->adj[i][j] == 1 && colors[j] == color) {
        color++;
      }
    }
    colors[i] = color;
  }
}


void read_file(char *archivo){
    FILE *fp;
    if((fp=fopen(archivo,"r"))==NULL){
		fprintf(stderr,"Error al abrir %s\n",archivo);
		exit(1);
	}
    fscanf(fp,"%d", &num_vertices);
    for(int i=0;i<num_vertices;i++)
        fscanf(fp,"%s",cruces[i]);
}