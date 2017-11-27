#include<SDL2/SDL.h>
#include<math.h>
#include "pieces.h"

boolean bKing(struct state gamestate[12][8], int i,int j,int k,int l)
{
	if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color == gamestate[k][l].piece_pos.color)) return FALSE;
	if(abs(k-i) == 1 && (l==j || abs(l-j)==1))
	{
		if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
		
		return TRUE;
	}
	
	if(abs(l-j) == 1 && (i==k || abs(k-i)==1))
	{
		if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
		
		return TRUE;
	}
	return FALSE;
}