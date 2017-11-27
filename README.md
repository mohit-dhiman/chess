# chess
a graphical chess application created using SDL (as a learning project)

to compile
gcc -c rook.c -o rook.o
gcc -c pawn.c -o pawn.o
gcc -c king.c -o king.o
gcc -c bishop.c -o bishop.o
gcc -c knight.c - o knight.o

ar rvs libpieces.a rook.o bishop.o knight.o pawn.o king.o

gcc cfinal8.c libpieces.a -o cfinal8 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

cfinal.exe file must have been created
