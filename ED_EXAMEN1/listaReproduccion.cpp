#include "listaReproduccion.h"

// Constructor
listaReproduccion::listaReproduccion(
	string listNombre, 
	usuario* listUsuario, 
	musica* listMusica
) {
	setNombre(listNombre);
	setUsuario(listUsuario);
	setMusica(listMusica);
}

// Destructor
listaReproduccion::~listaReproduccion() { }

// Getters
string listaReproduccion::getNombre() { return Nombre; }
usuario* listaReproduccion::getUsuario() { return _usuario; }
musica* listaReproduccion::getMusica() { return _musica; }

// Setters
void listaReproduccion::setUsuario(usuario* listUsuario) { _usuario = listUsuario; }
void listaReproduccion::setMusica(musica* listMusica) { _musica = listMusica; }
void listaReproduccion::setNombre(string listNombre) { Nombre = listNombre; }

// Otros Metodos
string listaReproduccion::toString() const
{
	stringstream valor;

	valor << "--  Lista de Reproducción: " << Nombre << endl;
	valor << "--  Creado por: " << _usuario -> getUsername() << endl;
	valor << "----------------------------------------" << endl;

	return valor.str();
}
