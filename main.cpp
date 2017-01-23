#include "ADTList.h"
#include "FSArrayList.h"
#include "object.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main() {
	int capacidad;
	cout << "Ingrese la capacidad de la lista: ";
	cin >> capacidad;
	char Resp = 'S';
	if (capacidad > 0){
		FSArrayList* lista = new FSArrayList(capacidad);
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
		int opcion  = 0;
		cin >> opcion;
			switch(opcion){
				case 1:{
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

				case 2:{
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

				case 3:{
					Person* temp;
					if(dynamic_cast<Person*>(lista->first())){
						temp = dynamic_cast<Person*>(lista->first());
						cout << temp -> toString()<<endl;
					}
					break;
				}

				case 4:{
					Person* tempLast;
					if(dynamic_cast<Person*>(lista->last())){
						tempLast = dynamic_cast<Person*>(lista->last());
						cout << tempLast -> toString()<<endl;
					}
					break;
				}

				case 5:{
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
								cout <<"El indice es: "<< lista -> indexOf(tempIndexOf);
								break;
							}
						}
					}
					break;
				}

				case 6:{
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

				case 7:{
					cout << "La capacidad es: "<< lista->Capacity()<<endl;
					break;
				}

				case 8:{
					lista ->clear();
					break;
				}

				case 9:{
					Person* tempImp;
					for (int i = 0; i < lista->Size(); ++i){
						if(dynamic_cast<Person*>(lista->get(i))){
							tempImp = dynamic_cast<Person*>(lista->get(i));
							cout << tempImp->toString()<<endl;
						}
					}
					break;
				}

				case 10:{
					cout << "size: "<<lista->Size()<<endl;
					break;
				}
			}
			cout << "Desea Continuar[s/n]: ";
			cin >> Resp;
		}
		delete lista;
	}
}