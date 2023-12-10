//
// Created by ericd on 06/12/2023.
//

#ifndef AGENDA_GR_FICHIER_PART1_H
#define AGENDA_GR_FICHIER_PART1_H

typedef struct s_cell {
    int value;
    struct s_cell **next;
    int level;
} t_cell;

typedef struct s_list {
    t_cell **heads;
    int max_level;
} t_list;

t_cell *createCell(int val, int levl);

t_list *createEmptyList(int lvl_max);

void InsertCellAtHead(t_cell *newCell, t_list *list);

void displayCellsAtLevel( t_list liste, int niveauDemande);

void displayAllLevel( t_list liste);

void insererTriee(t_list *list, int val);



#endif //AGENDA_GR_FICHIER_PART1_H
