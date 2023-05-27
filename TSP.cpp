/**
 * @file TSP.cpp
 * @author Piotr Nowak (nowakpiotr510@gmail.com)
 * @brief Funkcje odpowiedzialne za rozwi¹zanie TSP
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "TSP.h"

 /**
  * @brief Funkcja obliczaj¹ca fitness danej trasy
  *
  * @param route
  * @param graph
  * @return int
  */
int calcFitness(std::vector<char> route, Graph graph) {
    int fitness = 0;

    for (int i = 0; i < route.size(); i++) {
        int length = graph.map[std::make_pair(route[i], route[i + 1])];
        if (length == -1) return INT_MAX;
        fitness += length;
    }

    return fitness;
}

/**
 * @brief Funkcja generuje losowe œcie¿ki do populacji
 *
 * @param graph
 * @return std::vector<char>
 */
std::vector<char> generateRoute(Graph graph) {
    std::vector<char> path = graph.cities;
    std::random_shuffle(path.begin(), path.end());
    return path;
}

/**
 * @brief Funkcja odpowiadaj¹ca za krzy¿owanie
 *
 * @param parent1
 * @param child1
 * @param parent2
 * @return std::vector<char>
 */
std::vector<char> crossover(std::vector<char>& parent1, std::vector<char>& parent2) {
    int index = rand() % parent1.size();
    std::vector<char> child = parent1;
    std::set<char> used;

    for (int i = 0; i < index; i++) {
        used.insert(child[i]);
    }
    for (int i = index; i < parent2.size(); i++) {
        if (!used.count(parent2[i])) {
            child[i] = parent2[i];
            used.insert(parent2[i]);
        }
        else {
            for (int j = 0; j < parent1.size(); j++) {
                if (!used.count(parent1[j])) {
                    child[i] = parent1[j];
                    used.insert(parent1[j]);
                    break;
                }
            }
        }
    }
    return child;
}

/**
 * @brief Funkcja znajduj¹ca najlepsz¹ trasê spoœród tras w populacji
 *
 * @param population
 * @return std::pair<std::vector<char>, int>
 */
std::pair<std::vector<char>, int> findBestRoute(std::vector<std::pair<std::vector<char>, int>> population) {
    int minCost = INT_MAX;
    std::pair<std::vector<char>, int> result;

    for (auto route : population) {
        if (route.second < minCost) {
            minCost = route.second;
            result = route;
        }
    }

    return result;
}

/**
 * @brief Funkcja odpowiadaj¹ca za zachodzenie mutacji
 *
 * @param route
 */
void mutate(std::vector<char>& route) {
    int index1 = rand() % route.size();
    int index2 = rand() % route.size();
    std::swap(route[index1], route[index2]);
}

/**
 * @brief G³ówna funkcja rozwi¹zuj¹ca TSP
 *
 * @param graph
 * @param population_size
 * @param generations
 * @return std::vector<std::pair<std::vector<char>, int>>
 */
std::vector<std::pair<std::vector<char>, int>> TSP(Graph graph, int population_size, int generations) {
    std::vector<std::pair<std::vector<char>, int>> population;
    std::vector<std::pair<std::vector<char>, int>> result;

    for (int i = 0; i < population_size; i++) {
        std::vector<char> route = generateRoute(graph);
        population.push_back(std::make_pair(route, calcFitness(route, graph)));
    }

    for (int i = 0; i < generations; i++) {
        std::random_shuffle(population.begin(), population.end());
        std::vector<std::pair<std::vector<char>, int>> new_population;
        for (int j = 0; j < population_size / 2; j++) {
            std::vector<char> child1 = crossover(population[j].first, population[population_size - j].first);
            mutate(child1);
            std::vector<char> child2 = crossover(population[population_size - j - 1].first, population[j].first);
            mutate(child2);
            new_population.push_back(std::make_pair(child1, calcFitness(child1, graph)));
            new_population.push_back(std::make_pair(child2, calcFitness(child2, graph)));
        }
        population = new_population;

        std::vector<std::pair<std::vector<char>, int>> check;

        for (auto route : population) {
            std::vector<char> cities = route.first;
            cities.push_back(route.first[0]);
            check.push_back(std::make_pair(cities, calcFitness(cities, graph)));
        }

        std::pair<std::vector<char>, int> best = findBestRoute(check);


        result.push_back(best);
    }
    return result;
}