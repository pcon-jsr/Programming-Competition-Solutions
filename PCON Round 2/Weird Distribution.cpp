//Problem: https://www.hackerrank.com/contests/pcon-round-2/challenges/weird-distribution

/*
	To maximize the number of balls in last box, the other boxes should have least possible number of balls
	i.e, the distribution should be like 1, 2, 3,... .

	Time Complexity: O(n).
*/


#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		long long k, n;
		cin >> k >> n;
		long long total = (n*(n+1)) >> 1; //Least number of balls required for n boxes.
		if (total > k) {
			cout << -1 << endl;
			continue;
		}

		for (int i = 1; i < n; i++)
			cout << i << " ";

		long long last = n + (k-total); //Number of balls in nth box = n + (number of balls left).
		cout << last << endl;
	}

	return 0;
}
