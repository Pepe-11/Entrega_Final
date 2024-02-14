#include <cassert> // Necesario para assert
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <limits>

#include "Usuario.h"

void limpiarArchivoUsuariosTest() {
    ofstream archivo("usuarios_test.txt", ios::trunc);
    archivo.close();
}

void testVerificarExistenciaUsuario_UsuarioExiste() {
    limpiarArchivoUsuariosTest();
    ofstream archivo("usuarios_test.txt");
    archivo << "usuario_existente,contraseña,correo,rol,facultad\n";
    archivo.close();
    assert(verificarExistenciaUsuario("usuario_existente", "usuarios_test.txt") == true);
}

void testVerificarExistenciaUsuario_UsuarioNoExiste() {
    limpiarArchivoUsuariosTest();
    ofstream archivo("usuarios_test.txt");
    archivo << "usuario_existente,contraseña,correo,rol,facultad\n";
    archivo.close();
    assert(verificarExistenciaUsuario("usuario_no_existente", "usuarios_test.txt") == false);
}

void testRegistrarUsuario_UsuarioNuevo() {
    limpiarArchivoUsuariosTest();
    registrarUsuario("nuevo_usuario", "contraseña", "correo", "rol", "facultad", "usuarios_test.txt");
    ifstream archivoVerificar("usuarios_test.txt");
    string contenido;
    getline(archivoVerificar, contenido);
    assert(contenido == "nuevo_usuario,contraseña,correo,rol,facultad");
    archivoVerificar.close();
}

void testRegistrarUsuario_UsuarioExistente() {
    limpiarArchivoUsuariosTest();
    // Primero, registra un usuario para asegurarte de que exista
    registrarUsuario("usuario_existente", "contraseña", "correo", "rol", "facultad", "usuarios_test.txt");

    // Redirecciona el stream de salida
    stringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());

    // Intenta registrar el mismo usuario de nuevo
    registrarUsuario("usuario_existente", "contraseña", "correo", "rol", "facultad", "usuarios_test.txt");
    
    // Restaura el stream de salida original
    cout.rdbuf(old);

    // Comprueba si el mensaje esperado está en el buffer
    assert(buffer.str().find("El usuario ya existe") != string::npos);
}

int main() {

    testVerificarExistenciaUsuario_UsuarioExiste();
    testVerificarExistenciaUsuario_UsuarioNoExiste();
    testRegistrarUsuario_UsuarioNuevo();
    testRegistrarUsuario_UsuarioExistente();

    cout << "TODAS LAS PRUEBAS HAN SIDO PASADAS CON ÉXITO. ENHORABUENA!!!" << endl;
    
    return 0;
}