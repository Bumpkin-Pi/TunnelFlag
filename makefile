all: client server


# ---------- CLIENT ----------

client: client_main objects utils game camera
	g++ build/client/*.o -o build/client.rar -lSDL2 -pthread


client_main: client/src/main.cpp
	mkdir -p build
	mkdir -p build/client
	g++ -c client/src/main.cpp -o build/client/main.o -lSDL2 -pthread

camera: client/src/camera/camera.cpp client/src/camera/camera.h
	g++ -c client/src/camera/camera.cpp -o build/client/camera.o

game: client/src/game/game.cpp client/src/game/game.h
	g++ -c client/src/game/game.cpp -o build/client/build.o

objects: client/src/objects/localplayer.cpp client/src/objects/localplayer.h client/src/objects/object.cpp client/src/objects/object.h client/src/objects/player.cpp client/src/objects/player.h
	g++ -c client/src/objects/localplayer.cpp -o build/client/localplayer.o
	g++ -c client/src/objects/player.cpp -o build/client/player.o
	g++ -c client/src/objects/object.cpp -o build/client/object.o

utils: client/src/utils/color.cpp client/src/utils/color.h client/src/utils/keyboard.cpp client/src/utils/keyboard.h client/src/utils/vector2.cpp client/src/utils/vector2.h
	g++ -c client/src/utils/color.cpp -o build/client/color.o
	g++ -c client/src/utils/keyboard.cpp -o build/client/keyboard.o
	g++ -c client/src/utils/vector2.cpp -o build/client/vector2.o

# ---------- SERVER ----------