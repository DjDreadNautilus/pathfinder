#include "../inc/pathfinder.h"

t_graph *mx_read_graph(const char *filename) {

    char *file_content = mx_file_to_str(filename);
    char **strarr = mx_strsplit(file_content, '\n');

    if (!mx_validate_file(strarr, filename, file_content)) {
        mx_del_strarr(&strarr);
        free(file_content);

        return NULL;
    }

    int num_vertices = mx_atoi(strarr[0]);
    t_graph *graph = mx_create_graph(num_vertices);

    if (!graph) {
        mx_printerr("erorr: graph creation failed\n");
        free(file_content);
        mx_del_strarr(&strarr);

        return NULL;
    }

    for (int i = 1; strarr[i] != NULL; i++) {
        int dash_index = mx_get_char_index(strarr[i], '-');
        int comma_index = mx_get_char_index(strarr[i], ',');
        char *name1 = mx_strndup(strarr[i], dash_index);
        char *name2 = mx_strndup(strarr[i] + dash_index + 1, comma_index - dash_index - 1);
        int distance = mx_atoi(strarr[i] + comma_index + 1);

        if (!name1 || !name2 || distance <= 0) {
            free(name1);
            free(name2);

            continue;
        }

        t_vertex *v1 = NULL;
        t_vertex *v2 = NULL;

        for (int j = 0; j < graph->V; j++) {
            if (graph->vertices[j] && mx_strcmp(graph->vertices[j]->name, name1) == 0) {
                v1 = graph->vertices[j];
            }
            
            if (graph->vertices[j] && mx_strcmp(graph->vertices[j]->name, name2) == 0) {
                v2 = graph->vertices[j];
            }
        }

        if (!v1) {
            v1 = mx_create_vertex(name1);

            if (v1) {
                for (int j = 0; j < graph->V; j++) {
                    if (!graph->vertices[j]) {
                        graph->vertices[j] = v1;

                        break;
                    }
                }
            }
        }

        if (!v2) {
            v2 = mx_create_vertex(name2);

            if (v2) {
                for (int j = 0; j < graph->V; j++) {
                    if (!graph->vertices[j]) {
                        graph->vertices[j] = v2;

                        break;
                    }
                }
            }
        }

        if (v1 && v2) {
            mx_add_connection(v1, v2, distance);
        }

        free(name1);
        free(name2);
    }

    free(file_content);
    mx_del_strarr(&strarr);
    
    return graph;
}



