#include <stdio.h>
#include "fichier_Part1.h"
#include "timer.h"
#include "stdlib.h"


/*
//pour tester createEmptyList
int main(){
    t_list *list = createEmptyList(3);
    displayAllLevel(*list);
}
*/

/*
//pour tester createCell, insererTriee, displayCellsAtLevel, InsertAtHead, displayAllLevel
int main(){
    t_list *list = createEmptyList(4);
    insererTriee(list, 15);
    insererTriee(list, 1);
    insererTriee(list, 25);
    printf("Voici l'insertion des cellules dans l'ordre croissant :\n");
    displayCellsAtLevel(*list, 2);
    InsertCellAtHead(createCell(12, 2), list);
    printf("\nVoici la liste apres l'ajout de cellule a la tete \n");
    displayCellsAtLevel(*list, 2);
    printf("\nVoici ce que sa donne sur tous les niveaux :\n");
    displayAllLevel(*list);
}
 */


/*
//pour tester la recherche classique
int main() {
    t_list *list = createEmptyList(3);
    insererTriee(list, 5);
    insererTriee(list, 7);
    insererTriee(list, 4);

    displayAllLevel(*list);
    int valeurRecherchee = 5;
    t_cell *resultatRechercheClassique = rechercherClassique(list, valeurRecherchee);

    if (resultatRechercheClassique != NULL) {
        printf("La valeur %d a ete trouvee dans la recherche classique.\n", valeurRecherchee);
    } else {
        printf("La valeur %d n'a pas ete trouvee dans la recherche classique.\n", valeurRecherchee);
    }

    return 0;
}*/


//pour tester la fonction de rechercherAuPlusHautNiveau
int main(){
    t_list *list = createEmptyList(3);
    insererTriee(list, 5);
    insererTriee(list, 7);
    insererTriee(list, 4);

    displayAllLevel(*list);
    int valeurRecherchee = 5;
    t_cell *resultatRecherche = rechercherAuPlusHautNiveau(list, valeurRecherchee);

    if (resultatRecherche != NULL) {
        printf("La valeur %d a ete trouvee dans la recherche classique.\n", valeurRecherchee);
    } else {
        printf("La valeur %d n'a pas ete trouvee dans la recherche classique.\n", valeurRecherchee);
    }

    return 0;
}