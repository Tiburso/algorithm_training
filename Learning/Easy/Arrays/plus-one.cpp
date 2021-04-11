#include <bits/stdc++.h>
#define long long as ll

using namespace std;

vector<int> plusOne(vector<int> digits) {
	int size = digits.size()-1;

	bool carry = true;
	for (int i = size; i >= 0; i--) {
		if ( carry ) {
			if ( digits[i] == 9) {
				digits[i] = 0;
				if (i == 0) digits.insert(digits.begin(), 1);
			}
			else {
				digits[i]++;
				carry = false;
			}
		} 
	}

	return digits;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> n = {9,9};

	vector<int> v = plusOne(n);

	for (int x : v) cout << x << " ";
	cout << endl;

	return 0;
}