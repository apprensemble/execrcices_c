##Makefile de debutant

menu : ls.o menu.o main_menu.o
	gcc -o menu menu.o main_menu.o ls.o
main_menu.o : main_menu.c menu.h
	gcc -c -O3 main_menu.c
menu.o : menu.c menu.h
	gcc -c -O3 menu.c
ls.o : ls.c ls.h
	gcc -c -O3 ls.c
clean : 
	rm menu.o main_menu.o menu
