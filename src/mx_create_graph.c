#include "../inc/pathfinder.h"

t_graph *mx_create_graph(int V) {

    t_graph *graph = (t_graph *)malloc(sizeof(t_graph));
    
    if (!graph) {
        return NULL; 
    }
    
    graph->vertices = (t_vertex **)malloc(V * sizeof(t_vertex *));
    graph->V = V;
    
    for (int i = 0; i < graph->V; i++) {
        graph->vertices[i] = NULL; 
    }
    
    return graph;
    
}
