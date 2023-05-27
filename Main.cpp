/**
 * @file main.cpp
 * @author Piotr Nowak (nowakpiotr510@gmail.com)
 * @brief G³ówny plik programu
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "File.h"

 /**
  * @brief G³ówna funkcja programu
  *
  * @return int
  */
int main(int argc, char** argv) {

    if (argc != 9) {
        std::cout << "Podaj poprawne aregumenty" << std::endl;
        return 0;
    }

    std::map<std::string, std::string> arguments;
    for (int i = 1; i < argc; i += 2) arguments[argv[i]] = argv[i + 1];

    for (auto arg : arguments) {
        if (arg.first != "-i" && arg.first != "-o" && arg.first != "-g" && arg.first != "-n") {
            std::cout << "Podaj poprawne argumenty" << std::endl;
            return 0;
        }
    }

    Graph graph = loadGraph(arguments["-i"]);

    auto tsp = TSP(graph, stoi(arguments["-n"]), stoi(arguments["-g"]));

    saveGraph(tsp, arguments["-o"]);
}