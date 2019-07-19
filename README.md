# chess
A GUI based chess application created using SDL (as a learning project)



NOTE: you need SDL2, SDL2-devel, SDL2_ttf, SDL2_ttf-devel, SDL2_image and SDL2_image-devel libraries pre-installed for this program to compile.
If you are using CentOS, just use yum to install these libraries

to compile
gcc -c rook.c -o rook.o
gcc -c pawn.c -o pawn.o
gcc -c king.c -o king.o
gcc -c bishop.c -o bishop.o
gcc -c knight.c -o knight.o

ar rvs libpieces.a rook.o bishop.o knight.o pawn.o king.o

gcc cfinal.c libpieces.a -o cfinal -lSDL2 -lSDL2_image -lSDL2_ttf

cfinal.exe file must have been created

Use Right click to select a Piece
    Left click to move it to desired location on the chess board.
    
