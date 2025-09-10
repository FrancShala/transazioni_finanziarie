cmake_minimum_required(VERSION 3.16)
project(lib_tests)

# Trova tutti i file .cpp dei test in questa cartella
file(GLOB TEST_SOURCES "*.cpp")

# Aggiungi GoogleTest (devi avere la cartella googletest-main qui dentro)
add_subdirectory(googletest-main)
include_directories(googletest-main/googletest/include)

# Crea l'eseguibile dei test
add_executable(lib_tests
        ${TEST_SOURCES}
        ${CMAKE_SOURCE_DIR}/ContoCorrente.cpp
        ${CMAKE_SOURCE_DIR}/Transazione.cpp
)

# Linka GoogleTest
target_link_libraries(lib_tests
        gtest
        gtest_main
)

# Include directory principali
target_include_directories(lib_tests PRIVATE ${CMAKE_SOURCE_DIR})

enable_testing()
add_test(NAME lib_tests COMMAND lib_tests)
