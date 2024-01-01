#ifndef BFS_WORD_MELT_PROGRAM_LOCATION_H
#define BFS_WORD_MELT_PROGRAM_LOCATION_H

#include <iostream>

using namespace std;

class Location {
public:
    Location();

    void iterationBegin();
    Location iterationCurrent() const;
    void iterationAdvance(void);
    bool iterationDone(void) const;

    bool operator==(const Location &loc) const;

    friend ostream &operator<<(ostream &os, const Location &loc);
    friend istream &operator>>(istream &is, Location &loc);
    bool operator<(const Location &loc) const;

private:
    string word;
    enum { CHANGE_LETTER, INSERT_LETTER, DELETE_LETTER, DONE };
    unsigned int iterationMode;
    unsigned int indexToChange;
    char nextLetter;
};

#endif //BFS_WORD_MELT_PROGRAM_LOCATION_H
