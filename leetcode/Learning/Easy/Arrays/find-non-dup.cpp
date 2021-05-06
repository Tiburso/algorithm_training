#include <bits/stdc++.h>
#define long long as ll

using namespace std;

int singleNumber(vector<int>& nums) {
	int a = 0;

	for (int n : nums) {
		a ^= n;
	}

	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v = {1,1,2,2,3,3,4,5,5};

	int n = singleNumber(v);

	cout << n << endl;

	return 0;
}