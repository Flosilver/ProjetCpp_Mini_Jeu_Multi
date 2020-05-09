LDLIBS := -lsfml-graphics -lsfml-window -lsfml-system

main : Main.o
	g++ Main.o -o main $(LDLIBS)
	
Main.o :
	g++ -c Main.cpp

clean:
	rm -rf *.o
	
rmproper: clean
	rm -rf main
