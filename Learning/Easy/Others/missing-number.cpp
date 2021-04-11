#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int missingNumber(vector<int>& nums) {
	sort(nums.begin(), nums.end()); 

	int len = nums.size();
	if (nums[len-1] != len) return len;

	if (nums[0] != 0) return 0;

	for (int i = 1; i < len; i++) {
		if ( nums[i]-1 != nums[i-1])
			return nums[i]-1;
	}

	return -1;
}

int missingNumber2(vector<int>& nums) {
	int len = nums.size();
	int missing = len;

	for (int i = 0; i < len; i++) {
		missing ^= i ^ nums[i];
	}

	return missing;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	return 0;
}