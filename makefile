lista:	ADTList.o VSArrayList.o FSArrayList.o object.o Person.o main.o
	g++ ADTList.o VSArrayList.o FSArrayList.o object.o Person.o main.o -o lista

main.o:	ADTList.h VSArrayList.h object.h main.cpp Person.h
	g++ -c main.cpp

VSArrayList.o:	ADTList.h VSArrayList.cpp VSArrayList.h
	g++ -c VSArrayList.cpp

FSArrayList.o:	ADTList.h FSArrayList.cpp FSArrayList.h
	g++ -c FSArrayList.cpp

ADTList.o:	ADTList.h ADTList.cpp object.h
	g++ -c ADTList.cpp

Person.o:	Person.h Person.cpp object.h
	g++ -c Person.cpp

Object.o:	object.h object.cpp
	g++ -c object.cpp

clean:
	rm -f *.o lista