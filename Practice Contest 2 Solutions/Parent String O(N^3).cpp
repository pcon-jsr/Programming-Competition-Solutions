/* Parent String

You are given two strings 's1' and 's2'. You need to find the total number of unique shortest strings, having both strings(s1 and s2) as its subsequence.

*/

#include <bits/stdc++.h>

#define ll long long int

 
using namespace std;
ll dp1[51][51];
ll dp2[51][51][105];
 
ll func(string s1, string s2, int i, int j, ll l)
{
    if(i==s1.length() && j!=s2.length())
    {
        return func(s1,s2,i,j+1,l-1);
    }
   
    if(i!=s1.length() && j==s2.length())
    {
        return func(s1,s2,i+1,j,l-1);
    }
   
    if(i==s1.length() && j==s2.length() && l==0) return 1;
   
    if(i==s1.length() && j==s2.length() && l!=0) return 0;
   
    if(dp2[i][j][l]!=-1) return dp2[i][j][l];
   
    if(s1[i]==s2[j]) return dp2[i][j][l]=func(s1,s2,i+1,j+1,l-1);
   
    else return dp2[i][j][l]=func(s1,s2,i+1,j,l-1)+func(s1,s2,i,j+1,l-1);
}
 
int lcs(string s1, string s2, int i, int j)
{
    if(i==s1.length() || j==s2.length()) return 0;
   
    if(dp1[i][j]!=-1) return dp1[i][j];
   
    if(s1[i]==s2[j]) return dp1[i][j]=1+lcs(s1,s2,i+1,j+1);
   
    else return dp1[i][j]=max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
}
 
 
int main() {
   int t, it;
   cin>>t;
   while(t--)
   {
       memset(dp1,-1,sizeof(dp1));
       memset(dp2,-1,sizeof(dp2));
       string s1, s2;
       cin>>s1>>s2;
       ll len, ans;
       len=s1.length()+s2.length()-lcs(s1,s2,0,0);
       ans=func(s1,s2,0,0,len);
       printf("%lld\n",ans);
   }
 
   return 0;
}
