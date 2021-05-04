#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    char grid[width][height];

    for (int y = 0; y < height; y++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .

        for (int x = 0; x < line.length(); x++) {
        	grid[x][y] = line[x];
        }
    }

    stringstream ss;
    for (int y = 0; y < height; y++) {
    	for (int x = 0; x < width; x++) {
    		char p = grid[x][y];

    		// if theres a point there 
    		if ( p == '0' ) {
    			ss << x << " " << y;

    			// Check if theres a neigbour right
    			bool isRigth = false;
    			for (int k = x+1; k < width; k++) {
    				char right = grid[k][y];

    				if (right == '0') {
    					ss << " " << k << " " << y;
    					isRigth = true;
    					break;
    				}
    			}
    			if (!isRigth) ss << " -1 -1";

    			// Check if theres a neigbour down
    			bool isDown = false;
    			for (int k = y+1; k < height; k++) {
    				char down = grid[x][k];

    				if (down == '0') {
    					ss << " " << x << " " << k;
    					isDown = true;
    					break;
    				}
    			}
    			if (!isDown) ss <<" -1 -1";

    			ss << "\n";
			}
		}

	}	

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    cout << ss.str() << endl;
}