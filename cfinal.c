#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>
#include"pieces.h"
#define WINDOW_WIDTH (1000)
#define WINDOW_HEIGHT (700)
#define BOX_XPOS (38)
#define BOX_YPOS (38)
#define BOX_WIDTH (78)
#define BOX_HEIGHT (78)
#define CEM_BOX_XPOS (700)
#define CEM_BOX_YPOS (0)
#define CEM_BOX_WIDTH (50)
#define CEM_BOX_HEIGHT (50)
#define B_CEM_BOX_YPOS (530)


	//initial position of black pieces
	int brr1=0,brc1=0,bkr1=0,bkc1=1,bbr1=0,bbc1=2,bqr=0,bqc=3,bkr=0,bkc=4,bbr2=0,bbc2=5,bkr2=0,bkc2=6,brr2=0,brc2=7;
	//initial position of white pieces
	int wrr1=7,wrc1=0,wkr1=7,wkc1=1,wbr1=7,wbc1=2,wqr=7,wqc=3,wkr=7,wkc=4,wbr2=7,wbc2=5,wkr2=7,wkc2=6,wrr2=7,wrc2=7;
	//initial position of black pawns
	int bpr1=1,bpc1=0,bpr2=1,bpc2=1,bpr3=1,bpc3=2,bpr4=1,bpc4=3,bpr5=1,bpc5=4,bpr6=1,bpc6=5,bpr7=1,bpc7=6,bpr8=1,bpc8=7;
	//initial position of white pawns
	int wpr1=6,wpc1=0,wpr2=6,wpc2=1,wpr3=6,wpc3=2,wpr4=6,wpc4=3,wpr5=6,wpc5=4,wpr6=6,wpc6=5,wpr7=6,wpc7=6,wpr8=6,wpc8=7;

//to create texture of chess pieces
	SDL_Surface* piecesurf = NULL;
	SDL_Texture* bpawntex[8];
	SDL_Texture* wpawntex[8];
	SDL_Texture* brooktex1;
	SDL_Texture* brooktex2;
	SDL_Texture* wrooktex1;
	SDL_Texture* wrooktex2;
	SDL_Texture* bknighttex1;
	SDL_Texture* bknighttex2;
	SDL_Texture* wknighttex1;
	SDL_Texture* wknighttex2;
	SDL_Texture* bbishoptex1;
	SDL_Texture* bbishoptex2;
	SDL_Texture* wbishoptex1;
	SDL_Texture* wbishoptex2;
	SDL_Texture* bqueentex;
	SDL_Texture* wqueentex;
	SDL_Texture* bkingtex;
	SDL_Texture* wkingtex;
	
	
	
	
//wcemetery creator
SDL_Rect myCemRect(int i, int j)
{	
	SDL_Rect rect;
	rect.x = CEM_BOX_XPOS + j * (CEM_BOX_WIDTH);
	rect.y = CEM_BOX_YPOS + i * (CEM_BOX_HEIGHT);
	rect.w = CEM_BOX_WIDTH;
	rect.h = CEM_BOX_HEIGHT;
	
	return rect;
}	

//cemetery creator
SDL_Rect bmyCemRect(int i, int j)
{	
	SDL_Rect rect;
	rect.x = CEM_BOX_XPOS + j * (CEM_BOX_WIDTH);
	rect.y = B_CEM_BOX_YPOS + i * (CEM_BOX_HEIGHT);
	rect.w = CEM_BOX_WIDTH;
	rect.h = CEM_BOX_HEIGHT;
	
	return rect;
}	


