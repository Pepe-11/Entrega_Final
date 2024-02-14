#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>

#include "Usuario.h"
#include "Menu.h"

using namespace std;


int main(){

    int opcion;
    string nombre;
    string nombreRegistrado;
    string contrasena;
    string correo;
    string rol;
    string facultad;
    int tipo = 0;

    std::vector<std::string> facultadesAdicionales;

    do
    {
        mostrarMenuVisitante();

        if (!(cin >> opcion)){
            cin.clear();                                         // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta

            cout << "\nOpción no válida. Por favor, elige una opción válida.\n";
            continue; // Continúa con la siguiente iteración del bucle
        }

        switch (opcion){

            case 1:

                cout << "\nRegistro...\n\n";
                cout << "Por favor, introduce tu nombre de usuario: ";
                cin >> nombre;
                cout << "Por favor, introduce tu contrasena: ";
                cin >> contrasena;
                cout << "Por favor, introduce tu correo: ";
                cin >> correo;

                while (!CorreoValido(correo)) {
                    cout << "Correo inválido. Por favor, introduce un correo válido: ";
                    cin >> correo;
                }

                do{

                    cout << "Por favor, elija su facultad: \n";
                    cout << "1. Politécnica\n";
                    cout << "2. Medicina\n";
                    cout << "3. Derecho\n";
                    cout << "4. Arte Dramático\n";
                    cout << "5. Veterinaria\n";
                    cout << "6. Especifique su facultad (si no es ninguna de las anteriores):\n";
                    cout << "Ingrese el número correspondiente al estado: ";
                    cin >> tipo;

                } while (tipo < 1 || tipo > 6);

                switch (tipo){

                    case 1:

                        facultad = "Politécnica";

                    break;

                    case 2:

                        facultad = "Medicina";

                    break;

                    case 3:

                        facultad = "Derecho";

                    break;

                    case 4:

                        facultad = "Arte Dramático";

                    break;

                    case 5:

                        facultad = "Veterinaria";

                    break;

                    case 6:

                        cout << "Por favor, introduzca su facultad: ";
                        cin.ignore(); // Ignorar el salto de línea
                        getline(cin, facultad);

                        string facultadNormalizada = normalizarString(facultad);

                            if (find(facultadesAdicionales.begin(), facultadesAdicionales.end(), facultadNormalizada) == facultadesAdicionales.end()) {
                                facultadesAdicionales.push_back(facultadNormalizada);
                            }
                    break;
                }

                registrarUsuario(nombre, contrasena, correo, "Estudiante", facultad);

            break;
        }

    }while(opcion!=2);

}