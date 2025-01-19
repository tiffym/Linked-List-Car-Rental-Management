Linked-List-Car-Rental-Management: main.o functions.o
		gcc -Wall -std=c99 main.o functions.o -o Linked-List-Car-Rental-Management

main.o: main.c main.h
		gcc -Wall -std=c99 -c main.c

functions.o: functions.c main.h
		gcc -Wall -std=c99 -c functions.c

clean:
		rm -f *.o Linked-List-Car-Rental-Management

