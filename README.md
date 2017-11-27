# chess
a graphical chess application created using SDL (as a learning project)

to compile
gcc -c rook.c -o rook.o<br/>
gcc -c pawn.c -o pawn.o<br/>
gcc -c king.c -o king.o<br/>
gcc -c bishop.c -o bishop.o<br/>
gcc -c knight.c - o knight.o<br/>

ar rvs libpieces.a rook.o bishop.o knight.o pawn.o king.o<br/>

gcc cfinal8.c libpieces.a -o cfinal8 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf<br/>

cfinal.exe file must have been created
