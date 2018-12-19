LBT_AlejandroGarcia: LBT_AlejandroGarcia.o avisoFallo.o comentario.o
	g++ -Wall -g LBT_AlejandroGarcia.o avisoFallo.o comentario.o -o LBT_AlejandroGarcia

LBT_AlejandroGarcia.o: LBT_AlejandroGarcia.cpp avisoFallo.h comentario.h
	g++ -Wall -g -c LBT_AlejandroGarcia.cpp

avisoFallo.o: avisoFallo.cpp avisoFallo.h comentario.h
	g++ -Wall -g -c avisoFallo.cpp

comentario.o: comentario.cpp comentario.h
	g++ -Wall -g -c comentario.cpp

run: LBT_AlejandroGarcia
	./LBT_AlejandroGarcia
