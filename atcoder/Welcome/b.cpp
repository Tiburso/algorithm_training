#include <bits/stdc++.h>
#define long long as ll

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int i, j;

	cin >> n;
	int l[n/2];

	for (i = 0; i < n; i+=2){
		l[i/2] = i;
	} 

	for (i= 0, j = n/2; i <= j; i++, j--) {
		if (l[i] + l[j] == n) {
			cout << "YES" << "\n";
			return 0;
		}
	}

	cout << "NO" << "\n";

	return 0;
}