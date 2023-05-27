/**
 * @file TSP.h
 * @author Piotr Nowak (nowakpiotr510@gmail.com)
 * @brief Plik nag³ówkowy TSP
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <vector>
#include <set>
#include "Graph.h"

std::vector<std::pair<std::vector<char>, int>> TSP(Graph graph, int population_size, int generations);

std::vector<char> crossover(std::vector<char>& parent1, std::vector<char>& parent2);

std::vector<char> generateRoute(Graph graph);

int calcFitness(std::vector<char> route, Graph graph);

void mutate(std::vector<char>& route);

std::pair<std::vector<char>, int> findBestRoute(std::vector<std::pair<std::vector<char>, int>> population);
