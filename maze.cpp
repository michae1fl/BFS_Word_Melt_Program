#include "maze.h"
#include <cassert>

Maze::Maze() {
    startLocation = Location();
    endLocation = Location();
    validLocations = {startLocation, endLocation};
}

Location Maze::getStartLocation() const {
    return startLocation;
}

bool Maze::isValidLocation(const Location &loc) const {
    return validLocations.find(loc) != validLocations.end();
}

bool Maze::isEndLocation(const Location &loc) const {

    return loc == endLocation;
}

istream &operator>>(istream &is, Maze &m) {

    if (!(m.startLocation == Location())) {
        m.validLocations.clear();
    }

    Location loc;
    int noOfLocations;

    is >> noOfLocations;

    for (int i = 0; i < noOfLocations; i++) {
        is >> loc;
        m.validLocations.insert(loc);
    }


    is >> m.startLocation >> m.endLocation;

    assert(m.isValidLocation(m.startLocation));
    assert(m.isValidLocation(m.endLocation));

    return is;
}
