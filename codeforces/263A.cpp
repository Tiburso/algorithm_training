#include <bits/stdc++.h>
#define long long as ll

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;

	int n;
	for (int i = 0; i < 5 ; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> n;
			if ( n == 1 ) { y = j; x = i; } 
		}
	}

	cout << abs(2 - x) + abs(2 - y) << "\n";

	return 0;
}