#include <bits/stdc++.h>
#define long long as ll

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int total = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a,b,c;

		cin >> a >> b >> c;

		if (a+b+c >= 2) total++;
	} 

	cout << total << "\n";

	return 0;
}