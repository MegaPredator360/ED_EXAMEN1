#include "listaReproduccion.h"

class Validaciones
{
public:
	// Funciones para datos
	string ingresarNumeros();
	string confirmacionDefS();
	string confirmacionDefN();

	// Funciones para validar existencia de datos
	void mostrarUsuarios(iteradorLista<usuario>* IteradorUsuario);
	bool verificarUsername(iteradorLista<usuario>* IteradorUsuario, string Username);
	bool verificarLista(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string Username, string NombreLista);
	bool verificarLista2(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string NombreLista);
	bool verificarCancion(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string NombreLista, string Cancion);
	bool contarCanciones(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string Username, string NombreLista);
	usuario* obtenerUsuario(iteradorLista<usuario>* IteradorUsuario, string Username);
	nodo<listaReproduccion>* borrarCancion(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string NombreLista, string NombreCancion);
	void mostrarListasCreadas(iteradorLista<listaReproduccion>* IteradorListaReproduccion);
	bool mostrarListasUsuario(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string Username);
	void obtenerLista(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string NombreLista);
	void obtenerDuracionLista(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string NombreLista);
};