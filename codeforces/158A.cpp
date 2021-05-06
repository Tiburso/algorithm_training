#include <bits/stdc++.h>
#define long long as ll

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v;

	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a;

		cin >> a;

		v.push_back(a);  
	}

	int total = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] >= v[k-1] && v[i] > 0) total++;
	}

	cout << total << "\n";

	return 0;
}