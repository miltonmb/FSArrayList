list:	ADTList.o FSArrayList.o object.o Person.o main.o
	g++ ADTList.o FSArrayList.o object.o Person.o main.o -o list

main.o:	ADTList.h FSArrayList.h object.h main.cpp Person.h
	g++ -c main.cpp

FSArrayList.o:	ADTList.h FSArrayList.cpp FSArrayList.h
	g++ -c FSArrayList.cpp

ADTList.o:	ADTList.h ADTList.cpp object.h
	g++ -c ADTList.cpp

Person.o:	Person.h Person.cpp object.h
	g++ -c Person.cpp

Object.o:	object.h object.cpp
	g++ -c object.cpp

clean:
	rm -f *.o list