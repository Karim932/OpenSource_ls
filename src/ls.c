#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    // Déclarer une chaîne pour stocker le chemin du répertoire
    char directory[256];

    // Demander à l'utilisateur d'entrer le chemin du répertoire
    printf("Entrez le chemin du répertoire : ");
    scanf("%255s", directory);

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
