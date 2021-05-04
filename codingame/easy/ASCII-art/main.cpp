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

void capitalizeString(string& s)
{
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return toupper(c); });
}

int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
    map<char, int> m;

    for (int i = 1; i <= alphabet.length(); i++) {
        m.insert( {alphabet[i-1], L*i} );
    }

    capitalizeString(T); 

    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);

        for (char &c : T) {
            int obj;
            if ( m.find(c) != m.end() ) obj = m[c];
            else obj = m['?'];

            for (int j = obj-L; j < obj; j++) {
                cout << ROW[j];
            } 
        }

        cout << endl;
    }
}