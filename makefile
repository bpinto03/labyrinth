CC = gcc
CFLAGS =-ansi -pedantic -Wall
LIBFLAGS = -lMLV
OBJ = main.o Cellule.o Labyrinthe.o Texte.o Union.o Options.o Graphique.o

Labyrinthe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBFLAGS)

main.o: main.c Texte.h Labyrinthe.h Union.h Options.h Graphique.h

Cellule.o: Cellule.c Cellule.h

Labyrinthe.o: Labyrinthe.c Labyrinthe.h Cellule.h Union.h

Texte.o: Texte.c Texte.h Labyrinthe.h

Union.o: Union.c Union.h Cellule.h

Option.o: Options.c Cellule.h

Graphique.o: Graphique.c Graphique.h

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f Labyrinthe
