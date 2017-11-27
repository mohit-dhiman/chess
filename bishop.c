#include<SDL2/SDL.h>
#include<math.h>
#include "pieces.h"

boolean bBishop(struct state gamestate[12][8], int i, int j, int k, int l)
{
	if(abs(k-i) == abs(l-j))
	{
		if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color == gamestate[k][l].piece_pos.color)) return FALSE;
		int n = abs(k-i) - 1, count;
		//bottom right
		if(k>i && l>j)
		{
			for(count = 1; count<=n; count++)
			{
				if(gamestate[i+count][j+count].occupied == TRUE) return FALSE;
			}
			if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
					
			return TRUE;
		}
		
		//bottom left
		if(k>i && l<j)
		{
			for(count = 1; count<=n; count++)
			{
				if(gamestate[i+count][j-count].occupied == TRUE) return FALSE;
			}
			if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
					
			return TRUE;
		}
		
		//top right
		if(k<i && l>j)
		{
			for(count = 1; count<=n; count++)
			{
				if(gamestate[i-count][j+count].occupied == TRUE) return FALSE;
			}
			if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
					
			return TRUE;
		}
		
		//top left
		if(k<i && l<j)
		{
			for(count = 1; count<=n; count++)
			{
				if(gamestate[i-count][j-count].occupied == TRUE) return FALSE;
			}
			if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
					
			return TRUE;
		}
		
	}else
	{
		return FALSE;
	}
}