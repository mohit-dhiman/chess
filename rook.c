#include<SDL2/SDL.h>
#include<math.h>
#include "pieces.h"

boolean bRook(struct state gamestate[12][8], int i,int j,int k,int l){
	if(i==k || j==l)
	{	
		if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color == gamestate[k][l].piece_pos.color)) return FALSE;	
		int n,count;
		
		//horizontal
		if(i==k)
		{
			n=abs(l-j)-1;
			//forward
			if(j<l)
			{
				for(count=1;count<=n;count++)
				{
					if(gamestate[i][j+count].occupied == TRUE) return FALSE;
				}
				if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
					
				return TRUE;
			}//backward
			if(j>l)
			{
				for(count=1;count<=n;count++)
				{
					if(gamestate[i][l+count].occupied == TRUE) return FALSE;
				}
				if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
				
				return TRUE;
			}
		}
		
		//vertical
		else if(j == l)
		{
			n=abs(k-i)-1;
			//down
			if(i<k)
			{
				for(count=1;count<=n;count++)
				{
					if(gamestate[i+count][j].occupied == TRUE) return FALSE;
				}
				if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
				
				return TRUE;
			}//up
			if(i>k)
			{
				for(count=1;count<=n;count++)
				{
					if(gamestate[k+count][j].occupied == TRUE) return FALSE;
				}
				if((gamestate[k][l].occupied == TRUE) && (gamestate[i][j].piece_pos.color != gamestate[k][l].piece_pos.color))return KILL;
				
				return TRUE;
			}
		}
		
	}else
	{
		return FALSE;
	}
}