#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

long reverse1(int x) {
	long final = 0;

	while ( x != 0 ) {
		final = final*10 + x%10;
		x /= 10;
	}

	return final;
}

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long x = reverse(1534236469);

	cout << x << endl;

	return 0;
}