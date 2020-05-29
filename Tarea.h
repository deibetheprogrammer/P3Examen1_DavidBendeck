#ifndef TAREA_H
#define TAREA_H

#include <string>

using namespace std;

class Empleado;
class Tarea
{
	public:
		
		//CONSTRUCTORS
		Tarea();
		
		Tarea(string,int,int);
		
		//GETTERS
		string getDescripcion();
		int getNivel();
		int getCarga();
		Empleado* getEmpleado();
		
		//SETTERS
		void setEmpleado(Empleado*);
		void setCarga(int);
		
		//DESTRUCTORS
		~Tarea();
		
	protected:
		
		//FIELDS
		string descripcion;
		int nivel;
		int carga;
		Empleado* empleado;
};

#endif
