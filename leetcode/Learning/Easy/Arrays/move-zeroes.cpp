#include <bits/stdc++.h>
#define long long as ll

using namespace std;

void moveZeroes(vector<int>& nums) {

	for (int i = 0, j = 0; j < nums.size(); j++ ) {
		if ( nums[j] != 0 ) {
			swap(nums[i++], nums[j]);
		} 
    }

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v = {0,1,2,3,0,4,5,0,6,7};

	moveZeroes(v);

	for (int x: v) cout << x << " ";
	cout << endl;

	return 0;
}