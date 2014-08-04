CC = g++

revLinkedList.exe : revLinkedList.o
	$(CC) -o revLinkedList.exe revLinkedList.o

revLinkedList.o : revLinkedList.cc
	$(CC) -c revLinkedList.cc

clean:
	rm *.o *.exe

