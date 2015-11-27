#export LD_LIBRARY_PATH=lib/:lib/Box2D-2.3.0/lib-Linux64/:lib/SFML-2.2/lib-Linux64:lib/glew-1.10/

CC = g++
HDIR = ./include
SDIR = ./src
ODIR = ./obj
IDIR = -I./lib/CGF/include
IDIR += -I./lib/CGF/include/tmx
IDIR += -I./lib/CGF/include/pugixml
IDIR += -I./lib/Box2D-2.3.0/include
IDIR += -I./lib/SFML-2.2/include

LIBDIR = -L ./lib 
LIBDIR += -L ./lib/Box2D-2.3.0/lib-Linux64/ 
LIBDIR += -L ./lib/SFML-2.2/lib-Linux64 
LIBDIR += -L ./lib/glew-1.10

CFLAGS = -std=c++11 $(LIBDIR) -I$(HDIR) $(IDIR) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lBox2D -lCGF-Linux -lz 

_DEPS = Banana.h Enemy.h Item.h Map.h MenuState.h Player.h PlayState.h State.h
DEPS  = $(patsubst %,$(HDIR)/%,$(_DEPS))

_OBJ = Main.o Enemy.o Item.o Map.o MenuState.o Player.o PlayState.o State.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	LD_LIBRARY_PATH=lib/:lib/Box2D-2.3.0/lib-Linux64/:lib/SFML-2.2/lib-Linux64:lib/glew-1.10/ $(CC) -c -o $@ $< $(CFLAGS)

bananamen.game: $(OBJ)
	LD_LIBRARY_PATH=lib/:lib/Box2D-2.3.0/lib-Linux64/:lib/SFML-2.2/lib-Linux64:lib/glew-1.10/ $(CC) -o $@ $^ $(CFLAGS)
.PHONY: clean

all: bananamen.game
run: all
	LD_LIBRARY_PATH=lib/:lib/Box2D-2.3.0/lib-Linux64/:lib/SFML-2.2/lib-Linux64:lib/glew-1.10/ ./bananamen.game

clean:
	rm -f $(ODIR)/*.o
	rm -f bananamen.game
