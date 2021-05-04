#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
string find_target(string& s, map<string, int>& m) {
    int max = 1;
    string target = "";

    for (int i = 0; i < s.length()-1; i++) {
        string st = s.substr(i, 2);

        if ( m[st] > max ) {
            max = m[st];
            target = st;
        }
    }

    return target;
}

string pairs(string& s) {
    map<string, int> m;

    for (int i = 0; i < s.length()-1; i++) {
        string st = s.substr(i, 2);

        m[st]++;

        if (s[i] == s[i+2] && s[i+1] == s[i+2] ) i++;
    }

    return find_target(s, m);
}

list<pair<char, string>> compress(string& st) {
    string target;
    char NT = 'Z';
    list<pair<char,string>> subs;

    int i= 0;
    do  {
        target = pairs(st);

        string new_str = "";
        for (int i = 0; i < st.length(); i++) {
            if ( st.substr(i, 2) == target ) {
                new_str += NT;
                i++;
            }
            else new_str += st[i];
        }

        st = move(new_str);
        
        cerr << st << " Target:" << target << endl;
        if (target != "" ) subs.push_back( {NT, target} );
        NT--;

    } while (target != "");

    return subs;
}   

int main()
{
    int n;
    int m;
    cin >> n >> m; cin.ignore();

    string actual = "";
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line; cin.ignore();
        actual += line;
    }

    list<pair<char, string>> subs = compress(actual);
    cout << actual << endl;

    for (auto &p : subs) {
        cout << p.first << " = " << p.second << endl;
    }
}