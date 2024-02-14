#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

struct Usuario {
    string nombreUsuario;
    string contrasena;
    string rol; // Puede ser "visitante", "registrado", "director academico" u "organizador"
    string correo;
    string facultad;

};

    bool verificarExistenciaUsuario(const string &nombre, const string &nombreArchivo);
    void registrarUsuario(const string& nombre, const string& pwd, const string& correo, const string& rol, const string& facultad, const string& nombreArchivo = "archivoUsuarios.txt");    void eliminarUsuario(const string& nombre);
    bool CorreoValido(const string &correo);
    string normalizarString(const string& str);

#endif // USUARIO_H