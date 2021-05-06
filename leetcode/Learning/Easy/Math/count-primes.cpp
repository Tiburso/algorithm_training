#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int countPrimes(int n) {
	if (n == 0) return 0;

	vector<bool> isPrime(n,true);
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i*i < n; i++) {
		if (!isPrime[i]) continue;
		for (int j = i*i; j < n; j += i) {
			isPrime[j] = false;
		}
	}

	int count = 0; 
	for (int i = 0; i < n; i++) {
		if (isPrime[i]) count++;
	}

	return count;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x;

	cin >> x;

	cout << countPrimes(x) << endl;

	return 0;
}