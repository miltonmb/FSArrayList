#include "ADTList.h"
#include "FSArrayList.h"
#include "VSArrayList.h"
#include "object.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;
void print(ADTList*);
int main() {
	int capacidad;
	cout << "Ingrese la capacidad de la lista: ";
	cin >> capacidad;
	char Resp = 'S';
	if (capacidad > 0){
		ADTList* lista = new VSArrayList(capacidad,5);
		while(Resp == 'S' || Resp == 's'){
		cout <<"BIENVENIDO A LA LISTA DE PERSONAS"<<endl;
		cout << "QUE DESEA HACER: "<<endl;
		cout << "1- Agregar persona"<<endl;
		cout << "2- Borrar persona"<<endl;
		cout << "3- Primera persona"<<endl;
		cout << "4- Ultima persona"<<endl;;
		cout << "5- IndexOf"<<endl;
		cout << "6- Obtener una persona"<<endl;
		cout << "7- Obtener capacidad"<<endl;
		cout << "8- Borrar toda la lista"<<endl;
		cout << "9- Imprimir elementos de la lista"<<endl;
		cout << "10- Ver Size"<<endl;
		cout << "11- Ver si la lista esta vacia"<<endl;
		cout << "12- Ver si la lista esta llena"<<endl;
		cout << "13- Comparar dos elementos"<<endl;
		int opcion  = 0;
		cin >> opcion;
			switch(opcion){
				/*Insertar objetos dentro de la lista*/
				case 1:{
					cout << "--INSERT--"<<endl;
					string nombre;
					int edad;
					int pos;
					cout << "Ingrese el nombre: ";
					cin >> nombre;
					cout << "Ingrese la edad: ";
					cin >> edad;
					cout << "Ingrese la posicion: ";
					cin >> pos;
					Person* persona = new Person(nombre,edad);
					if(lista -> insert(persona,pos)){
						cout << "Se agrego con exito!"<<endl;
					}else{
						cout << "Ha ocurrido un error! por favor contacte con el Administrador"<<endl;
					}
					break;
				}
				/*Remover objetos de la lista*/
				case 2:{
					cout << "--REMOVE--"<<endl;
					int posRemove;
					cout << "Ingrese la posicion de la persona que quiere eliminar: ";
					cin >> posRemove;
					if(lista -> remove(posRemove)){
					cout << "Se ha borrado con exito!"<<endl;
					}else{
						cout << "Ha ocurrido un error! por favor contacte con el Administrador"<<endl;
					}
					break;
				}

				/*Obtener el primer objeto dentro de la lista*/
				case 3:{
					cout << "--FIRST--"<<endl;
					Person* temp;
					if(dynamic_cast<Person*>(lista->first())){
						temp = dynamic_cast<Person*>(lista->first());
						cout << temp -> toString()<<endl;
					}
					break;
				}
				/*Obtener el ultimo objeto dentro de la lista*/
				case 4:{
					cout << "--LAST--"<<endl;
					Person* tempLast;
					if(dynamic_cast<Person*>(lista->last())){
						tempLast = dynamic_cast<Person*>(lista->last());
						cout << tempLast -> toString()<<endl;
					}
					break;
				}
				/*Obtener el indice de la lista*/
				case 5:{
					cout << "--INDEXOF--"<<endl;
					Person* tempIndexOf;
					string nameIndex;
					int edadIndex;
					cout << "Ingrese el nombre: ";
					cin >>nameIndex;
					cout << "Ingrese la edad: ";
					cin >>edadIndex;
					Person* tempIndex =  new Person(nameIndex,edadIndex);
					for (int i = 0; i < lista->Size(); ++i){
						if(tempIndexOf = dynamic_cast<Person*>(lista->get(i))){
							tempIndexOf = dynamic_cast<Person*>(lista->get(i));
							if(tempIndexOf -> equals(tempIndex)){
								cout <<"El indice es: "<< lista -> indexOf(tempIndexOf)<<endl;
								break;
							}
						}
					}
					break;
				}
				/*Obtener una persona de una posicion n, dentro de la lista*/
				case 6:{
					cout << "--GET--"<<endl;
					Person* tempGet;
					cout << "Ingrese la poision de la persona que desea obtener: ";
					int posGet; 
					cin >>posGet;
					if(dynamic_cast<Person*>(lista->get(posGet))){
						tempGet = dynamic_cast<Person*>(lista->get(posGet));
						cout << tempGet->toString()<<endl;
					}
					break;
				}
				/*Obtener la capacidad de la lista*/
				case 7:{
					cout << "--CAPACITY--"<<endl;
					cout << "La capacidad es: "<< lista->Capacity()<<endl;
					break;
				}

				/*Limpiar la lista*/
				case 8:{
					cout << "--CLEAR--"<<endl;
					lista ->clear();
					break;
				}

				/*Imprimir todos los elementon dentro de la lista*/
				case 9:{
					print(lista);
					break;
				}

				/*Obtener el size de la lista*/
				case 10:{
					cout << "--SIZE--"<<endl;
					cout << "size: "<<lista->Size()<<endl;
					break;
				}

				case 11:{
					cout << "--ISEMPTY--"<<endl;
						if(lista->isEmpty()){
							cout << "La lista esta vacía"<<endl;
						}
					break;
				}

				case 12:{
					cout << "--ISFULL--"<<endl;
					if(lista ->isFull()){
						cout << "La lista esta llena "<<endl;
					}
					break;
				}

				case 13:{
					cout << "--EQUALS--"<<endl;
					Person* tempUno;
					Person* tempDos;
					int P_uno, P_dos;
					cout << "Indique la posición de la persona 1: ";
					cin >> P_uno;
					cout <<"Indique la posicion de la persona 2: ";
					cin >> P_dos;
					if(dynamic_cast<Person*>(lista->get(P_uno)) && dynamic_cast<Person*>(lista->get(P_dos)) ){
							tempUno = dynamic_cast<Person*>(lista->get(P_uno));
							tempDos = dynamic_cast<Person*>(lista->get(P_dos));
							if(tempUno->equals(tempDos)){
								cout << "Son iguales"<<endl;
							}else{
								cout << "No son iguales"<<endl;
							}
						}
					break;
				}
			}
			cout << "Desea Continuar[s/n]: ";
			cin >> Resp;
		}
		for (int i = 0; i < lista->Size(); ++i){
			lista->remove(i);
		}
		lista->clear();
		delete lista;
	}
}

void print(ADTList* lista){
	cout << "--PRINT--"<<endl;
	Person* tempImp;
	for (int i = 0; i < lista->Size(); ++i){
		if(dynamic_cast<Person*>(lista->get(i))){
				tempImp = dynamic_cast<Person*>(lista->get(i));
				cout <<"i -- "<< i <<tempImp->toString()<<endl;
		}
	}
}