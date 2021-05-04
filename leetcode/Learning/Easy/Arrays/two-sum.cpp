#include <bits/stdc++.h>
#define long long as ll

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> passed;
	int size = nums.size();

	for (int i = 0; i < size; i++) {
		auto it = passed.find( target - nums[i] );
		if (it != passed.end()) {
			return {it->second,i};
		}

		passed[nums[i]] = i;
	}

	return {};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 9;
	vector<int> v = {};

	vector <int> ans = twoSum(v, n);

	for (int x : ans) cout << x << " ";
	cout << endl;

	return 0;
}