/*
Problem:
https://www.hackerrank.com/contests/pcon-round-1/challenges/dora-the-explorer

Editorial:

This problem is similar to having a string of (a[1]+a[2]+...a[d]) length, in which there are d different characters and the frequency of character i is a[i]. The total number of different strings that can be formed is simply
(a[1]+a[2]+...+a[d])! / ( a[1]! * a[2]! *...*a[d]! ). where n! is factorial of n.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+10, M = 1e9+7;
vector<ll> fact(N);


void f()
{
  fact[0] = 1, fact[1] = 1;
  
  for (int i = 2; i < N; i++)
  fact[i] = (fact[i-1]*i)%M;
}

ll inv(ll x)
{
  ll res = 1, n = M-2;
  while (n)
  {
    if (n&1)
    res = (res*x)%M;
    x = (x*x)%M;
    n >>= 1;
  }
  return res;
}


const int NN = 1000;
int main(int argc, char const *argv[]) {

  f();
  int t;
  cin >> t;
  assert(t <= NN and t > 0);
  while (t--)
  {
    int n;
    cin >> n;
    assert(n <= NN and n > 0);
    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
      assert(v[i] <= NN and v[i] > 0);
      sum += v[i];
    }

    ll res = fact[sum];
    for (int i = 0; i < n; i++)
    res = (res*inv(fact[v[i]]))%M;

    assert(res < M and res > 0);
    cout << res << endl;
  }

  return 0;
}
