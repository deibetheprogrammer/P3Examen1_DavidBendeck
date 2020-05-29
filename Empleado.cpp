#include "Empleado.h"

using std::string;

//CONSTRUCTORS
Empleado::Empleado()
{
}

Empleado::Empleado(string nombre,int edad,int nivel ,int habilidad,int pereza) {
	this->nombre = nombre;
	this->edad = edad;
	this->nivel = nivel;
	this->habilidad = habilidad;
	this->pereza = pereza;
	this->tarea = nullptr;
}

//GETTERS
string Empleado::getNombre() {
	return nombre;
}

int Empleado::getEdad() {
	return edad;
}

int Empleado::getNivel() {
	return nivel;
}

int Empleado::getHabilidad() {
	return habilidad;
}

int Empleado::getPereza() {
	return pereza;
}

Tarea* Empleado::getTarea() {
	return tarea;
}

//SETTERS
void Empleado::setTarea(Tarea* tarea) {
	this->tarea = tarea;
}

//DESTRUCTORS
Empleado::~Empleado()
{
	
}
