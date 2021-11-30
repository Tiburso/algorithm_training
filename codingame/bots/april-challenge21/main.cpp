#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <memory>

using namespace std;

class Tree {
private:	
	int cellIndex;
	int size;
	bool isMine;

public:
	//Tree(int id) : cellIndex(id) {}
	Tree(int id = 0, int s = 0, bool mine = false) : 
		cellIndex(id), size(s), isMine(mine) {}
	~Tree() {}

	friend ostream& operator<<(ostream& os, const Tree& t);
};

ostream& operator<<(ostream& os, const Tree& t) {
	return os << t.cellIndex << " " << t.size << " " << t.isMine;
}


/* Grid class */
class Grid {
private:
	vector<int> adj;
	Tree* tree;
	bool isShadow;
public:
	Grid( vector<int> a, Tree* t = NULL, bool shadow = false) : adj(a), tree(t), isShadow(shadow) {}
	~Grid() {
		delete tree;
	}

	void castShadow() { isShadow = true; }
};


/* Map class */
class Map {
private:
	int day;
	int sun; 
	int nutrient;

	map<int, Grid> grid;
	vector<vector<Tree>> myTrees;

public:
	Map(int d = 0, int s = 1, int n = 20) : day(d), sun(s), nutrient(n) {}
	~Map() {}

	void updateTrees() {

	}

	void newDay(int newDay, int newSun, int newNutrients) {
		day = newDay;
		sun = newSun;
		nutrient = newNutrients;

		//return new_d;
	}

	void clearTrees() {

		for (auto &size : trees) {
			size.clear();
		}
	}

	void growTrees() {

		 // GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>        
        if ( (7+trees[3].size() <= sun) && !trees[2].empty() ) {
        	cout << "GROW " << trees[2][0] << endl;
        }
        
        else if ( !trees[3].empty() ) {
        	cout << "COMPLETE " << trees[3][0] << endl;
        }

        else if ( (3+trees[2].size() <= sun) && !trees[1].empty() ) {
        	cout << "GROW " << trees[1][0] << endl;
        }

        else cout << "WAIT" << endl;  

	}

	void castShadows(int dir) {
		for (auto &p : grid) {
			p.second.castShadow();
		}
	}

};


/* Main function */

int main() {
    int numberOfCells; // 37
    cin >> numberOfCells; cin.ignore();

    Map map;
    for (int i = 0; i < numberOfCells; i++) {
        int index; // 0 is the center cell, the next cells spiral outwards
        int richness; // 0 if the cell is unusable, 1-3 for usable cells
        int neigh0; // the index of the neighbouring cell for each direction
        int neigh1;
        int neigh2;
        int neigh3;
        int neigh4;
        int neigh5;
        cin >> index >> richness >> neigh0 >> neigh1 >> neigh2 >> neigh3 >> neigh4 >> neigh5; cin.ignore();
    }

    // game loop
    while (1) {

        int day; // the game lasts 24 days: 0-23
        cin >> day; cin.ignore();

        int nutrients; // the base score you gain from the next COMPLETE action
        cin >> nutrients; cin.ignore();

        int sun; // your sun points
        int score; // your current score
        cin >> sun >> score; cin.ignore();

        map.newDay(day, sun, nutrients);

        int oppSun; // opponent's sun points
        int oppScore; // opponent's score
        bool oppIsWaiting; // whether your opponent is asleep until the next day
        cin >> oppSun >> oppScore >> oppIsWaiting; cin.ignore();

        int numberOfTrees; // the current amount of trees
        cin >> numberOfTrees; cin.ignore();


        map.clearTrees();

        for (int i = 0; i < numberOfTrees; i++) {
            int cellIndex; // location of this tree
            int size; // size of this tree: 0-3
            bool isMine; // 1 if this is your tree
            bool isDormant; // 1 if this tree is dormant
            cin >> cellIndex >> size >> isMine >> isDormant; cin.ignore();

            if (isMine) {
            	trees[size].push_back(cellIndex);
            }
            
        }

        // Can ignore just for input
        int numberOfPossibleMoves;
        cin >> numberOfPossibleMoves; cin.ignore();
        for (int i = 0; i < numberOfPossibleMoves; i++) {
            string possibleMove;
            getline(cin, possibleMove);
        }



        
    }
}