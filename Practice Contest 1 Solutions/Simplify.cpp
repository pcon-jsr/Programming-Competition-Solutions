/*
Link to the challenge : https://www.hackerrank.com/contests/practice-1-pcon/challenges/rishav-and-maths/problem
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long
const ll p=1e9+7;
ll power(ll n,ll m)
{
    ll res=1ll;
    while(m)
    {
        if(m&1)
        res=(res*n)%p;
        n=(n*n)%p;
        m/=2;
    }
    return res;
}
int main()
{
  ll n,i,t;
  cin>>t;
  while(t--)
  {
  cin>>n;
  ll x=power(3ll,n+2);
  x=(x%p -(2*n)%p +p)%p;
  x=(x%p -5%p + p)%p;
  x=(x * power(n+1,p-2))%p;
  x=(x * power(n+2,p-2))%p;
  cout<<x<<"\n";
  }  
}
