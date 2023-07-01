#include <string>
#include <iostream>
#include <sstream>		// Para stringstream
#include <wchar.h>		// Para caracteres especiales
#include <conio.h>		// Para obtener caracter en formato ASCII
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>
#include <vector>		// Para evitar mostrar listas de reproduccion repetidas

#pragma comment (lib, "winmm.lib") // Vinculará las funciones multimedia de Windows con el programa

// Colores para consola
#define RED     "\033[31m"
#define YELLOW	"\x1B[33m"
#define GREEN	"\x1B[32m"
#define RESET   "\033[0m"

using namespace std;

