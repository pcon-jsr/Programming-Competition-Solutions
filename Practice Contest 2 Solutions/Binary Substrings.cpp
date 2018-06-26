/* Binary Substrings

You are given a binary string (string consistng of zeros and ones) 'A', of length 'n'. Next you are given 'm' substrings (as pair of starting and ending indices), of the given binary string 'A'. Now the 'm' substrings are concatenated, such that the first substring takes the righmost postion, followed by each substring concatenated to the left. You need to tell the decimal value of this resultant concatenated binary string.

As the output can be significantly large, print the result mod 10^9 + 7

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

char ch[10001];

long long int binExpo(long long int n, long long int m)
{
    long long int ans=1;
    while(m>0)
    {
        if(m%2==1)
            ans=(ans*n)%MOD;
        n=(n*n)%MOD;
        m/=2;
    }
    return ans;
}


int main() {
    long long int n,m,l,r,val,val1,val2,ans,i,j;
    scanf("%lld %lld",&n,&m);
    scanf(" %s",ch);
    long long int a[n];
    val=1;
    for(i=n-1;i>=0;i--)
    {
        if(ch[i]=='1')
            a[i]=val;
        else
            a[i]=0;
        if(i!=n-1)
            a[i]+=a[i+1];
        val=(val*2)%MOD;
    }
    val1=0;
    ans=0;
    for(i=1;i<=m;i++)
    {
        scanf("%lld %lld",&l,&r);
        val=a[l];
        if(r!=n-1)
            val=(val-a[r+1]+MOD)%MOD;
        val=(val*binExpo(binExpo(2,n-1-r),MOD-2))%MOD;
        val=(val*binExpo(2,val1))%MOD;
        val1+=r-l+1;
        ans=(ans+val)%MOD;
    }
    cout<<ans;
    return 0;
}