void pieceTexCreator(SDL_Renderer* rend){
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/blackrook.png");
	brooktex1 = SDL_CreateTextureFromSurface(rend, piecesurf);
	brooktex2 = brooktex1;
	SDL_FreeSurface(piecesurf);
	
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/whiterook.png");
	wrooktex1 = SDL_CreateTextureFromSurface(rend, piecesurf);
	wrooktex2 = wrooktex1;
	SDL_FreeSurface(piecesurf);
	
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/blackbishop.png");
	bbishoptex1 = SDL_CreateTextureFromSurface(rend, piecesurf);
	bbishoptex2 = bbishoptex1;
	SDL_FreeSurface(piecesurf);
	
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/whitebishop.png");
	wbishoptex1 = SDL_CreateTextureFromSurface(rend, piecesurf);
	wbishoptex2 = wbishoptex1;
	SDL_FreeSurface(piecesurf);
	
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/blackknight.png");
	bknighttex1 = SDL_CreateTextureFromSurface(rend, piecesurf);
	bknighttex2 = bknighttex1;
	SDL_FreeSurface(piecesurf);
	
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/whiteknight.png");
	wknighttex1 = SDL_CreateTextureFromSurface(rend, piecesurf);
	wknighttex2 = wknighttex1;
	SDL_FreeSurface(piecesurf);
	
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/blackqueen.png");
	bqueentex = SDL_CreateTextureFromSurface(rend, piecesurf);
	SDL_FreeSurface(piecesurf);
	
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/whitequeen.png");
	wqueentex = SDL_CreateTextureFromSurface(rend, piecesurf);
	SDL_FreeSurface(piecesurf);
	
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/blackking.png");
	bkingtex = SDL_CreateTextureFromSurface(rend, piecesurf);
	SDL_FreeSurface(piecesurf);
	
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/whiteking.png");
	wkingtex = SDL_CreateTextureFromSurface(rend, piecesurf);
	SDL_FreeSurface(piecesurf);
	
	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/blackpawn.png");
	int i = 0;
	for(i=0;i<8;i++)
		bpawntex[i] = SDL_CreateTextureFromSurface(rend, piecesurf);
	SDL_FreeSurface(piecesurf);

	piecesurf = (SDL_Surface*)IMG_Load("resources/pieces2/whitepawn.png");
	for(i=0;i<8;i++)
		wpawntex[i] = SDL_CreateTextureFromSurface(rend, piecesurf);
	SDL_FreeSurface(piecesurf);
	
}	
	
	
void pieceRenderer(SDL_Renderer* rend, struct state gamestate[12][8]){
	//draw pieces on board
		SDL_RenderCopy(rend, brooktex1, NULL, &gamestate[brr1][brc1].rect);	
		SDL_RenderCopy(rend, bknighttex1, NULL, &gamestate[bkr1][bkc1].rect);	
		SDL_RenderCopy(rend, bbishoptex1, NULL, &gamestate[bbr1][bbc1].rect);	
		SDL_RenderCopy(rend, bqueentex, NULL, &gamestate[bqr][bqc].rect);	
		SDL_RenderCopy(rend, bkingtex, NULL, &gamestate[bkr][bkc].rect);	
		SDL_RenderCopy(rend, bbishoptex2, NULL, &gamestate[bbr2][bbc2].rect);	
		SDL_RenderCopy(rend, bknighttex2, NULL, &gamestate[bkr2][bkc2].rect);	
		SDL_RenderCopy(rend, brooktex2, NULL, &gamestate[brr2][brc2].rect);	
	
	
		SDL_RenderCopy(rend, wrooktex1, NULL, &gamestate[wrr1][wrc1].rect);	
		SDL_RenderCopy(rend, wknighttex1, NULL, &gamestate[wkr1][wkc1].rect);	
		SDL_RenderCopy(rend, wbishoptex1, NULL, &gamestate[wbr1][wbc1].rect);	
		SDL_RenderCopy(rend, wqueentex, NULL, &gamestate[wqr][wqc].rect);	
		SDL_RenderCopy(rend, wkingtex, NULL, &gamestate[wkr][wkc].rect);	
		SDL_RenderCopy(rend, wbishoptex2, NULL, &gamestate[wbr2][wbc2].rect);	
		SDL_RenderCopy(rend, wknighttex2, NULL, &gamestate[wkr2][wkc2].rect);	
		SDL_RenderCopy(rend, wrooktex2, NULL, &gamestate[wrr2][wrc2].rect);
		
		SDL_RenderCopy(rend, bpawntex[0], NULL, &gamestate[bpr1][bpc1].rect);	
		SDL_RenderCopy(rend, bpawntex[1], NULL, &gamestate[bpr2][bpc2].rect);	
		SDL_RenderCopy(rend, bpawntex[2], NULL, &gamestate[bpr3][bpc3].rect);	
		SDL_RenderCopy(rend, bpawntex[3], NULL, &gamestate[bpr4][bpc4].rect);
		SDL_RenderCopy(rend, bpawntex[4], NULL, &gamestate[bpr5][bpc5].rect);
		SDL_RenderCopy(rend, bpawntex[5], NULL, &gamestate[bpr6][bpc6].rect);	
		SDL_RenderCopy(rend, bpawntex[6], NULL, &gamestate[bpr7][bpc7].rect);	
		SDL_RenderCopy(rend, bpawntex[7], NULL, &gamestate[bpr8][bpc8].rect);	
	
	
		SDL_RenderCopy(rend, wpawntex[0], NULL, &gamestate[wpr1][wpc1].rect);	
		SDL_RenderCopy(rend, wpawntex[1], NULL, &gamestate[wpr2][wpc2].rect);	
		SDL_RenderCopy(rend, wpawntex[2], NULL, &gamestate[wpr3][wpc3].rect);	
		SDL_RenderCopy(rend, wpawntex[3], NULL, &gamestate[wpr4][wpc4].rect);
		SDL_RenderCopy(rend, wpawntex[4], NULL, &gamestate[wpr5][wpc5].rect);
		SDL_RenderCopy(rend, wpawntex[5], NULL, &gamestate[wpr6][wpc6].rect);	
		SDL_RenderCopy(rend, wpawntex[6], NULL, &gamestate[wpr7][wpc7].rect);	
		SDL_RenderCopy(rend, wpawntex[7], NULL, &gamestate[wpr8][wpc8].rect);
		
		gamestate[brr1][brc1].occupied = TRUE;
		gamestate[bkr1][bkc1].occupied = TRUE;
		gamestate[bbr1][bbc1].occupied = TRUE;
		gamestate[bqr][bqc].occupied = TRUE;
		gamestate[bkr][bkc].occupied = TRUE;
		gamestate[bbr2][bbc2].occupied = TRUE;
		gamestate[bkr2][bkc2].occupied = TRUE;
		gamestate[brr2][brc2].occupied = TRUE;
	
		gamestate[wrr1][wrc1].occupied = TRUE;
		gamestate[wkr1][wkc1].occupied = TRUE;
		gamestate[wbr1][wbc1].occupied = TRUE;
		gamestate[wqr][wqc].occupied = TRUE;
		gamestate[wkr][wkc].occupied = TRUE;
		gamestate[wbr2][wbc2].occupied = TRUE;
		gamestate[wkr2][wkc2].occupied = TRUE;
		gamestate[wrr2][wrc2].occupied = TRUE;
		
		gamestate[bpr1][bpc1].occupied = TRUE;
		gamestate[bpr2][bpc2].occupied = TRUE;
		gamestate[bpr3][bpc3].occupied = TRUE;
		gamestate[bpr4][bpc4].occupied = TRUE;
		gamestate[bpr5][bpc5].occupied = TRUE;
		gamestate[bpr6][bpc6].occupied = TRUE;
		gamestate[bpr7][bpc7].occupied = TRUE;
		gamestate[bpr8][bpc8].occupied = TRUE;
	
	
		gamestate[wpr1][wpc1].occupied = TRUE;
		gamestate[wpr2][wpc2].occupied = TRUE;
		gamestate[wpr3][wpc3].occupied = TRUE;
		gamestate[wpr4][wpc4].occupied = TRUE;
		gamestate[wpr5][wpc5].occupied = TRUE;
		gamestate[wpr6][wpc6].occupied = TRUE;
		gamestate[wpr7][wpc7].occupied = TRUE;
		gamestate[wpr8][wpc8].occupied = TRUE;
	
		gamestate[brr1][brc1].piece_pos.color = BLACK;
		gamestate[bkr1][bkc1].piece_pos.color = BLACK;
		gamestate[bbr1][bbc1].piece_pos.color = BLACK;
		gamestate[bqr][bqc].piece_pos.color = BLACK;
		gamestate[bkr][bkc].piece_pos.color = BLACK;
		gamestate[bbr2][bbc2].piece_pos.color = BLACK;
		gamestate[bkr2][bkc2].piece_pos.color = BLACK;
		gamestate[brr2][brc2].piece_pos.color = BLACK;
	
		gamestate[wrr1][wrc1].piece_pos.color = WHITE;
		gamestate[wkr1][wkc1].piece_pos.color = WHITE;
		gamestate[wbr1][wbc1].piece_pos.color = WHITE;
		gamestate[wqr][wqc].piece_pos.color = WHITE;
		gamestate[wkr][wkc].piece_pos.color = WHITE;
		gamestate[wbr2][wbc2].piece_pos.color = WHITE;
		gamestate[wkr2][wkc2].piece_pos.color = WHITE;
		gamestate[wrr2][wrc2].piece_pos.color = WHITE;
	
		gamestate[brr1][brc1].piece_pos.name = BROOK1;
		gamestate[bkr1][bkc1].piece_pos.name = BKNIGHT1;
		gamestate[bbr1][bbc1].piece_pos.name = BBISHOP1;
		gamestate[bqr][bqc].piece_pos.name = BQUEEN;
		gamestate[bkr][bkc].piece_pos.name = BKING;
		gamestate[bbr2][bbc2].piece_pos.name = BBISHOP2;
		gamestate[bkr2][bkc2].piece_pos.name = BKNIGHT2;
		gamestate[brr2][brc2].piece_pos.name = BROOK2;
		
		gamestate[wrr1][wrc1].piece_pos.name = WROOK1;
		gamestate[wkr1][wkc1].piece_pos.name = WKNIGHT1;
		gamestate[wbr1][wbc1].piece_pos.name = WBISHOP1;
		gamestate[wqr][wqc].piece_pos.name = WQUEEN;
		gamestate[wkr][wkc].piece_pos.name = WKING;
		gamestate[wbr2][wbc2].piece_pos.name = WBISHOP2;
		gamestate[wkr2][wkc2].piece_pos.name = WKNIGHT2;
		gamestate[wrr2][wrc2].piece_pos.name = WROOK2;
		
		
		gamestate[bpr1][bpc1].piece_pos.color = BLACK;
		gamestate[bpr2][bpc2].piece_pos.color = BLACK;
		gamestate[bpr3][bpc3].piece_pos.color = BLACK;
		gamestate[bpr4][bpc4].piece_pos.color = BLACK;
		gamestate[bpr5][bpc5].piece_pos.color = BLACK;
		gamestate[bpr6][bpc6].piece_pos.color = BLACK;
		gamestate[bpr7][bpc7].piece_pos.color = BLACK;
		gamestate[bpr8][bpc8].piece_pos.color = BLACK;
	
	
		gamestate[wpr1][wpc1].piece_pos.color = WHITE;
		gamestate[wpr2][wpc2].piece_pos.color = WHITE;
		gamestate[wpr3][wpc3].piece_pos.color = WHITE;
		gamestate[wpr4][wpc4].piece_pos.color = WHITE;
		gamestate[wpr5][wpc5].piece_pos.color = WHITE;
		gamestate[wpr6][wpc6].piece_pos.color = WHITE;
		gamestate[wpr7][wpc7].piece_pos.color = WHITE;
		gamestate[wpr8][wpc8].piece_pos.color = WHITE;
	
	
		gamestate[bpr1][bpc1].piece_pos.name = BPAWN1;
		gamestate[bpr2][bpc2].piece_pos.name = BPAWN2;
		gamestate[bpr3][bpc3].piece_pos.name = BPAWN3;
		gamestate[bpr4][bpc4].piece_pos.name = BPAWN4;
		gamestate[bpr5][bpc5].piece_pos.name = BPAWN5;
		gamestate[bpr6][bpc6].piece_pos.name = BPAWN6;
		gamestate[bpr7][bpc7].piece_pos.name = BPAWN7;
		gamestate[bpr8][bpc8].piece_pos.name = BPAWN8;
		
	
		gamestate[wpr1][wpc1].piece_pos.name = WPAWN1;
		gamestate[wpr2][wpc2].piece_pos.name = WPAWN2;
		gamestate[wpr3][wpc3].piece_pos.name = WPAWN3;
		gamestate[wpr4][wpc4].piece_pos.name = WPAWN4;
		gamestate[wpr5][wpc5].piece_pos.name = WPAWN5;
		gamestate[wpr6][wpc6].piece_pos.name = WPAWN6;
		gamestate[wpr7][wpc7].piece_pos.name = WPAWN7;
		gamestate[wpr8][wpc8].piece_pos.name = WPAWN8;
}	


