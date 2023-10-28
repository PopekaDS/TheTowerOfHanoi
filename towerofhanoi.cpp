/*
The Tower of Hanoi, by Al Sweigart al@inventwithpython.com
A stack-moving puzzle game.
This code is available at https://nostarch.com/big-book-small-python-programming

import copy
import sys


def main():


    while True:  # Run a single turn.
        # Display the towers and disks:
        displayTowers(towers)

        # Ask the user for a move:
        fromTower, toTower = askForPlayerMove(towers)

        # Move the top disk from fromTower to toTower:
        disk = towers[fromTower].pop()
        towers[toTower].append(disk)

        # Check if the user has solved the puzzle:
        if COMPLETE_TOWER in (towers['B'], towers['C']):
            displayTowers(towers)  # Display the towers one last time.
            print('You have solved the puzzle! Well done!')
            sys.exit()


def askForPlayerMove(towers):
    """Asks the player for a move. Returns (fromTower, toTower)."""

    while True:  # Keep asking player until they enter a valid move.
        print('Enter the letters of "from" and "to" towers, or QUIT.')
        print('(e.g. AB to moves a disk from tower A to tower B.)')
        response = input('> ').upper().strip()

        if response == 'QUIT':
            print('Thanks for playing!')
            sys.exit()

        # Make sure the user entered valid tower letters:
        if response not in ('AB', 'AC', 'BA', 'BC', 'CA', 'CB'):
            print('Enter one of AB, AC, BA, BC, CA, or CB.')
            continue  # Ask player again for their move.

        # Syntactic sugar - Use more descriptive variable names:
        fromTower, toTower = response[0], response[1]

        if len(towers[fromTower]) == 0:
            # The "from" tower cannot be an empty tower:
            print('You selected a tower with no disks.')
            continue  # Ask player again for their move.
        elif len(towers[toTower]) == 0:
            # Any disk can be moved onto an empty "to" tower:
            return fromTower, toTower
        elif towers[toTower][-1] < towers[fromTower][-1]:
            print('Can\'t put larger disks on top of smaller ones.')
            continue  # Ask player again for their move.
        else:
            # This is a valid move, so return the selected towers:
            return fromTower, toTower


def displayTowers(towers):
    """Display the current state."""

    # Display the three towers:
    for level in range(TOTAL_DISKS, -1, -1):
        for tower in (towers['A'], towers['B'], towers['C']):
            if level >= len(tower):
                displayDisk(0)  # Display the bare pole with no disk.
            else:
                displayDisk(tower[level])  # Display the disk.
        print()

    # Display the tower labels A, B, and C.
    emptySpace = ' ' * (TOTAL_DISKS)
    print('{0} A{0}{0} B{0}{0} C\n'.format(emptySpace))


*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int TOTAL_DISKS = 5; // More disks means a more difficult puzzle.
void displayDisk(int width);

int main() {
    cout << "The Tower of Hanoi, by Al Sweigart al@inventwithpython.com\n";
    cout << "Move the tower of disks, one disk at a time, to another tower.Larger\n";
    cout << "disks cannot rest on top of a smaller disk.\n";
    cout << "More info at https ://en.wikipedia.org/wiki/Tower_of_Hanoi\n";

    // Start with all disks on tower A :
    vector <int> COMPLETE_TOWER(TOTAL_DISKS);
    for (int i = 0; i < TOTAL_DISKS; ++i) {
        COMPLETE_TOWER[i] = TOTAL_DISKS - i;
    }

    // Set up the towers.The end of the list is the top of the tower.
    map<char, vector<int>> towers = {
        {'A', COMPLETE_TOWER}, {'B', {}}, {'C', {}} // // // towers = { 'A': copy.copy(COMPLETE_TOWER), 'B' : [] , 'C' : [] }
    };

    displayDisk(0);
    displayDisk(1);
    displayDisk(2);
    displayDisk(3);
    displayDisk(4);
    displayDisk(5);

    return 0;
}

void displayDisk(int width) {
    // Display a disk of the given width. A width of 0 means no disk.
    string emptySpace(TOTAL_DISKS - width, ' ');
    if (width == 0) {
        cout << emptySpace << "||" << emptySpace << '\n';
    } else {
        // Display the disk:
        string disk(width, '@');
        string numLabel = "_" + to_string(width);
        cout << emptySpace << disk << numLabel << disk << emptySpace << '\n';
    }
}