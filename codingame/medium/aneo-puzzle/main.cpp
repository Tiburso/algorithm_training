#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Light {
	int dist;
	int duration;

	Light() : dist(0), duration(0) {}
	Light(int _dist, int _duration) : dist(_dist), duration(_duration) {}
};

bool isGreen(int speed, Light& l) {
	const long dist = 18 * l.dist;
	const long mod = 10 * speed * l.duration;
	const long rside = 5 * speed * l.duration;

	return dist % mod < rside;
}

int main() {
    int maxSpeed;
    cin >> maxSpeed; cin.ignore();

    int lightCount;
    cin >> lightCount; cin.ignore();
	std::vector<Light> lights(lightCount);

    for (int i = 0; i < lightCount; i++) {
        int distance;
        int duration;
        cin >> distance >> duration; cin.ignore();

        Light tmp(distance, duration);

        lights[i] = tmp;
    }

    int speed;

   	for (speed = maxSpeed; speed > 0; speed--) {
   		bool pass = true;

   		for (auto &l: lights) {
   			if ( !isGreen(speed, l) ) {
   				pass = false;
   				break;
   			}
   		}

   		if (pass) break;
   	}

    cout << speed << endl;
}