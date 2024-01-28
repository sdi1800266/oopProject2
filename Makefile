CC = g++
CFLAGS = -std=c++11 -Wall

all: menu main

menu: person.o secretary.o student.o professor.o course.o menu.o
	$(CC) $(CFLAGS) $^ -o $@

main: person.o secretary.o student.o professor.o course.o main.o
	$(CC) $(CFLAGS) $^ -o $@

person.o: person.cpp person.h semestertype.h
	$(CC) $(CFLAGS) -c person.cpp

secretary.o: secretary.cpp secretary.h person.h semestertype.h
	$(CC) $(CFLAGS) -c secretary.cpp

student.o: student.cpp student.h person.h semestertype.h
	$(CC) $(CFLAGS) -c student.cpp

professor.o: professor.cpp professor.h person.h semestertype.h
	$(CC) $(CFLAGS) -c professor.cpp

course.o: course.cpp course.h person.h semestertype.h
	$(CC) $(CFLAGS) -c course.cpp

menu.o: menu.cpp person.h secretary.h student.h professor.h semestertype.h
	$(CC) $(CFLAGS) -c menu.cpp

main.o: main.cpp person.h secretary.h student.h professor.h semestertype.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o menu main
