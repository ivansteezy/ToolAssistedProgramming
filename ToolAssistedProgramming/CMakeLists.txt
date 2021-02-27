# CMakeList.txt: archivo del proyecto de CMake de nivel superior, establezca la configuración global
# e incluya los subproyectos aquí.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)

project ("ToolAssistedProgramming")

# Incluya los subproyectos.
add_subdirectory ("ToolAssistedProgramming")
