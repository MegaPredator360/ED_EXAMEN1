#include "musica.h"

// Constructores
musica::musica(): Nombre("No definido"), Artista("No definido"), Duracion(0)
{ }
musica::musica(
	string musiNombre,
	string musiArtista,
	int musiDuracion
) {
	Nombre = musiNombre;
	Artista = musiArtista;
	Duracion = musiDuracion;
}

// Destructor
musica::~musica() { }

// Getters
string musica::getNombre() { return Nombre; }
string musica::getArtista() { return Artista; }
int musica::getDuracion() { return Duracion; }

// Setters
void musica::setNombre(string musiNombre) { Nombre = musiNombre; }
void musica::setArtista(string musiArtista) { Artista = musiArtista; }
void musica::setDuracion(int musiDuracion) { Duracion = musiDuracion; }

string musica::toString() const
{
	stringstream valor;

	valor << "--  Nombre de Canción: " << Nombre << endl;
	valor << "--  Artista: " << Artista << endl;
	valor << "--  Duración: " << Duracion << " segundos" << endl;
	valor << "----------------------------------------" << endl;

	return valor.str();
}
