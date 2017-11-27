#include<SDL2/SDL.h>
#include<math.h>
#include "pieces.h"

boolean bKnight(struct state gamestate[12][8], int i,int j,int k,int l)
{
	if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color == gamestate[k][l].piece_pos.color)) return FALSE;
	
	//top/bottom to left/right
	if(abs(k-i) == 2 && abs(l-j) == 1 )
	{
		if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
		
		return TRUE;
	}
	
	//left/right to top/bottom
	if(abs(l-j) == 2 && abs(k-i) == 1 )
	{
		if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
		
		return TRUE;
	}
	return FALSE;
}