#include "../inc/pathfinder.h"

void mx_free_paths(t_paths *all_paths) {
    for (int i = 0; i < all_paths->num_paths; i++) {
        free(all_paths->paths[i]);
    }

    free(all_paths->paths);
    free(all_paths->path_lengths);
}

