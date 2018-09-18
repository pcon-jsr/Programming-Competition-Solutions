/*
Problem Link:
https://www.hackerrank.com/contests/pcon-round-1/challenges/ted-ratio

Editorial:
Just iterate over the string and take count of the number of vowels and consonants. At each itertion just check for the largest ratio of consonants to vowel and store the maximum index.
*/


#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  int res = 0;
  double vowel = 0, cons = 0, m = 0;
  for (int i = 0; i < n; i++)
    {
      if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
	vowel += 1;
      else
	cons += 1;

      double x = cons/vowel;
      if (x >= m)
	{
	  m = x;
	  res = i;
	}
    }

  cout << res+1;
  
  return 0;
}
