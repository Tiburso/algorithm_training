#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int> final;
	int i, j;

	for (i = 0, j = 0; i < m && j < n;) {
		if (nums1[i] < nums2[j]) {
			final.push_back(nums1[i]);
			i++;	
		} 
		else {
			final.push_back(nums2[j]);
			j++;
		}
	}

	for (; i < m; i++) {
		final.push_back(nums1[i]);
	}

	for (;j < n; j++) {
		final.push_back(nums2[j]);
	}

	nums1 = final;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v1 = {1,2,3,0,0,0}; 
	vector<int> v2 = {2,5,6}; 

	merge(v1, 3, v2, 3);

	for (int x: v1) cout << x << " ";
	cout << endl;

	return 0;
}