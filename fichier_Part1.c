//
// Created by ericd on 23/10/2023.
//
#include "fichier_Part1.h"
#include "stdio.h"
#include "stdlib.h"


t_cell *createCell(int val, int levl)
{
    t_cell *newCell = (t_cell*) malloc(sizeof(t_cell));
    newCell->value = val;
    newCell->level = levl;

    //allocation de mémoire d'un tableau de pointeur de cellule dont la taille est déterminé par levl
    newCell->next = (t_cell**) malloc(levl * sizeof (t_cell*));
    for(int i=0; i<levl; i++){
        //la cellule crée ne pointe vers rien initialement
        newCell->next[i] = NULL;
    }
    return newCell;
}



t_list *createEmptyList(int lvl_max)
{
    t_list *newList = (t_list*)malloc(sizeof(t_list));
    newList->max_level = lvl_max;

    //on alloue un tableau de pointeur de cellule avec lvl_max niveaux dans la liste
    newList->heads = (t_cell**)malloc(lvl_max * sizeof(t_cell*));
    //pour intialise chaque head dans chaque niveau à NULL pour avoir une liste vide à chaque niveau
    for(int i = 0; i < lvl_max; i++){
        newList->heads[i] = NULL;
    }
    return newList;
}



void InsertCellAtHead(t_cell *newCell, t_list *list)
{
    if(newCell->level > list->max_level){
        printf("Le niveau de la Celulle est supérieur à la hauteur max de la liste !\n");
    }
    else
    {
        // on parcourt tous les niveaux de la liste pour ajouter la cellule à la tête
        for(int i = 0; i< list->max_level; i++){
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }
    }
}


void displayCellsAtLevel(t_list list, int nivDemande)      // t_list est copié car on veut simplement parcourir
{
    if(nivDemande > list.max_level || nivDemande < 0){
        printf("The targeted level doesn't exist !");
    }
    else{
        printf("[ list HEAD_%d] --",nivDemande);
        t_cell *temp = list.heads[nivDemande];
        while(temp != NULL)
        {
            // tant qu'on atteint pas la dernière cellule qui pointe vers NULL on affiche la valeur de la cellule actuelle
            printf("> [ %d | @ ]--", temp->value);
            temp = temp->next[nivDemande];
        }
        printf(">NULL\n");
    }
}


//on ne prend pas de pointeur en argument car on ne modifie pas la liste
void displayAllLevel( t_list liste) {
    // on fait une boucle avec la fonction qui affiche à un niveau pour afficher tout les niveaux
    for (int i=0;i<liste.max_level;i++)
    {
        displayCellsAtLevel(liste,i);
    }
}


void insererTriee(t_list *list, int val) {
    t_cell *newCell = createCell(val, list->max_level);
    //tableau update utile pour stocker els mises à jour nécessaire lors de l'insertion des cellules
    t_cell **update = malloc(sizeof(t_cell *) * list->max_level);

    //boucle qui parcours chaque niveau de la liste pour trouver l'endroit idéal pour la cellule à ajouter
    for (int i = list->max_level - 1; i >= 0; i--) {
        t_cell *current = list->heads[i];
        while (current != NULL && current->next[i] != NULL && current->next[i]->value < val) {
            current = current->next[i];
        }
        //met à jour le tableau des cellules précédentes où la nouvelle cellule doit être ajoutée
        update[i] = current;
    }
    //en ayant déterminé la position de la mise à jour (update) la nouvelle cellule va pouvoir être positionner entre la cellule précédente et sa suivante
    for (int i = 0; i < list->max_level; i++) {
        if (update[i] != NULL) {
            newCell->next[i] = update[i]->next[i];
            update[i]->next[i] = newCell;
        } else {
            //si aucune cellule n'a été prélevé dans update (donc liste vide) alors la nouvelle cellule est placé en tant que head
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }
    }
    free(update);
}


