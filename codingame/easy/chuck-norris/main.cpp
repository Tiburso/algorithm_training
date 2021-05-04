#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void add_prefix(stringstream& ss, int v) {
	if ( v == 0 ) ss << "00 ";
	else ss << "0 ";  
}

int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);


    stringstream ss;
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int v = (MESSAGE[0] >> 6) & 1;
    add_prefix(ss, v);
    for ( char &c : MESSAGE ) {

    	for (int i = 6; i >= 0; i--) {

    		if ( (( c >> i ) & 1) != v) {
    			ss << " ";
    			v = (c >> i) & 1;	
    			add_prefix(ss, v);
    		}

    		ss << "0";
    	}
    }


    cout << ss.str() << endl;
}