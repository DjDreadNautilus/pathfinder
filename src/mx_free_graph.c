#include "../inc/pathfinder.h"

void mx_free_graph(t_graph *graph) {
    if (!graph) {
        return;
    } 

    for (int i = 0; i < graph->V; i++) {
        t_vertex *vertex = graph->vertices[i];
        
        if (vertex) {
            free(vertex->name); 
            free(vertex->connections);
            free(vertex->distances);  
            free(vertex);              
        }
    }
    
    mx_free_graph(graph);
        
}
