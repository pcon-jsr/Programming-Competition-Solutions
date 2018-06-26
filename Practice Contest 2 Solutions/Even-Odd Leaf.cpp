/*Even-Odd Leaf

Given a tree consisting of n nodes where each node is uniquely labeled from 1 to n and node labeled as 1 is root.

You have to print n line consisting of two numbers x and y where in ith line x is total number of pair of leaf nodes at odd distance and their path passing through node i and y is total number of pair of leaf nodes at even distance and path passing through node i.

Distance between two nodes is defined as total number of edges in shortest path between the two nodes.

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector< pi > 
const int N = 1000010;
vi v[N];
int odd[N],even[N];
ll oddAns[N],evenAns[N];
void dfs(int x, int p = 0)
{
    if(x!=1&&v[x].size()==1)
    {
        even[x]=1;
        return;
    }
    int leafAtEven=0,leafAtOdd=0;
    for(int y : v[x])
    {
        if(y==p) continue;
        dfs(y,x);
        leafAtOdd+=even[y];
        leafAtEven+=odd[y];
    }
    for(int y : v[x])
    {
        if(y==p) continue;
        oddAns[x]+=1ll*even[y]*(leafAtEven-odd[y]);
        oddAns[x]+=1ll*odd[y]*(leafAtOdd-even[y]);
        evenAns[x]+=1ll*even[y]*(leafAtOdd-even[y]);
        evenAns[x]+=1ll*odd[y]*(leafAtEven-odd[y]);
    }
    even[x]=leafAtEven;
    odd[x]=leafAtOdd;
    
}
void solve(int x,int p,ll evenLeaf,ll oddLeaf)
{
    int leafAtEven=0,leafAtOdd=0;
    if(x!=1&&v[x].size() == 1)
        leafAtEven = 1;
    for(int y : v[x])
    {
        if(y==p) continue;
        leafAtOdd+=even[y];
        leafAtEven+=odd[y];
    }
    //cout<<x<<" "<<oddLeaf<<" "<<evenLeaf<<" "<<leafAtOdd<<" "<<leafAtEven<<"\n";
    oddAns[x] += oddLeaf*leafAtEven + evenLeaf*leafAtOdd;
    evenAns[x] += oddLeaf*leafAtOdd + evenLeaf*leafAtEven;
    ll newEven = oddLeaf + leafAtOdd;
    ll newOdd = evenLeaf + leafAtEven;
    for(int y : v[x])
    {
        if(y==p) continue;
        solve(y, x, newEven-even[y], newOdd-odd[y]);
    }
    
}
int main()
{
    int n,x,y;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    //calculate answer where both leafs are in subtree
    dfs(1);
    for(int i=1;i<=n;i++)
        oddAns[i]/=2,evenAns[i]/=2;
    //calculate answer where only one leaf is in subtree
    solve(1,0,0,0);
    for(int i=1;i<=n;i++)
        printf("%lld %lld\n",oddAns[i],evenAns[i]);
    return 0;
}
