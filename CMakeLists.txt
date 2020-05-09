cmake_minimum_required(VERSION 3.0)

project(Demo)

set(CMAKE_CXX_FLAGS "-g -Wall")

include_directories(include)

add_subdirectory(src) # AJOUTER CELA 

enable_testing ()
# Télécharge googletest au moment de la configureation
configure_file(CMakeLists.txt.in
               googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Ajout googletest directement au moment de la compilation
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src)

include_directories(${gtest_SOURCE_DIR}/include)
add_subdirectory(tests)

add_test (NAME test_dvector COMMAND test_dvector)
add_test (NAME test_GenerateurParkMiller COMMAND test_GenerateurParkMiller)

