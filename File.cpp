/**
 * @file File.cpp
 * @author Piotr Nowak (nowakpiotr510@gmail.com)
 * @brief Funkcje operacji na plikach
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "File.h"

 /**
  * @brief Dzielenie tekstu na fragmenty wzglêdem znaku
  *
  * @param str
  * @return std::vector<std::string>
  */
std::vector<std::string> split(std::string str) {
    std::vector<std::string> result;

    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, ' ')) {
        result.push_back(s);
    }

    return result;
}

/**
 * @brief Wczytywanie grafu z pliku
 *
 * @param routefile
 * @param graphfile
 * @return Graph
 */
Graph loadGraph(std::string graphfile) {
    std::ifstream gfile(graphfile);

    std::vector<char> labels;
    std::string s;
    std::getline(gfile, s);
    std::vector<std::string> l = split(s);

    for (int i = 0; i < l.size(); i++) labels.push_back(l[i][0]);

    Graph graph = initGraph(labels);

    std::string line;
    int num = 0;
    while (std::getline(gfile, line)) {
        std::vector<std::string> sline = split(line);
        for (int i = 0; i < sline.size(); i++) {
            addEdge(graph, labels[num], labels[i], stoi(sline[i]));
        }
        num++;
    }

    return graph;
}

/**
 * @brief Zapis wyniku do pliku
 *
 * @param tsp
 * @param filename
 */
void saveGraph(std::vector<std::pair<std::vector<char>, int>> tsp, std::string filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (int i = 0; i < tsp.size(); i++) {
            file << "generacja " << i + 1 << ", dlugosc " << tsp[i].second << std::endl;

            for (auto c : tsp[i].first) file << c << " ";
            file << std::endl;
        }

        file.close();
    }
    else {
        std::cout << "Nie mo¿na otworzyæ pliku " << filename << std::endl;
    }

}