#ifndef USUARIO_H
#define USUARIO_H

#include "std.h"

class usuario
{
protected:
	string Username;
	string Nombre;
	string TipoSubscripcion;

public:
	// Constructores
	usuario();
	usuario(
		string usuaUsername,
		string usuaNombre,
		string usuaTipoSubscripcion
	);

	// Destructor
	~usuario();

	// Getters
	string getUsername();
	string getNombre();
	string getTipoSubscripcion();

	// Setters
	void setUsername(string usuaUsername);
	void setNombre(string usuaNombre);
	void setTipoSubscripcion(string usuaTipoSubscripcion);

	// Otros Metodos
	string toString() const;
	string archivoUsuario();
};

#endif // !USUARIO_H