#include <bits/stdc++.h>
#define long long as ll

using namespace std;

int removeDuplicate(vector<int>& nums) {
	int len = nums.size();
	if (len == 0 || len == 1) return len;

	int j = 0;
	for (int i = 0; i < len-1; i++) {
		if (nums[i] != nums[i+1]) nums[j++] = nums[i];
	}	

	nums[j++] = nums[len-1];

	return j;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v = {1,1,1,2,2,3,3,4,5}; 

	int len = removeDuplicate(v);

	cout << len << " ";

	cout << "[";
	for (auto i = 0; i < len-1; i++) {
		cout << v[i] << ",";
	}

	cout << v[len-1] << "]" << endl;

	return 0;  // v = [0,0,1,1,1,2,2,3,3,4] i=0
}