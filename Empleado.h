#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
using std::string;

class Tarea;
class Empleado
{
	public:
		//CONSTRUCTORS
		Empleado();
		
		Empleado(string,int,int,int,int);
		
		//GETTERS
		string getNombre();
		int getEdad();
		int getNivel();
		int getHabilidad();
		int getPereza();
		Tarea* getTarea();
		
		//SETTERS
		void setTarea(Tarea*);
		
		//DESTRUCTORS
		~Empleado();
		
	protected:
		
		//FIELDS
		string nombre;
		int edad;
		int nivel;
		int habilidad;
		int pereza;
		Tarea* tarea;
		
};

#endif
