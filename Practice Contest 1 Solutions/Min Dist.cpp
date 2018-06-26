/*

Min Dist
--------------------------------------------------------------------------

You are given a number 'n'. Assume an infinite perfect n-ary tree. The root node is always 0. The node 'i' has 'n' children : i*n + 1 , i*n + 2 , ...... , i*n + n

You are given two nodes 'A' and 'B', of this infinite n-ary tree. Suppose 'L' is the Lowest Common Ancestor of these two nodes. Now, let the distance of 'A' and 'B' from 'L' be 'x' and 'y' respectively. You need to print the minimum of 'x' and 'y'.

Distance between two nodes is the number of edges between them.

Input Format

You are given 'T' test. In the next 'T' lines, you get three integers : 'n' , 'A' and 'B'.

Constraints

1<=T<=10^5

1<=n<=10

0<=A,B<=10^9

Output Format

Print the required output, each in a new line.

Sample Input 0

2
3 22 9
3 4 7
Sample Output 0

1
2



*/



#include <bits/stdc++.h>
 
#define INF                         (long long)1e15
#define EPS                         1e-9
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
   ios_base::sync_with_stdio(false);  
   int it, t;
   cin>>t;
   while(t--)
   {
      ll n, a, b, i, j, x=0, y=0;
      cin>>n>>a>>b;
      if(n==1)
      {
        cout<<0<<"\n";
        continue;
      }
      stack<ll> s1, s2;
      while(a)
      {
        s1.push(a);
        a = (a-1)/n;
      }
      while(b)
      {
        s2.push(b);
        b = (b-1)/n;
      }

      while(!s1.empty() && !s2.empty() && s1.top()==s2.top())
      {
        s1.pop();
        s2.pop();
      }

      x = s1.size();
      y = s2.size();

      cout<<min(x,y)<<endl;


   }



   return 0;
} 