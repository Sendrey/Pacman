#include <test>
BAPTISTE EST UN GRAND FOUFOU
int pac[10][10]={
	{1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,1,1,2,1,2,1,2,1},
	{1,2,1,1,2,1,2,1,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,2,1,1,1,1,2,1,1},
	{1,1,2,1,1,1,1,2,1,1},
	{1,2,2,2,1,1,2,2,2,1},
	{1,2,1,2,1,1,2,1,2,1},
	{1,2,2,2,1,1,2,2,2,1},
};

g
	
void plateau(int pac[10][10]){
	int i,j;
	for(i=0;i<HAUT;i=i+1)
		for(j=0;j<LARG;j=j+1)
			if(pac[i][j]==1){
				renderTexture(wall, ren, i*LARG, j*HAUT, LARG, HAUT);
			}
			if(pac[i][j]==2){
				renderTexture(gum, ren, i*LARG, j*HAUT, LARG, HAUT);
			}
}
				
