#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int climbStairs(int n) {
	if (n == 1) return 1;

	pair<int,int> p = {1,2};
	for (int i = 2; i < n; i++) {
		int aux = p.first + p.second;
		p.first = p.second;
		p.second = aux;
	}

	return p.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << climbStairs(30) << endl;

	return 0;
}