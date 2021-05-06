#include <bits/stdc++.h>
#define long long as ll

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	map<int, int> m;
	vector<int> final;

	if ( nums1.size() < nums2.size() ) swap(nums1, nums2);

	for (int x : nums1) {
		m[x]++;
	}

	for (int x : nums2) {
		if (m[x] >= 1) {
			final.push_back(x);	
			m[x]--;
		} 
	}

	return final;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v1 = {1,2};
	vector<int> v2 = {1,1};

	vector<int> final = intersect(v1, v2); 

	for (int x : final) cout << x << " ";
	cout << endl;

	return 0;
}