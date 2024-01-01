#include "location.h"

Location::Location() {
    word = "";
    iterationMode = CHANGE_LETTER;
    indexToChange = 0;
    nextLetter = 'a';
}

void Location::iterationBegin() {

    indexToChange = 0;
    nextLetter = 'a';
    if(nextLetter == word.at(indexToChange)) {
        nextLetter++;
    }
    iterationMode = CHANGE_LETTER;
}

Location Location::iterationCurrent() const {
    Location loc = *this;

    if (iterationMode == CHANGE_LETTER) {
        loc.word.at(indexToChange) = nextLetter;
    }
    if (iterationMode == INSERT_LETTER) {
        loc.word.insert(indexToChange, 1, nextLetter);
    }
    if (iterationMode == DELETE_LETTER) {
        loc.word.erase(indexToChange, 1);
    }

    return loc;
}

void Location::iterationAdvance() {
    if (iterationMode == DELETE_LETTER) {
        indexToChange ++;
    }
    else {
        nextLetter++;
        if (iterationMode == CHANGE_LETTER && nextLetter == word.at(indexToChange)) {
            nextLetter ++;
        }
    }

    switch (iterationMode) {
        case CHANGE_LETTER:
            if (nextLetter == word.at(indexToChange)) {
                if (nextLetter == 'z' + 1) {

                    indexToChange++;
                    nextLetter = 'a';
                    if (indexToChange >= word.length()) {iterationMode = INSERT_LETTER;
                        indexToChange = 0;

                    }
                }
                else {
                    nextLetter ++;
                }
            }
            else {
                if (nextLetter == 'z'+1) {
                    indexToChange++;
                    nextLetter = 'a';
                    if (indexToChange >= word.length()) {
                        iterationMode = INSERT_LETTER;
                        indexToChange = 0;
                    }
                    if (nextLetter == word.at(indexToChange)) {
                        nextLetter ++;
                    }
                }
            }
            break;

        case INSERT_LETTER:
            if (nextLetter == 'z'+1) {
                indexToChange ++;
                nextLetter = 'a';
            }
            if (indexToChange > word.length()) {
                iterationMode = DELETE_LETTER;
                indexToChange = 0;
                nextLetter = 'a';
            }
            break;
        case DELETE_LETTER:
            if(indexToChange == word.length()) {
                iterationMode = DONE;
                indexToChange = 0;
            }
            break;
        default:
            iterationMode = CHANGE_LETTER;
            indexToChange = 0;
            nextLetter = 'a';
    }


}

bool Location::iterationDone() const {
    return (iterationMode == DONE);
}

bool Location::operator==(const Location &loc) const {
    return (word == loc.word);
}

ostream &operator<<(ostream &os, const Location &loc) {
    os << loc.word;
    return os;
}

istream &operator>>(istream &is, Location &loc) {
    is >> loc.word;
    return is;
}

bool Location::operator<(const Location &loc) const {
    return (word < loc.word);
}