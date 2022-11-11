FILES = ./build/main.o  ./build/Map.o ./build/DeathScreen.o ./build/Enemy.o ./build/Player.o ./build/Menu.o

all: $(FILES)
	g++ $(FILES) -o ./build/app.bin -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio
./build/Map.o: ./src/Map.cpp
	g++ -c ./src/Map.cpp -o ./build/Map.o
./build/DeathScreen.o: ./src/DeathScreen.cpp
	g++ -c ./src/DeathScreen.cpp -o ./build/DeathScreen.o
./build/Enemy.o: ./src/Enemy.cpp
	g++ -c ./src/Enemy.cpp -o ./build/Enemy.o
./build/Player.o: ./src/Player.cpp
	g++ -c ./src/Player.cpp -o ./build/Player.o
./build/Menu.o: ./src/Menu.cpp  
	g++ -c ./src/Menu.cpp -o ./build/Menu.o 
./build/main.o: ./src/main.cpp
	g++ -c ./src/main.cpp -o ./build/main.o
clean:
	rm $(FILES) ./build/app.bin