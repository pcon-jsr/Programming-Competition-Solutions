/*Kth Smallest Number

Given an array of length n and two integer a and b .Find number of distinct integer k such that absolute difference between kth smallest element and (k+a)th smallest element of array is less than b.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int c[1000001];

int main() {
    long long int n,a,b,i,ans=0;
    scanf("%lld %lld %lld",&n,&a,&b);
    for(i=0;i<n;i++)
        scanf("%lld",&c[i]);
    sort(c,c+n);
    for(i=0;i<n;i++)
    {
        if(i+a<n && c[i+a]-c[i]<b)
            ans++;
    }
    cout<<ans;
    return 0;
}



