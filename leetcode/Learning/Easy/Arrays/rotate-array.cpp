#include <bits/stdc++.h>
#define long long as ll

using namespace std;

void rotate(vector<int>& nums, int k) {
	int len =  nums.size();

	vector<int> aux(len);
	for (int i = 0; i < len; i++) {
		aux[(i+k) % len] = nums[i];
	}

	swap(aux, nums);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k = 3;
	vector<int> v = {0};

	rotate(v, k);

	for (int x: v) cout << x << " ";
	cout << endl;

	return 0;
}