#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct point {
    int x; 
    int y;
    point() : x(0), y(0) {}
    point(int _x, int _y) : x(_x), y(_y) {}

    bool same_height(const point& other) const {
        return y == other.y;
    }

    bool operator==(const point& rhs) const{
        return x == rhs.x && y == rhs.y;
    }
    
    bool operator!=(const point& rhs) const {
        return !operator==(rhs);
    }
    
    friend ostream& operator<<(ostream& os, const point& p);
};

ostream& operator<<(ostream& os, const point& p) {
    os << "X:" << p.x << " Y:" << p.y;

    return os;
}

int main()
{
    int h;
    point prev; 

    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();
    for (int i = 0; i < surfaceN; i++) {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> landX >> landY; cin.ignore();

        point tmp(landX, landY);

        if ( tmp.same_height(prev) ) h = landY;
        else prev = tmp;
    }

    // game loop
    while (1) {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        int dist = Y - h;

        if (dist >= 2500 ) {
            power = 0;
        }
        else if ( dist < h && dist >= 2200 ) {
            power = 1;
        } 
        else if ( dist >= 2000 ) {
            power = 2;
        }
        else if ( dist >= 1500 ) {
            power = 3;
        }
        else {
            power = 4;
        }

        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
        cout << "0 " << power << endl;
    }
}