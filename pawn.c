#include<SDL2/SDL.h>
#include<math.h>
#include "pieces.h"

boolean bPawn(struct state gamestate[12][8], int i,int j,int k,int l)
{
	if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color == gamestate[k][l].piece_pos.color)) return FALSE;
	
	//black pawn
	if(gamestate[i][j].piece_pos.color == BLACK)
	{	
		if(i==1 && k==3 && j==l)
		{
			if(gamestate[2][j].occupied == FALSE && gamestate[3][j].occupied == FALSE)
				return TRUE;
		}
		
		if(k == (i+1))
		{
			if((l ==(j-1) || l == (j+1) ) && gamestate[k][l].occupied == TRUE && gamestate[k][l].piece_pos.color == WHITE)
			{
				return KILL;
			}
			if((l == j) && gamestate[k][l].occupied == FALSE)
			{
				return TRUE;
			}
			
			return FALSE;
		}else
		{
			return FALSE;
		}
	}
	
	//White pawn
	if(gamestate[i][j].piece_pos.color == WHITE)
	{
		if(i==6 && k==4 && j==l)
		{
			if(gamestate[4][j].occupied == FALSE && gamestate[5][j].occupied == FALSE)
				return TRUE;
		}
		
		if(k == (i-1))
		{
			if((l ==(j-1) || l == (j+1) ) && gamestate[k][l].occupied == TRUE && gamestate[k][l].piece_pos.color == BLACK)
			{
				return KILL;
			}
			if((l == j) && gamestate[k][l].occupied == FALSE)
			{
				return TRUE;
			}
			
			return FALSE;
		}else
		{
			return FALSE;
		}
	}
	
}