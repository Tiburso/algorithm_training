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

void str_tolower(string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

string SplitFilename (const std::string& str) {
    std::size_t found = str.find_last_of(".");
    string ret = str.substr(found+1);

    if ( ret == str )
        return "";
    else 
        return ret;
}

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();

    map<string, string> mime;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();

        str_tolower(EXT);

        mime[EXT] = MT;
    }

    for (int i = 0; i < Q; i++) {
        string FNAME;
        getline(cin, FNAME); // One file name per line.

        string ext = SplitFilename(FNAME);
        str_tolower(ext);

        cerr << "EXT:" << ext << "\n";

        if ( mime.find(ext) != mime.end() ) {
            string s = mime[ext];
            cout << s << endl;
        }
        else 
            cout << "UNKNOWN" << endl;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    
}