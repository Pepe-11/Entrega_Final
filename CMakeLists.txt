cmake_minimum_required(VERSION 3.10)
project(TuProyecto)

# Archivos fuente para el ejecutable principal
set(SOURCES_MAIN
    main.cpp
    Usuario.cpp
    menu.cpp
)

# Archivos fuente para las pruebas
set(SOURCES_TESTS
    Tests.cpp
    Usuario.cpp  # Si hay archivos compartidos entre las pruebas y el programa principal
)

# Ejecutable principal
add_executable(${PROJECT_NAME} ${SOURCES_MAIN})

# Ejecutable para las pruebas
add_executable(${PROJECT_NAME}_tests ${SOURCES_TESTS})

# Establece las dependencias para las pruebas
add_dependencies(${PROJECT_NAME}_tests ${PROJECT_NAME})