//function to create logical squares
SDL_Rect myRect(int i, int j)
{	
	SDL_Rect rect;
	rect.x = BOX_XPOS + j * (BOX_WIDTH);
	rect.y = BOX_YPOS + i * (BOX_HEIGHT);
	rect.w = BOX_WIDTH;
	rect.h = BOX_HEIGHT;
	
	return rect;
}

//button state printer
void printstate(struct state gamestate[12][8])
{	
	FILE *statefile;
	statefile = fopen("state_game.txt", "w");
	if(statefile == NULL){
		printf("error accesssing file\n");
		return;
	}
	
	fprintf(statefile,"\n\n*******CURRENT STATE OF THE GAME********\n");
	fprintf(statefile,"0:False		1:True		8:Black		9:White\n");
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			fprintf(statefile,"[%d  ,%d  ,%d]\t",gamestate[i][j].occupied,gamestate[i][j].piece_pos.color,gamestate[i][j].piece_pos.name);
		}
		fprintf(statefile,"\n");
	}		
	fprintf(statefile,"\n*****************END******************\n");
	fclose(statefile);
}

//kill color
int killcolor(struct state gamestate[12][8], int lx, int ly)
{
	if(gamestate[lx][ly].piece_pos.color == WHITE)
		return BLACK;
	else 
		return WHITE;
}


