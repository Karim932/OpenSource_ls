#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    const char *directory;

    // Vérifier si un argument a été fourni
    if (argc == 2) {
        // Utiliser le répertoire spécifié
        directory = argv[1];
    } else {
        // Utiliser le répertoire courant
        char current_directory[1024];
        if (getcwd(current_directory, sizeof(current_directory)) != NULL) {
            directory = current_directory;
        } else {
            perror("Erreur lors de l'obtention du répertoire courant");
            exit(EXIT_FAILURE);
        }
    }

    // Ouvrir le répertoire spécifié
    DIR *dir = opendir(directory);

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

