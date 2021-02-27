# CMakeList.txt: proyecto de CMake para ToolAssistedProgramming, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)

# Agregue un origen al ejecutable de este proyecto.
add_executable (ToolAssistedProgramming "EntryPoint.cpp" "EntryPoint.hpp" "FileManager.cpp" "FileManager.hpp")

# TODO: Agregue pruebas y destinos de instalación si es necesario.
