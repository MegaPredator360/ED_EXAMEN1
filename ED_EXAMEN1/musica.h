#ifndef MUSICA_H
#define MUSICA_H

#include "std.h"

class musica
{
protected:
	string Nombre;
	string Artista;
	int Duracion;

public:
	// Constructores
	musica();
	musica(
		string musiNombre,
		string musiArtista,
		int musiDuracion
	);

	// Destructor
	~musica();

	// Getters
	string getNombre();
	string getArtista();
	int getDuracion();

	// Otros Metodos
	string toString() const;
};

#endif // !MUSICA_H