#ifndef BFS_WORD_MELT_PROGRAM_MAZE_H
#define BFS_WORD_MELT_PROGRAM_MAZE_H

#include "location.h"
#include <iostream>
#include <set>

using namespace std;


class Maze {
public:
    Maze(void);

    Location getStartLocation() const;
    bool isValidLocation(const Location &loc) const;
    bool isEndLocation(const Location &loc) const;

    friend istream &operator>>(istream &is, Maze &m);

private:
    set<Location> validLocations;

    Location startLocation, endLocation;
};

#endif //BFS_WORD_MELT_PROGRAM_MAZE_H
