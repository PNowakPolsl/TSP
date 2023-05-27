/**
 * @file Graph.h
 * @author Piotr Nowak (nowakpiotr510@gmail.com)
 * @brief Plik nag³ówkowy grafu
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

struct Graph {
    std::vector<char> cities;
    std::map<std::pair<char, char>, int> map;
};

Graph initGraph(std::vector<char> cities);

void addEdge(Graph& graph, char from, char to, int distance);
