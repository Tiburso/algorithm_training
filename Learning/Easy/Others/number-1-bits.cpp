#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int hammingWeight(uint32_t n) {
	int total = 0;
	for (; n != 0; n >>= 1) {
		if ( n & 1 ) total++;
	}

	return total;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;

	cin >> n;

	cout << hammingWeight(n);

	return 0;
}