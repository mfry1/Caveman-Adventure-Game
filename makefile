all: final
	
final: main.o utils.o forest.o mountain.o river.o home.o cave.o space.o game.o creature.o caveman.o mammoth.o tiger.o bear.o
	g++ main.o utils.o forest.o mountain.o river.o home.o cave.o space.o game.o creature.o caveman.o mammoth.o tiger.o bear.o -o final

main.o: main.cpp
	g++ -c main.cpp
  
utils.o: utils.cpp
	g++ -c utils.cpp

forest.o: forest.cpp
	g++ -c forest.cpp

mountain.o: mountain.cpp
	g++ -c mountain.cpp
  
river.o: river.cpp
	g++ -c river.cpp
  
home.o: home.cpp
	g++ -c home.cpp
  
cave.o: cave.cpp
	g++ -c cave.cpp
  
space.o: space.cpp
	g++ -c space.cpp
  
game.o: game.cpp
	g++ -c game.cpp
  
creature.o: creature.cpp
	g++ -c creature.cpp
  
caveman.o: caveman.cpp
	g++ -c caveman.cpp
  
mammoth.o: mammoth.cpp
	g++ -c mammoth.cpp
  
bear.o: bear.cpp
	g++ -c bear.cpp
  
tiger.o: tiger.cpp
	g++ -c tiger.cpp
clean: 
	rm *o lab1