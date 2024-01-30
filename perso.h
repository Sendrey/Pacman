#ifndef PERSO_H

#define PERSO_H

#include <stdio.h>
#include <string.h>
#include <gestionGraphique.h>


struct persoSt{
	char nom[30];
	int lig;
	int col;
};


struct persoSt initPerso(char nom[30]);
struct persoSt deplace(struct persoSt p, char c, char grille);
void affCaracPerso(struct persoSt p);


#endif 