#include <iostream>
#include "Empleado.h"
#include "Tarea.h"
#include <Vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::cout;
using std::cin;
using std::endl;
using std::getline;

//Funcion que realiza la simulaci�n
void simulacion(vector<Empleado>, vector<Tarea*>);

int main(int argc, char** argv) {
	
	vector<Empleado> empleados;
	vector<Tarea*> tareas;
	
	bool loop = true;
	while(loop) {
	
		cout<<"********MENU********" << endl
			<<"1) Contratar empleado" << endl
			<<"2) Despedir empleado" << endl
			<<"3) Listar empleados" << endl
			<<"4) Crear tarea" << endl
			<<"5) Listar tareas" << endl
			<<"6) Inciciar proyecto" << endl
			<<"7) Salir"
			<<"Su eleccion: ";
	
		int opcion;
		cin >> opcion;
	
		while (!cin || (opcion < 1 && opcion > 7)) {
			cin.clear ();    // Restore input stream to working state
    		cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 	cout << "Por favor, ingrese una opcion valida: ";
    		cin >> opcion; 
		}
		
		switch(opcion) {
			case 1: {
				
				cout << "***CONTRATAR EMPLEADO***" << "\n\n"
					 << "Ingrese un nombre: ";
				string nombre;
				cin >> nombre;
				
				//EDAD
				cout << "Ingrese la edad: ";
				int edad;
				cin >> edad;
				
				//validacion
				while (!cin || (edad < 18 || edad > 80)) {
					cin.clear ();    // Restore input stream to working state
    				cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 			cout << "Por favor, ingrese una edad entre 18 y 80";
    				cin >> edad; 
				}
				
				//NIVEL
				cout << "Ingrese un nivel: " << endl
					 << "1) Bajo" << endl
					 << "2) Medio" << endl
					 << "3) Alto" << endl
					 << "Nivel : ";
				int nivel;
				cin >> nivel;
				
				//validaci�n
				while (!cin || (nivel < 1 && nivel > 3)) {
					cin.clear ();    // Restore input stream to working state
    				cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 			cout << "Por favor, ingrese una opcion valida: ";
    				cin >> nivel; 
				}
				
				//HABILIDAD
				cout << "Ingrese la habilidad: ";
				int habilidad;
				cin >> habilidad;
				
				//validacion
				while (!cin || (habilidad < 1 || habilidad > 100)) {
					cin.clear ();    // Restore input stream to working state
    				cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 			cout << "Por favor, ingrese una edad entre 1 y 100";
    				cin >> habilidad; 
				}
				
				//PEREZA
				cout << "Ingrese la pereza: ";
				int pereza;
				cin >> pereza;
				
				//validacion
				while (!cin || (pereza < 1 || pereza > 100)) {
					cin.clear ();    // Restore input stream to working state
    				cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 			cout << "Por favor, ingrese una edad entre 1 y 100";
    				cin >> pereza; 
				}
				
				//Creaci�n de nuevo empleado
				empleados.push_back(*(new Empleado(nombre,edad,nivel,habilidad,pereza)));
				
				
				break;
			}
			case 2: {
				
				break;
			}
			case 3: {
				
				break;
			}
			case 4: {
				
				cout << "***CREAR TAREA***" << "\n\n"
					 << "Ingrese una descripcion: ";
				string descripcion;
				getline(cin,descripcion);
				
				//NIVEL
				cout << "Ingrese un nivel: " << endl
					 << "1) Bajo" << endl
					 << "2) Medio" << endl
					 << "3) Alto" << endl
					 << "Nivel : ";
				int nivel;
				cin >> nivel;
				
				//validaci�n
				while (!cin || (nivel < 1 && nivel > 3)) {
					cin.clear ();    // Restore input stream to working state
    				cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 			cout << "Por favor, ingrese una opcion valida: ";
    				cin >> nivel; 
				}
				
				//CARGA
				cout << "Ingrese una carga: ";
				int carga;
				cin >> carga;
				
				while (!cin || carga < 1) {
					cin.clear ();    // Restore input stream to working state
    				cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 			cout << "Por favor, ingrese una cantida mayor a 0: ";
    				cin >> carga; 
				}
				
				//Creacion de una nueva tarea
				tareas.push_back(new Tarea(descripcion,nivel,carga));
				
				break;
			}
			case 5: {
				
				break;
			}
			case 6: {
				
				break;
			}
			case 7: {
				cout << "Saliendo ...";
				loop = false;
				break;
			}
		}
	}
	return 0;
	
}

//Funcion que realiza la simulacion
void simulacion(vector<Empleado> empleados, vector<Tarea*> &tareas) {
	
	srand (time(0));
	
	//Estimacion de la duracion del proyecto
	int N = 0;
	for(int i = 0; i < tareas.size(); i++) {
		N += tareas[i]->getCarga();
	}
	
	int dias = N + N*0.20;
	
	//Tareas en ejecucion
	int enProgreso = 0;
	
	//Empleados perezosos
	int perezosos = 0;
	
	//Empleados que fallaron
	int fallaron = 0;
	
	//Empleados que lograron
	int lograron = 0;
	
	//SIMULACION
	while(tareas.size() > 0 || enProgreso > 0) {
		
		
		cout << "\n\n"
		 	 << "Dias restantes para finalizar el proyecto: " << dias
		 	 << "\n\n"
		 	 << "----------------------------------------------" << endl
		 	 << "1) Siguiente dia" << endl
		 	 << "2) Generar reporte" << endl
		 	 << "3) Salir" << endl
		 	 << "Su opcion: ";
		int opcion;
		cin >> opcion;
		 	 
		while (!cin || (opcion < 1 && opcion > 3)) {
			cin.clear ();    // Restore input stream to working state
    		cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 	cout << "Por favor, ingrese una opcion valida: ";
    		cin >> opcion; 
		}	
		
		switch(opcion) {
			case 1: {
				
				//ASIGNAR TAREAS
				for (int i = 1; i < 4; i++) {
					for(int j = 0; j < empleados.size(); j++) {
						if(empleados[j].getNivel() == i && empleados[j].getTarea() == nullptr) {
							for(int k = 0; k < tareas.size(); k++) {
								if(tareas[k]->getNivel() <= i) {
									empleados[j].setTarea(tareas[k]);
									tareas.erase(tareas.begin()+k);
								}
							}
						}
					}
				}
				
				//EJECUCION DE TAREAS
				for(int i = 0; i < empleados.size(); i++) {
					
				}
				
				break;
			}
			case 2: {
				
				cout << "***REPORTE***" << endl
					 << "Tareas en el backlog: " << tareas.size() << endl
					 << "Tareas en progreso: " << enProgreso << endl
					 << "Empleados perezosos: " << perezosos << endl
					 << "Empleados que fallaron: " << fallaron << endl
					 << "Empleados que lograron el dia: " << lograron << endl;
				
				break;
			}
			case 3: {
				
				break;
			}
		}
		
	}
	
	
}


