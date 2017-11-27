#ifndef ALL_H_INCLUDED
#define ALL_H_INCLUDED
#define TRUE 1
#define FALSE 0
#define KILL 7
enum{BLACK = 8, WHITE =9};
enum{
	BROOK1 = 11,
	BROOK2 = 12,
	BKNIGHT1 = 13,
	BKNIGHT2 = 14,
	BBISHOP1 = 15,
	BBISHOP2 = 16,
	BQUEEN = 17,
	BKING = 18,
	
	WROOK1 = 19,
	WROOK2 = 20,
	WKNIGHT1 = 21,
	WKNIGHT2 = 22,
	WBISHOP1 = 23,
	WBISHOP2 = 24,
	WQUEEN = 25,
	WKING = 26,
	
	BPAWN1 = 27,
	BPAWN2 = 28,
	BPAWN3 = 29,
	BPAWN4 = 30,
	BPAWN5 = 31,
	BPAWN6 = 32,
	BPAWN7 = 33,
	BPAWN8 = 34,
	
	WPAWN1 = 35,
	WPAWN2 = 36,
	WPAWN3 = 37,
	WPAWN4 = 38,
	WPAWN5 = 39,
	WPAWN6 = 40,
	WPAWN7 = 41,
	WPAWN8 = 42,
	
};
typedef int boolean;
typedef struct piece
{
	int color;
	int name;
	
}mypiece;

typedef struct state
{
	SDL_Rect rect;
	boolean occupied;
	struct piece piece_pos; 
}gamestate;


boolean bRook(struct state gamestate[12][8], int i,int j,int k,int l);
boolean bBishop(struct state gamestate[12][8], int i,int j,int k,int l);
boolean bKnight(struct state gamestate[12][8], int i,int j,int k,int l);
boolean bKing(struct state gamestate[12][8], int i,int j,int k,int l);
boolean bPawn(struct state gamestate[12][8], int i,int j,int k,int l);
#endif