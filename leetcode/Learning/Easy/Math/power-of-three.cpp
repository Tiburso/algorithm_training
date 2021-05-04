#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

bool isPowerOfThree(int n) {
	return n > 0 && 1162261467 % n == 0;  // 1162261467 is the max int value power of 3
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;

	if (isPowerOfThree(x)) cout << "true";
	else cout << "false";

	return 0;
}