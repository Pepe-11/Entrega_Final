#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>
#include <map>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

#include "Usuario.h"
#include "Menu.h"

using namespace std;

// Ruta al archivo de usuarios
const string archivoUsuarios = "archivoUsuarios.txt";

// registarUsuario
void registrarUsuario(const string& nombre, const string& pwd, const string& correo, const string& rol, const string& facultad, const string& nombreArchivo)
{
    if (verificarExistenciaUsuario(nombre, nombreArchivo))
    {
        cout << "\nEl usuario ya existe." << endl;
        return;
    }

    ofstream archivo(nombreArchivo, ios::app);

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return;
    }

    archivo << nombre << "," << pwd << "," << correo << "," << rol << "," << facultad << endl;
    archivo.close();
    cout << "\nUsuario registrado." << endl;
}

bool verificarExistenciaUsuario(const string &nombre, const string &archivoUsuarios) {

    ifstream archivo(archivoUsuarios);

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);
        if (nombreUsuarioEnArchivo == nombre)
        {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

bool CorreoValido(const string &correo){
    size_t arrobaPos = correo.find('@');
    size_t puntoPos = correo.find('.', arrobaPos);

    // Verificar que el correo contiene '@' y un punto después del '@'
    if (arrobaPos == string::npos || puntoPos == string::npos || puntoPos <= arrobaPos){
        return false;
    }

        // Verificar la longitud del correo
    if (correo.empty() || correo.length() > 255){
        return false;
    }

    return true;
}

string normalizarString(const string& str) {

    map<string, char> equivalencias = {{"á", 'a'}, {"é", 'e'}, {"í", 'i'}, {"ó", 'o'}, {"ú", 'u'},
                                       {"Á", 'a'}, {"É", 'e'}, {"Í", 'i'}, {"Ó", 'o'}, {"Ú", 'u'}};

    string normalizado;
    for (char c : str) {
        string c_str(1, c);  // Convierte el char a un string de un solo carácter
        if (equivalencias.find(c_str) != equivalencias.end()) {
            normalizado += equivalencias[c_str];
        } else if (isalpha(c)) {
            normalizado += tolower(c);
        } else {
            normalizado += c;
        }
    }
    return normalizado;
}