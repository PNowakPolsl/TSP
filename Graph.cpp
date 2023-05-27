/**
 * @file Graph.cpp
 * @author Piotr Nowak (nowakpiotr510@gmail.com)
 * @brief Funkcje odpowiedzialne za graf
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Graph.h"

 /**
  * @brief Inicjalizacja grafu
  *
  * @param index
  * @param cities
  * @return Graph
  */
Graph initGraph(std::vector<char> cities) {
    Graph graph;
    graph.cities = cities;

    return graph;
}

/**
 * @brief Dodawanie krawêdzi grafu (pojedyncze po³¹czenia)
 *
 * @param graph
 * @param from
 * @param to
 * @param distance
 */
void addEdge(Graph& graph, char from, char to, int distance) {
    graph.map[std::make_pair(from, to)] = distance;
}
