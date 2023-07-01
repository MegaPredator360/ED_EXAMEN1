#ifndef LISTAREPRODUCCION_H
#define LISTAREPRODUCCION_H

#include "lista.h"
#include "usuario.h"
#include "musica.h"

class listaReproduccion
{
protected:
	string Nombre;
	musica* _musica;
	usuario* _usuario;

public:
	// Constructor
	listaReproduccion(string listNombre, usuario* listUsuario, musica* listMusica);

	// Destructor
	~listaReproduccion();

	// Getters
	string getNombre();
	usuario* getUsuario();
	musica* getMusica();

	// Setters
	void setUsuario(usuario* listUsuario);
	void setMusica(musica* listMusica);
	void setNombre(string listNombre);

	// Otros Metodos
	string toString() const;
};

#endif // !LISTAREPRODUCCION_H