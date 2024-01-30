#include "perso.h"

struct persoSt initPerso(char nom[30]){
	struct persoSt p;
	strcpy(p.nom,nom);
	p.x=0;
	p.y=0;
	return p;
}

struct persoSt deplace(struct persoSt p, char c, char grille){
	if(c=='g')
		if ((grille[p.x-1][p.y])=='2')
		p.x = p.x - 1;
	else if(c=='d')
		if ((grille[p.x+1][p.y])=='2')
		p.x = p.x + 1;
	else if(c=='b')
		if ((grille[p.x][p.y-1])=='2')
		p.y = p.y - 1;
	else if(c=='h')
		if ((grille[p.x][p.y+1])=='2')
		p.y = p.y + 1;
	return p;
}


void affCaracPerso(struct persoSt p){
	printf("%s : l = %d - c = %d -> \n", p.nom, p.x, p.y);
}