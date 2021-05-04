#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <list>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
enum class Type {
    Wall, Empty, Unknown, Objective, Begin
};

struct hash_pair {
   template <class T1, class T2>
   size_t operator()(const pair<T1, T2>& p) const{
      auto hash1 = hash<T1>{}(p.first);
      auto hash2 = hash<T2>{}(p.second);
      return hash1 ^ hash2;
   }
};

struct Maze {
    int row, col;
    map<pair<int, int>, Type> board;
    bool completed;
    pair<int,int> obj;

    Maze(int r, int c) : row(r), col(c), completed(false) {}

    void build_board(int x, int y, char piece) {   
        pair<int,int> c(x,y);
        Type type;

        switch (piece) {
            case '.':
                type = Type::Empty;
                break;
            case '#':
                type = Type::Wall;
                break;
            case '?':
                type = Type::Unknown;
                break;
            case 'C':
                if (completed) type = Type::Begin;

                else {
                    type = Type::Objective;
                    obj = c;
                }
                break;
            case 'T':
                if (!completed) type = Type::Begin;
                
                else {
                    type = Type::Objective;
                    obj = c;
                }
                break;
        }

        board[c] = type;

    }

    list<pair<int,int>> valid_adj(const pair<int,int>& any) {
        list<pair<int,int>> adj;
        
        if ( board[ make_pair(any.first + 1, any.second ) ] != Type::Wall ) {
            adj.push_back( make_pair(any.first + 1, any.second ) );
        }

        if ( board[ make_pair(any.first - 1, any.second ) ] != Type::Wall ) {
            adj.push_back( make_pair(any.first - 1, any.second ));
        }
        
        if ( board[ make_pair(any.first, any.second + 1 )] != Type::Wall ) {
            adj.push_back( make_pair(any.first, any.second + 1 ) );
        } 

        if ( board[ make_pair(any.first, any.second - 1 ) ] != Type::Wall ) { 
            adj.push_back( make_pair(any.first, any.second - 1 ) );
        }

        return adj;
    }

    pair<unordered_map<pair<int, int>, pair<int,int>, hash_pair>, pair<int,int>> find_path(pair<int,int>& src) {
        queue<pair<int,int>> traversed;
        map<pair<int,int>, bool> visited;
        unordered_map<pair<int, int>, pair<int,int>, hash_pair> path;

        traversed.push(src);
        visited[src] = true;
        path[src] = src;

        pair<int,int> compare;

        pair<int, int> c;
        while ( !traversed.empty() ) {
            c = traversed.front();
            traversed.pop();

            if ( completed ) {
                if (c == obj)
                    break;
            }
            else if (c == obj || board[c] == Type::Unknown ) {
                break;
            }

            for ( auto &a : valid_adj(c) ) {
                if ( !visited[a] ) {
                    path[a] = c;
                    traversed.push(a);
                    visited[a] = true;
                }
            }
        }

        return {path, c};
    }

    string choose_path(pair<int,int>& src) {
        string dir;

        auto p = find_path(src);
        auto path = p.first;
        auto begin = p.second;

        while ( path[begin] != src ) {
            begin = path[begin];
        }

        if (begin == obj) completed = true;
        
        if ( src.first == begin.first) {
            if ( src.second < begin.second) dir = "DOWN";
            else dir = "UP";
        }
        else {
            if ( src.first < begin.first) dir = "RIGHT";
            else dir = "LEFT";
        }
        
        return dir;
    }
};


int main()
{
    int R; // number of rows.
    int C; // number of columns.
    int A; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
    cin >> R >> C >> A; cin.ignore();

    Maze maze(R,C);

    // game loop
    while (true) {
        int KR; // row where Kirk is located.
        int KC; // column where Kirk is located.
        cin >> KR >> KC; cin.ignore();
        
        pair<int,int> src(KC, KR);

        for (int y = 0; y < R; y++) {
            string ROW; // C of the characters in '#.TC?' (i.e. one line of the ASCII maze).
            cin >> ROW; cin.ignore();

            //cerr << ROW << "\n";
            for (int x = 0 ; x < ROW.length(); x++) {
                maze.build_board(x, y, ROW[x]);
            }
        }
        
        cout << maze.choose_path(src) << endl;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

    }
}