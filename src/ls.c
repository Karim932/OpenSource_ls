/*
name: Bug report
about: Faire un report pour améliorer le projet
title: ''
labels: bug, good first issue
assignees: Karim932
*/


#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    // Vérifier si le nombre d'arguments est correct
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Ouvrir le répertoire spécifié
    DIR *dir = opendir(argv[1]);

    // Vérifier si le répertoire a été ouvert avec succès
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        exit(EXIT_FAILURE);
    }

    // Lire les entrées du répertoire
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Fermer le répertoire
    closedir(dir);

    return 0;
}
