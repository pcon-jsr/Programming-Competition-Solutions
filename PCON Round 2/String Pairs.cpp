//Problem: https://www.hackerrank.com/contests/pcon-round-2/challenges/string-matching-4/problem

/*
	If for each string, we solve the queries by iterating over all the strings and checking 
	each possible substring. The complexity of this algorithm is O(n*n*l*l), where n is the number of string and l is the length of string.

	A little optimization - If we calculate, for each string the number of different substring it contains, then we can answer the queries by counting 
	the number of times a substring appeared. The counting can be done using a map or a hash table.
	The total complexity is O(n*l*l).
*/


#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	map<string, int> mp;
	set<string> S;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];

		for (int j = 0; j < v[i].length(); j++) {
			string s = "";
			for (int k = j; k < v[i].length(); k++) {
				s.push_back(v[i][k]);
				S.insert(s);
			}
		}

		for (auto &x : S)
			mp[x]++;
		S.clear();
	}

	int res = 0;
	for (auto &x : v)
		res += mp[x] - 1;

	cout << res << endl;

	return 0;
}
