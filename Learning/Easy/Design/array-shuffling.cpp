#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

class Solution {
	vector<int> v;
	vector<int> def;

public:
	Solution(vector<int>& nums) {
		v = nums;

		for (int x : nums) {
			def.push_back(x);
		}
	}

	vector<int> reset() {
		return def;
	}

	vector<int> shuffle() {
		random_shuffle( v.begin(), v.end() );

		return v;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//Solution solution = new Solution();


	//solution.shuffle();
	//solution.reset();

	return 0;
}