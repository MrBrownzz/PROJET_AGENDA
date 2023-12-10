//
// Created by ericd on 10/12/2023.
//

#ifndef AGENDA_GR_FICHIER_PART2_H
#define AGENDA_GR_FICHIER_PART2_H
#include "fichier_Part1.h"


t_cell *rechercherClassique(t_list *liste, int valeur);

void createLeveledList(int n);

t_cell *rechercherAuPlusHautNiveau(t_list *liste, int valeur);

#endif //AGENDA_GR_FICHIER_PART2_H
