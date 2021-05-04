#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    vector<int> stocks;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        stocks.push_back(v);
    }

    int base = stocks[0];
    int diff = 0;
    for (int i = 1; i < n; i++) {
        base = max(base, stocks[i]);
        diff = min(diff, stocks[i] - base);
    }   

    cout << diff << endl;
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
}