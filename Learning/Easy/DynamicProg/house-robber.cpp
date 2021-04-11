#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int rob(vector<int>& nums) {
	int include = nums[0];
	int exclude = 0;

	int len = nums.size();
	for (int i = 1; i < len; i++) {
		int tmp = max(include, exclude);
		include = exclude+nums[i];
		exclude = tmp;
	}


	return max(include, exclude);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v = {5,3,1,7};

	cout << rob(v) << endl;
	return 0;
}