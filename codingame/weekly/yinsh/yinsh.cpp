#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
enum class key {
    Empty, Mark, Ring
};

class Board {
private:
    map<string, key> board;

public:
    Board();
    ~Board();
};

Board::Board() {

}

Board::~Board() {
    
}


int main() {
    int myId; // ID of your player.
    cin >> myId; cin.ignore();

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "yes" << endl;

    // game loop
    while (1) {
        int count; // number of rows.
        cin >> count; cin.ignore();
        for (int i = 0; i < count; i++) {
            string line; // rows from left to right (viewer perspective).
            cin >> line; cin.ignore();
        }
        int actionCount; // number of legal actions for this turn.
        cin >> actionCount; cin.ignore();
        for (int i = 0; i < actionCount; i++) {
            string action; // the action
            cin >> action; cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << "a2" << endl;
    }
}