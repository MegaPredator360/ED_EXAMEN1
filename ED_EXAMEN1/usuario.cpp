#include "usuario.h"

// Constructores
usuario::usuario(): Username("No definido"), Nombre("No definido"), TipoSubscripcion("No definido")
{ }
usuario::usuario(
	string usuaUsername, 
	string usuaNombre, 
	string usuaTipoSubscripcion
) {
	Username = usuaUsername;
	Nombre = usuaNombre;
	TipoSubscripcion = usuaTipoSubscripcion;
}

// Destructores
usuario::~usuario() { }

// Getters
string usuario::getUsername() { return Username; }
string usuario::getNombre() { return Nombre; }
string usuario::getTipoSubscripcion() { return TipoSubscripcion; }

// Setters
void usuario::setTipoSubscripcion(string usuaTipoSubscripcion) { TipoSubscripcion = usuaTipoSubscripcion; }

// Otros Metodos
string usuario::toString() const
{
	stringstream valor;

	valor << "--  Username: " << Username << endl;
	valor << "--  Nombre: " << Nombre << endl;
	valor << "--  Tipo de Subscripcion: " << TipoSubscripcion << endl;
	valor << "----------------------------------------" << endl;

	return valor.str();
}
