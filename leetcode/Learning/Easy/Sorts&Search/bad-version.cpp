#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int bad;
int times = 0;

bool isBadVersion(int version) {
	times++;
	return version >= bad;
}

int firstBadVersion(int n) {
	int min = 0;
	int max = n;
	int mid;

	while ( max-min != 1) {
		mid = min + (max-min)/2;

		if ( isBadVersion(mid) ) max = mid;
		else min = mid;

	}
	
	return max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x = 10;

	bad = rand() % x;

	x = firstBadVersion(x);

	cout << times << " " << x << " " << bad; 

	return 0;
}