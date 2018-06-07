/*
Little geometry
-----------------------------------------------------------
Link to challenge : https://www.hackerrank.com/contests/practice-1-pcon/challenges/little-geometry


There are two right angled triangles, having the same base(on the same side of the base). You are given the length of hypotenuse of the two triangles('a' and 'b') and the perpendicular distance('d') between the point of intersection of the hypotenuses and the base. You need to calculate the length of the base of the triangles.

Input Format

There are T test cases. Each test case has consists of three floating point values(the length of two hypotenuses, and the perpedicular distance between the point of intersection of the hypotenuses and the base).

Constraints

1<=T<=10^5

1<=a,b,d<=10^9

Output Format

Print the length of base rounded off to the nearest integer.

Sample Input 0

2
10.0 8.0 2.0
12.0 10.0 3.0
Sample Output 0

7
9
*/

#include <bits/stdc++.h>
 
#define INF                         (long long)1e15
#define EPS                         1e-6
#define MOD   1000000007
#define checkbit(n,b)                ( (n >> b) & 1)
#define min3(a,b,c)                  ( a<b?(a<c?a:c):(b<c?b:c) )
#define max3(a,b,c)                  ( a>b?(a>c?a:c):(b>c?b:c) )
//dataTypes
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define vp vector< pair<long long, long long > >
//STLFunctions
#define pb(x) push_back(x)
#define maxElement(v) *max_element(v.begin(), v.end())
#define minElement(v) *min_element(v.begin(), v.end())
#define SORT(v) sort(v.begin(),v.end())
#define mp(x,y) make_pair(x,y)
//loops
#define f(i,a,n) for( i=a; i<n; i++)
 
using namespace std;
 
int main() {
   //ios_base::sync_with_stdio(false);
   int t, it;
   cin>>t;
   while(t--)
   {
       double x, y, c, d, ans, z, w;
       cin>>x>>y>>c;
       double h=min(x,y), l=0, cdash;
       while(h>=l)
       {
           w=(l+h)/2;
           cdash=(sqrt(x*x-w*w)*sqrt(y*y-w*w))/(sqrt(x*x-w*w)+sqrt(y*y-w*w));
           if(abs(c-cdash)<EPS)
           {
               ans=w;
               break;
           }
           if(cdash>c) l=w;
           else h=w;

       }
       
       printf("%lld\n",(long long)round(ans));
   }
 
   return 0;
}