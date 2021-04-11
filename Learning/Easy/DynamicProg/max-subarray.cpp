#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int maxSubArray(vector<int>& nums) {

	int total = nums[0];
	int max_value = nums[0];
	int len = nums.size();

	for (int i = 1; i < len; i++) {
		total = max(nums[i], total+nums[i]);
		max_value = max(max_value, total);
	}

	return max_value;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v = {1,2};

	cout << maxSubArray(v) << endl;

	return 0;
}