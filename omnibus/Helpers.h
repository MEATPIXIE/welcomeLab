#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>

using namespace std;

struct Station{
    std::string stationName;

    struct Neighbor{
        Station* stationNeighbor;
        int time;
        std::string lineName;
    };

    Neighbor neighbor;

    std::vector<std::string> transitLines;
};

#endif
