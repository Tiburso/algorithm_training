#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int hammingDistance(int x, int y) {
	int test = x^y;
	int diff = 0;

	for (; test != 0; test >>= 1) {
		if ( test & 1) diff++;
	}

	return diff;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y;

	cin >> x >> y;


	cout << hammingDistance(x,y);

	return 0;
}