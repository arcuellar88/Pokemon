//
// Created by Alejandro Rodriguez Cuellar on 17/09/25.
//
// Utility.cpp

#include "Utility.hpp"
#include <iostream>
#include <limits>

using namespace std;

void Utility :: clear_console() {
    system("clear");
}

void Utility :: wait_for_enter() {
    cin.get();
}

void Utility :: clear_input_buffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}