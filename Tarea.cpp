#include "Tarea.h"

using std::string;


//CONSTRUCTORS
Tarea::Tarea()
{
}

Tarea::Tarea(string descripcion,int nivel, int carga) {
	this->descripcion = descripcion;
	this->nivel = nivel;
	this->carga = carga;
	this->empleado;
	this->empleado = nullptr;
}

//GETTERS
string Tarea::getDescripcion() {
	return descripcion;
}

int Tarea::getNivel() {
	return nivel;
}

int Tarea::getCarga() {
	return carga;
}

Empleado* Tarea::getEmpleado() {
	return empleado;
}

//SETTERS
void Tarea::setEmpleado(Empleado* empleado) {
	this->empleado = empleado;
}

void Tarea::setCarga(int carga) {
	this->carga = carga;
}

//DESTRUCTORS
Tarea::~Tarea()
{
}