//kill piece
void killPiece(struct state gamestate[12][8], int rx, int ry, int lx, int ly)
{
	int killit = gamestate[lx][ly].piece_pos.name;
	printf("killing...   %d   %d\n",lx,ly);
	
	//black ROOK 1
	if(killit == BROOK1)
	{
		//brooktex1 = NULL;
		brr1=10;brc1=0;
	}
	
	//black ROOK 2
	if(killit == BROOK2)
	{
		//brooktex2 = NULL;
		brr2=10;brc2=7;
	}
	
	//white ROOK 1
	if(killit == WROOK1)
	{
		//wrooktex1 = NULL;
		wrr1=8;wrc1=0;
	}
	
	//white ROOK 2
	if(killit == WROOK2)
	{
		//wrooktex2 = NULL;
		wrr2=8;wrc2=7;
	}
	
	//black KNIGHT 1
	if(killit == BKNIGHT1)
	{
		//bknighttex1 = NULL;
		bkr1=10;bkc1=1;
	}
	
	//black KNIGHT 2
	if(killit == BKNIGHT2)
	{
		//bknighttex2 = NULL;
		bkr2=10;bkc2=6;
	}
	
	//white KNIGHT 1
	if(killit == WKNIGHT1)
	{
		//wknighttex1 = NULL;
		wkr1=8;wkc1=1;
	}
	
	//white KNIGHT 2
	if(killit == WKNIGHT2)
	{
		//wknighttex2 = NULL;
		wkr2=8;wkc2=6;
	}
	
	//black BISHOP 1
	if(killit == BBISHOP1)
	{
		//bbishoptex1 = NULL;
		bbr1=10;bbc1=2;
	}
	
	//black BISHOP 2
	if(killit == BBISHOP2)
	{
		//bbishoptex2 = NULL;
		bbr2=10;bbc2=5;
	}
	
	//white BISHOP 1
	if(killit == WBISHOP1)
	{
		//wbishoptex1 = NULL;
		wbr1=8;wbc1=2;
	}
	
	//white BISHOP 2
	if(killit == WBISHOP2)
	{
		//wbishoptex2 = NULL;
		wbr2=8;wbc2=5;
	}
	
	//black QUEEN
	if(killit == BQUEEN)
	{
		//bqueentex = NULL;
		bqr=10;bqc=3;
	}
	
	
	//white QUEEN
	if(killit == WQUEEN)
	{
		//wqueentex = NULL;
		wqr=8;wqc=3;
	}
	
	
	//black KING
	if(killit == BKING)
	{
		//bkingtex = NULL;
		bkr=10;bkc=4;
	}
	
	
	//white KING
	if(killit == WKING)
	{
		//wkingtex = NULL;
		wkr=8;wkc=4;
	}
	
	//white PAWN 1
	if(killit == WPAWN1)
	{
		//wpawntex[0] = NULL;
		wpr1=9;wpc1=0;
	}
	
	//white PAWN 2
	if(killit == WPAWN2)
	{
		//wpawntex[1] = NULL;
		wpr2=9;wpc2=1;
	}
	
	//white PAWN 3
	if(killit == WPAWN3)
	{
		//wpawntex[2] = NULL;
		wpr3=9;wpc3=2;
	}
	
	//white PAWN 4
	if(killit == WPAWN4)
	{
		//wpawntex[3] = NULL;
		wpr4=9;wpc4=3;
	}
	
	//white PAWN 5
	if(killit == WPAWN5)
	{
		//wpawntex[4] = NULL;
		wpr5=9;wpc5=4;
	}
	
	//white PAWN 6
	if(killit == WPAWN6)
	{
		//wpawntex[5] = NULL;
		wpr6=9;wpc6=5;
	}
	
	//white PAWN 7
	if(killit == WPAWN7)
	{
		//wpawntex[6] = NULL;
		wpr7=9;wpc7=6;
	}
	
	//white PAWN 8
	if(killit == WPAWN8)
	{
		//wpawntex[7] = NULL;
		wpr8=9;wpc8=7;
	}
	
	//black PAWN 1
	if(killit == BPAWN1)
	{
		//bpawntex[0] = NULL;
		bpr1=11;bpc1=0;
	}
	
	//black PAWN 2
	if(killit == BPAWN2)
	{
		//bpawntex[1] = NULL;
		bpr2=11;bpc2=1;
	}
	
	//black PAWN 3
	if(killit == BPAWN3)
	{
		//bpawntex[2] = NULL;
		bpr3=11;bpc3=2;
	}
	
	//black PAWN 4
	if(killit == BPAWN4)
	{
		//bpawntex[3] = NULL;
		bpr4=11;bpc4=3;
	}
	
	//black PAWN 5
	if(killit == BPAWN5)
	{
		//bpawntex[4] = NULL;
		bpr5=11;bpc5=4;
	}
	
	//black PAWN 6
	if(killit == BPAWN6)
	{
		//bpawntex[5] = NULL;
		bpr6=11,bpc6=5;
	}
	
	//black PAWN 7
	if(killit == BPAWN7)
	{
		//bpawntex[6] = NULL;
		bpr7=11;bpc7=6;
	}
	
	//black PAWN 8
	if(killit == BPAWN8)
	{
		//bpawntex[7] = NULL;
		bpr8=11;bpc8=7;
	}
	int pcolor = killcolor(gamestate, rx, ry);
	gamestate[lx][ly].occupied = TRUE;
	gamestate[lx][ly].piece_pos.color = pcolor;
	gamestate[lx][ly].piece_pos.name = gamestate[rx][ry].piece_pos.name;
}


