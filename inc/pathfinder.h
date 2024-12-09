#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"
#include <limits.h>

//graph related structures

typedef struct s_vertex
{
    char *name;
    struct s_vertex **connections;
    int *distances;
    int num_connections;   
} t_vertex;

typedef struct s_graph
{
    t_vertex **vertices;  
    int V;                 
} t_graph;

typedef struct s_paths {
    int **paths;       
    int *path_lengths;  
    int num_paths;      
} t_paths;

//utility

int mx_atoi(const char *str);
bool mx_isdigit(char c);
int mx_strncmp_at(const char *s1, const char *s2, int len1, int len2);
void mx_printerr(const char *s);
bool mx_isalpha(char c);

//graph

t_graph *mx_create_graph(int V);
t_vertex *mx_create_vertex(const char *name);
void mx_add_connection(t_vertex *vertex, t_vertex *connection, int distance);
void mx_free_graph(t_graph *graph);
t_graph *mx_read_graph(const char *filename);
void mx_free_vertex(t_vertex *vertex);
void mx_free_paths(t_paths *all_paths);

//validate

bool mx_validate_file(char **strarr, const char *filename, char *file_content);
bool mx_validate_dublicates(char **strarr);
int mx_count_real_amount(char **strarr);
bool is_vertex_in_list(t_list *list, char *vertex);
bool mx_validate_line(const char *line);

//algorithm

t_paths mx_find_all_paths(t_graph *graph, int src, int dst);
int mx_find_distance(t_graph *graph, int *path, int path_length);
void mx_print_shortest(t_graph *graph, int *path, int length);
t_paths mx_find_shortest_paths(t_graph *graph, int src, int dst);
void dfs_find_shortest_paths(t_graph *graph, int src, int dst, bool *visited, int *path, int path_index, t_paths *shortest_paths, int current_distance, int *min_distance);

#endif
