//
// Created by ericd on 10/12/2023.
//
#include "fichier_Part2.h"
#include "stdlib.h"
#include "stdio.h"


t_cell *rechercherClassique(t_list *liste, int valeur) {
    t_cell *current = liste->heads[0];
    while (current && current->value != valeur) {
        current = current->next[0];
    }
    return current;
}


void createLeveledList(int n)
{
    //Calcul du nombre total de cellules
    int totalCells = (1 << n) - 1;
    //Allocation de mémoire pour les cellules
    t_list *list = createEmptyList(n);
    //Allocation de mémoire pour le tableau des niveaux
    int *levels = (int *)malloc(totalCells * sizeof(int));

    //Initialisation du tableau des niveaux à 0
    for (int i = 0; i < totalCells; i++) {
        levels[i] = 0;
    }
    //Initialisation des niveaux
    int step = totalCells / 2;
    while (step > 0) {
        for (int i = step - 1; i < totalCells; i += 2 * step) {
            levels[i] += 1;
        }
        step /= 2;
    }
    //On ajoute les cellules dans la liste
    for (int i = 0; i < totalCells; i++) {
        int valeurCellule = i + 1;
        int niveauCellule = levels[i];

        t_cell *newCell = createCell(valeurCellule, niveauCellule);

        for (int niveau = 0; niveau <= niveauCellule; niveau++) {
            newCell->next[niveau] = list->heads[niveau];
            list->heads[niveau] = newCell;
        }
    }
    //On libère la mémmoire
    free(levels);
}

t_cell *rechercherAuPlusHautNiveau(t_list *liste, int valeur) {
    int niveauActuel = liste->max_level - 1; // on commence la recherche du niveau max
    t_cell *result = NULL;

    while (niveauActuel >= 0 && result == NULL) {
        t_cell *current = liste->heads[niveauActuel];

        while (current != NULL && current->value != valeur) {
            if (current->next[niveauActuel] == NULL || current->next[niveauActuel]->value > valeur) {
                // si la valeur suivante est plus grande on descend d'un niveau
                niveauActuel--;
            } else {
                current = current->next[niveauActuel];
            }
        }
        if (current != NULL && current->value == valeur) {
            // la valeur recherchée a été retrouvée
            result = current;
        }
    }
    // La valeur n'est pas présente dans la liste
    return result;
}