int moveThePiece(struct state gamestate[12][8], int rx, int ry, int lx, int ly){
	
	int moved=0;
	
	//for blackROOK1
	if(rx == brr1 && ry == brc1 && bRook(gamestate, rx, ry, lx, ly))
	{	
		if(bRook(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		brr1 = lx;
		brc1 = ly;
		moved=1;
	}
			
	//for blackROOK2
	else if(rx == brr2 && ry == brc2 && bRook(gamestate, rx, ry, lx, ly))
	{	
		if(bRook(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		brr2 = lx;
		brc2 = ly;
		moved=1;
	}
			
	//for whiteROOK1
	else if(rx == wrr1 && ry == wrc1 && bRook(gamestate, rx, ry, lx, ly))
	{	
		if(bRook(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wrr1 = lx;
		wrc1 = ly;
		moved=1;
	}
	
	//for whiteROOK2
	else if(rx == wrr2 && ry == wrc2 && bRook(gamestate, rx, ry, lx, ly))
	{	
		if(bRook(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wrr2 = lx;
		wrc2 = ly;
		moved=1;
	}
	
	//for blackKNIGHT1
	else if(rx == bkr1 && ry == bkc1 && bKnight(gamestate, rx, ry, lx, ly))
	{	
		if(bKnight(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bkr1 = lx;
		bkc1 = ly;
		moved=1;
	}
	
	//for blackKNIGHT2
	else if(rx == bkr2 && ry == bkc2 && bKnight(gamestate, rx, ry, lx, ly))
	{	
		if(bKnight(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bkr2 = lx;
		bkc2 = ly;
		moved=1;
	}
	
	//for whiteKNIGHT1
	else if(rx == wkr1 && ry == wkc1 && bKnight(gamestate, rx, ry, lx, ly))
	{	
		if(bKnight(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wkr1 = lx;
		wkc1 = ly;
		moved=1;
	}
	
	//for whiteKNIGHT2
	else if(rx == wkr2 && ry == wkc2 && bKnight(gamestate, rx, ry, lx, ly))
	{	
		if(bKnight(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wkr2 = lx;
		wkc2 = ly;
		moved=1;
	}
	
	//for blackBISHOP1
	else if(rx == bbr1 && ry == bbc1 && bBishop(gamestate, rx, ry, lx, ly))
	{	
		if(bBishop(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bbr1 = lx;
		bbc1 = ly;
		moved=1;
	}
	
	//for blackBISHOP2
	else if(rx == bbr2 && ry == bbc2 && bBishop(gamestate, rx, ry, lx, ly))
	{	
		if(bBishop(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bbr2 = lx;
		bbc2 = ly;
		moved=1;
	}
	
	//for whiteBISHOP1
	else if(rx == wbr1 && ry == wbc1 && bBishop(gamestate, rx, ry, lx, ly))
	{	
		if(bBishop(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wbr1 = lx;
		wbc1 = ly;
		moved=1;
	}
	
	//for whiteBISHOP2
	else if(rx == wbr2 && ry == wbc2 && bBishop(gamestate, rx, ry, lx, ly))
	{	
		if(bBishop(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wbr2 = lx;
		wbc2 = ly;
		moved=1;
	}
	
	
	//for blackQUEEN
	else if(rx == bqr && ry == bqc && (bRook(gamestate, rx, ry, lx, ly) || bBishop(gamestate, rx, ry, lx, ly)))
	{	
		if(bRook(gamestate, rx, ry, lx, ly) == KILL || bBishop(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bqr = lx;
		bqc = ly;
		moved=1;
	}
	
	//for whiteQUEEN
	else if(rx == wqr && ry == wqc && (bRook(gamestate, rx, ry, lx, ly) || bBishop(gamestate, rx, ry, lx, ly)))
	{	
		if(bRook(gamestate, rx, ry, lx, ly) == KILL || bBishop(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wqr = lx;
		wqc = ly;
		moved=1;
	}
	
	//for blackKING
	else if(rx == bkr && ry == bkc && bKing(gamestate, rx, ry, lx, ly))
	{	
		if(bKing(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bkr = lx;
		bkc = ly;
		moved=1;
	}
	
	//for whiteKING
	else if(rx == wkr && ry == wkc && bKing(gamestate, rx, ry, lx, ly))
	{	
		if(bKing(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wkr = lx;
		wkc = ly;
		moved=1;
	}
	
	
	//for blackPAWN1
	else if(rx == bpr1 && ry == bpc1 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bpr1 = lx;
		bpc1 = ly;
		moved=1;
	}
	
	
	//for blackPAWN2
	else if(rx == bpr2 && ry == bpc2 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bpr2 = lx;
		bpc2 = ly;
		moved=1;
	}
	
	//for blackPAWN3
	else if(rx == bpr3 && ry == bpc3 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bpr3 = lx;
		bpc3 = ly;
		moved=1;
	}
	
	//for blackPAWN4
	else if(rx == bpr4 && ry == bpc4 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bpr4 = lx;
		bpc4 = ly;
		moved=1;
	}
	
	//for blackPAWN5
	else if(rx == bpr5 && ry == bpc5 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bpr5 = lx;
		bpc5 = ly;
		moved=1;
	}
	
	//for blackPAWN6
	else if(rx == bpr6 && ry == bpc6 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bpr6 = lx;
		bpc6 = ly;
		moved=1;
	}
	
	//for blackPAWN7
	else if(rx == bpr7 && ry == bpc7 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bpr7 = lx;
		bpc7 = ly;
		moved=1;
	}
	
	//for blackPAWN8
	else if(rx == bpr8 && ry == bpc8 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		bpr8 = lx;
		bpc8 = ly;
		moved=1;
	}
	
	//for whitePAWN1
	else if(rx == wpr1 && ry == wpc1 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wpr1 = lx;
		wpc1 = ly;
		moved=1;
	}
	
	
	//for whitePAWN2
	else if(rx == wpr2 && ry == wpc2 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wpr2 = lx;
		wpc2 = ly;
		moved=1;
	}
	
	//for whitePAWN3
	else if(rx == wpr3 && ry == wpc3 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wpr3 = lx;
		wpc3 = ly;
		moved=1;
	}
	//for whitePAWN4
	else if(rx == wpr4 && ry == wpc4 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wpr4 = lx;
		wpc4 = ly;
		moved=1;
	}
	
	//for whitePAWN5
	else if(rx == wpr5 && ry == wpc5 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wpr5 = lx;
		wpc5 = ly;
		moved=1;
	}
	
	
	//for whitePAWN6
	else if(rx == wpr6 && ry == wpc6 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wpr6 = lx;
		wpc6 = ly;
		moved=1;
	}
	
	//for whitePAWN7
	else if(rx == wpr7 && ry == wpc7 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wpr7 = lx;
		wpc7 = ly;
		moved=1;
	}
	
	//for whitePAWN8
	else if(rx == wpr8 && ry == wpc8 && bPawn(gamestate, rx, ry, lx, ly))
	{	
		if(bPawn(gamestate, rx, ry, lx, ly) == KILL)
			killPiece(gamestate, rx,ry,lx, ly);
		wpr8 = lx;
		wpc8 = ly;
		moved=1;
	}
			
	return moved;
}


//main function
int main(int argc, char **argv)
{	
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("error initializing SDL %s",SDL_GetError());
		return 1;
	}
	if(TTF_Init()<0){
		printf("error initializing TTF%s",TTF_GetError());
	}
	SDL_Window* win = SDL_CreateWindow("ChessEngine", 
										SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED,
										WINDOW_WIDTH, WINDOW_HEIGHT,0);
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
	
	SDL_Surface* iconsurf = (SDL_Surface*)IMG_Load("resources/logo/logo2.png");
	SDL_SetWindowIcon(win, iconsurf);
	SDL_FreeSurface(iconsurf);
	
	//window size where chessboard(texture) will be drawn
	SDL_Rect winrect;
	winrect.x = 0;
	winrect.y = 0;
	winrect.w = 700;
	winrect.h = 700;
	SDL_Surface* boardsurf = (SDL_Surface*)IMG_Load("resources/boards/board5.png");
	SDL_Texture* boardtex = SDL_CreateTextureFromSurface(rend, boardsurf);
	SDL_FreeSurface(boardsurf);
	
	SDL_Rect siderect;
	siderect.x = 700;
	siderect.y = 0;
	siderect.w = 300;
	siderect.h = 700;
	boardsurf = (SDL_Surface*)IMG_Load("resources/sidebars/sidebar4.jpg");
	SDL_Texture* sidetex = SDL_CreateTextureFromSurface(rend, boardsurf);
	SDL_FreeSurface(boardsurf);
	
	
	
	//msgbox
	SDL_Rect msgrect;
	msgrect.x=730;
	msgrect.y=680;
	
	SDL_Rect gamerect;
	gamerect.x=770;
	gamerect.y=300;
	
	
	SDL_Rect winnerrect;
	winnerrect.x=780;
	winnerrect.y=340;
	
	SDL_Rect newgamerect;
	newgamerect.x=755;
	newgamerect.y=170;
	
	SDL_Rect turnrect;
	turnrect.x=775;
	turnrect.y=450;
	
	TTF_Font* msgfont = TTF_OpenFont("resources/font/OpenSans-Bold.ttf", 14);
	TTF_Font* gamefont = TTF_OpenFont("resources/font/OpenSans-Bold.ttf", 26);
	TTF_Font* winnerfont = TTF_OpenFont("resources/font/OpenSans-Bold.ttf", 24);
	SDL_Color white = {255, 255,255, 0};
	
	SDL_Surface* msgsurf = TTF_RenderText_Blended_Wrapped(msgfont, "This Chess Engine is created by MOHIT", white,300);
	SDL_Texture* msgtex = SDL_CreateTextureFromSurface(rend, msgsurf);
	SDL_QueryTexture(msgtex, NULL, NULL, &msgrect.w, &msgrect.h);
	SDL_FreeSurface(msgsurf);
	
	msgsurf = TTF_RenderText_Blended_Wrapped(gamefont, "GAME OVER", white,300);
	SDL_Texture* gametex = SDL_CreateTextureFromSurface(rend, msgsurf);
	SDL_QueryTexture(gametex, NULL, NULL, &gamerect.w, &gamerect.h);
	SDL_FreeSurface(msgsurf);
	
	
	msgsurf = TTF_RenderText_Blended_Wrapped(winnerfont, "White Wins!", white,300);
	SDL_Texture* whitegametex = SDL_CreateTextureFromSurface(rend, msgsurf);
	SDL_QueryTexture(whitegametex, NULL, NULL, &winnerrect.w, &winnerrect.h);
	SDL_FreeSurface(msgsurf);
	
	msgsurf = TTF_RenderText_Blended_Wrapped(winnerfont, "Black Wins!", white,300);
	SDL_Texture* blackgametex = SDL_CreateTextureFromSurface(rend, msgsurf);
	SDL_QueryTexture(blackgametex, NULL, NULL, &winnerrect.w, &winnerrect.h);
	SDL_FreeSurface(msgsurf);
	
	msgsurf = TTF_RenderText_Blended_Wrapped(winnerfont, "      NewGame      ", white,300);
	SDL_Texture* newgametex = SDL_CreateTextureFromSurface(rend, msgsurf);
	SDL_QueryTexture(newgametex, NULL, NULL, &newgamerect.w, &newgamerect.h);
	SDL_FreeSurface(msgsurf);
	
	msgsurf = TTF_RenderText_Blended_Wrapped(winnerfont, "White's Turn", white,300);
	SDL_Texture* wturntex = SDL_CreateTextureFromSurface(rend, msgsurf);
	SDL_QueryTexture(wturntex, NULL, NULL, &turnrect.w, &turnrect.h);
	SDL_FreeSurface(msgsurf);
	
	
	msgsurf = TTF_RenderText_Blended_Wrapped(winnerfont, "Black's Turn", white,300);
	SDL_Texture* bturntex = SDL_CreateTextureFromSurface(rend, msgsurf);
	SDL_QueryTexture(bturntex, NULL, NULL, &turnrect.w, &turnrect.h);
	SDL_FreeSurface(msgsurf);
	
	
	
	//to create logical squares
	struct state gamestate[12][8];

	int i=0,j=0;	
	for(i=0;i<8;i++)
	{	for(j=0;j<8;j++)
		{	
			gamestate[i][j].rect = myRect(i, j);
			gamestate[i][j].occupied = FALSE;
			gamestate[i][j].piece_pos.color = NULL;
			gamestate[i][j].piece_pos.name = NULL;
		}
	}
	
	int wcr = 8, wcc = 0;
	//white cemetery
	//SDL_Rect wcemetery[3][6];
	for(i=0;i<3;i++)
		for(j=0;j<6;j++){
			if(i <2 || (i==2 && j<4)){
			gamestate[wcr][wcc].rect = myCemRect(i, j);
			gamestate[wcr][wcc].occupied = FALSE;
			gamestate[wcr][wcc].piece_pos.color = NULL;
			gamestate[wcr][wcc].piece_pos.name = NULL;
			if(wcc < 7 && wcr <= 9)wcc++;
			else{
				wcc=0;
				wcr++;
			}	
			}
		}
		
	int bcr = 10, bcc = 0;	
	//black cemetery
	//SDL_Rect bcemetery[3][6];
	for(i=0;i<3;i++)
		for(j=0;j<6;j++){
			if(i >=1 || (i==0 && j<4)){
			gamestate[bcr][bcc].rect = bmyCemRect(i, j);
			gamestate[bcr][bcc].occupied = FALSE;
			gamestate[bcr][bcc].piece_pos.color = NULL;
			gamestate[bcr][bcc].piece_pos.name = NULL;			
			if(bcc < 7 && bcr <= 11)bcc++;
			else{
				bcc=0;
				bcr++;
			}	
			}
		}
	
	
	//creating texture for chess pieces
	pieceTexCreator(rend);
	
	//prerequisite for gameloop
	int close_requested = 0;
	int left_flag = 0, right_flag=1,rect_flag = 0,move_flag = 0,moved = 0, movecolor = WHITE;
	int rx, ry, lx, ly;
	
	//game loop
	while(!close_requested)
	{	
		SDL_Event event;
		
		//to rend chessboard on window
		SDL_RenderCopy(rend, boardtex, NULL, &winrect);
		//sidebar rendering
		SDL_RenderCopy(rend, sidetex, NULL, &siderect);
		SDL_RenderCopy(rend, msgtex, NULL, &msgrect);
		//draw white edges
		SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
		for(i =0;i<8;i++)
			for(j=0;j<8;j++)
				SDL_RenderDrawRect(rend, &gamestate[i][j].rect);
		
		//to change color of square when a piece is selected to move
		if(rect_flag)
		{
			SDL_SetRenderDrawColor(rend, 181, 230, 29, 255);
			SDL_RenderFillRect(rend, &gamestate[rx][ry].rect);
			SDL_SetRenderDrawColor(rend, 0, 128, 0, 255);
			SDL_RenderDrawRect(rend, &gamestate[rx][ry].rect);
		}
		
		pieceRenderer(rend,gamestate);
		
		
		
		if((bkr==10 && bkc==4) || (wkr==8 && wkc==4))
		{	
			right_flag = 0;
			SDL_RenderCopy(rend, gametex, NULL, &gamerect);	
			if((bkr==10 && bkc==4)){
				SDL_RenderCopy(rend, whitegametex, NULL, &winnerrect);	
			}
			else if((wkr==8 && wkc==4)){
				SDL_RenderCopy(rend, blackgametex, NULL, &winnerrect);	
			}
			SDL_RenderCopy(rend, NULL, NULL, &turnrect);	
		}else{
			if(movecolor == WHITE)
				SDL_RenderCopy(rend, wturntex, NULL, &turnrect);
			else if(movecolor == BLACK)
				SDL_RenderCopy(rend, bturntex, NULL, &turnrect);
		}
		//mouse position
		int mouse_x, mouse_y;
        int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
		SDL_Point point;
		point.x = mouse_x;
		point.y = mouse_y;
		if(SDL_PointInRect(&point, &newgamerect)){
			SDL_SetRenderDrawColor(rend, 181, 230, 29, 255);
			SDL_RenderFillRect(rend, &newgamerect);
		}
		SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
		SDL_RenderDrawRect(rend, &newgamerect);
		SDL_RenderCopy(rend, newgametex, NULL, &newgamerect);
		SDL_RenderPresent(rend);
		
		//select the piece
		if(buttons & SDL_BUTTON(SDL_BUTTON_RIGHT) && right_flag)
		{	
			for(i =0;i<8;i++)
				for(j=0;j<8;j++)
					if(SDL_PointInRect(&point, &gamestate[i][j].rect) && gamestate[i][j].occupied == TRUE)
					{
						if(movecolor == gamestate[i][j].piece_pos.color)
						{
							rx=i;ry=j;
							//lx=rx;ly=ry;
							left_flag = 1;
							rect_flag = 1;
							move_flag = 0;
							//printf("rx=%d  ry=%d\n",rx, ry);
						}
					}
		}//closing selecting the element
		
		//select the destination of piece
		if(buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && left_flag)
		{		
			for(i =0;i<8;i++)
				for(j=0;j<8;j++)
					if(SDL_PointInRect(&point, &gamestate[i][j].rect))
					{
						lx=i;ly=j;
						move_flag = 1;
						//printf("lx=%d  ly=%d\n",lx, ly);
					}
		}//closing selecting the destination of element
		
		//moving a piece
		if(move_flag)
		{
			moved = moveThePiece(gamestate, rx, ry, lx, ly);
			rect_flag=0;
			left_flag = 0;
			printstate(gamestate);
			
			if(moved){
				int mycolor = gamestate[rx][ry].piece_pos.color;
				if(mycolor == BLACK)
					movecolor = WHITE;
				else if(mycolor == WHITE)
					movecolor = BLACK;
				
				gamestate[rx][ry].occupied = FALSE;
				gamestate[rx][ry].piece_pos.color = NULL;
				gamestate[rx][ry].piece_pos.name = NULL;
				
				moved = 0;
			}
		}//move the piece end
		
		//new game initialization
		if(buttons & SDL_BUTTON(SDL_BUTTON_LEFT) & SDL_PointInRect(&point, &newgamerect) )
		{	
			//initial position of black pieces
			brr1=0;brc1=0;bkr1=0;bkc1=1;bbr1=0;bbc1=2;bqr=0;bqc=3;bkr=0;bkc=4;bbr2=0;bbc2=5;bkr2=0;bkc2=6;brr2=0;brc2=7;
			//initial position of white pieces
			wrr1=7;wrc1=0;wkr1=7;wkc1=1;wbr1=7;wbc1=2;wqr=7;wqc=3;wkr=7;wkc=4;wbr2=7;wbc2=5;wkr2=7;wkc2=6;wrr2=7;wrc2=7;
			//initial position of black pawns
			bpr1=1;bpc1=0;bpr2=1;bpc2=1;bpr3=1;bpc3=2;bpr4=1;bpc4=3;bpr5=1;bpc5=4;bpr6=1;bpc6=5;bpr7=1;bpc7=6;bpr8=1;bpc8=7;
			//initial position of white pawns
			wpr1=6;wpc1=0;wpr2=6;wpc2=1;wpr3=6;wpc3=2;wpr4=6;wpc4=3;wpr5=6;wpc5=4;wpr6=6;wpc6=5;wpr7=6;wpc7=6;wpr8=6;wpc8=7;
			
			
			left_flag = 0; 
			right_flag=1;
			rect_flag = 0;
			move_flag = 0;
			moved = 0;
			movecolor = WHITE;
			
			for(i=0;i<8;i++)
			{	for(j=0;j<8;j++)
				{
					gamestate[i][j].occupied = FALSE;
					gamestate[i][j].piece_pos.color = NULL;
					gamestate[i][j].piece_pos.name = NULL;
				}
			}
			printstate(gamestate);
		}
		
		
		
		close_requested = 0;
		//to quit when clicked on red cross
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				close_requested = 1;
			}	
			
		}//poll event loop closed
		
		
	}//game loop end
	
	SDL_DestroyTexture(boardtex);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
	
}//main function end
