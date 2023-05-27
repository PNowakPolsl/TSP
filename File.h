/**
 * @file File.h
 * @author Piotr Nowak (nowakpiotr510@gmail.com)
 * @brief Plik nag³ówkowy operacji na plikach
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "TSP.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

Graph loadGraph(std::string graphfile);

std::vector<std::string> split(std::string str);

void saveGraph(std::vector<std::pair<std::vector<char>, int>> tsp, std::string filename);