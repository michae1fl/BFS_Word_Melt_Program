#include "maze.h"
#include "arrayqueue.h"
#include "location.h"
#include <map>
#include <sstream>
#include <stack>

using namespace std;


int main(int argc, char **argv) {

    Maze problem;
    cin >> problem;


    map<Location, Location> solution;
    ArrayQueue<Location> frontier;
    Location current, neighbor;
    stack<Location> solStack;

    frontier.add(problem.getStartLocation());
    solution.insert(make_pair(frontier.getFront(), frontier.getFront()));

    while (frontier.getLength() != 0 &&
           !problem.isEndLocation(frontier.getFront())) {

        current = frontier.getFront();
        frontier.remove();

        for (current.iterationBegin(); !current.iterationDone(); current.iterationAdvance()) {
            neighbor = current.iterationCurrent();

            if (solution.find(neighbor) == solution.end() &&
                problem.isValidLocation(neighbor)) {
                frontier.add(neighbor);
                solution.insert(make_pair(neighbor, current));
            }
        }

    }


    if (problem.isEndLocation(problem.getStartLocation())) {
        cout << "Solution found" << endl;
        cout << problem.getStartLocation() << endl;
    } else if (problem.isEndLocation(frontier.getFront())) {
        cout << "Solution found" << endl;
        current = frontier.getFront();
        solStack.push(current);

        while (!(solution[current] == problem.getStartLocation())) {
            neighbor = solution[current];
            solStack.push(neighbor);
            current = neighbor;
        }
        solStack.push(solution[current]);

        while (!solStack.empty()) {
            cout << solStack.top() << endl;
            solStack.pop();
        }
    } else {
        cout << "No solution" << endl;
    }

    return 0;
}