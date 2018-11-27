// Problem: https://www.hackerrank.com/contests/pcon-round-2/challenges/cakewalk-2-2

/*
	The common divisor of numbers A and B is the same as the common divisors of gcd of both numbers i.e, gcd(A, B).
	So, just need to find the number of divisors of gcd(A, B).

	Time Complexity: O(sqrt(n)).
*/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		long long hcf = __gcd(a, b);
		int res = 0;
		for (long long i = 1; i*i <= hcf; i++) {
			if (hcf%i == 0) {
				if (i*i == hcf) // Number is a perfect square.
					res++;
				else
					res += 2;
			}
		}
		cout << res << endl;
	}

	return 0;
}
