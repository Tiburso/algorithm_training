#include <bits/stdc++.h>
#define long long as ll

using namespace std;

bool containsDuplicate(vector<int>& nums) {
	set<int> s; 

	for (int n : nums) {
		if ( s.count(n) ) return true;
		else s.insert(n);
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v = {1,1,2,3,4,5}; 

	if (!containsDuplicate(v)) cout << "NO DUPS" << endl;
	else cout << "DUPS" << endl;

	return 0;
}