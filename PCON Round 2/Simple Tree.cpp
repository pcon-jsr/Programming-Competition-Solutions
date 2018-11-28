/*
problem:
https://www.hackerrank.com/contests/pcon-round-2/challenges/simple-tree/problem

Related Topic:
https://codeforces.com/blog/entry/62528

This problem can be solved using EulerTour and 
Slight modification in lazy propagation(Refer to the above link).

For any update in a subtree we can update it using intime and
out time of the node in EulerTour, lazily in o(logn).

Query can also be done in logn

overall time complexity: O( nlogn + qlogn).

*/



#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector< pi > 
const int N=100010;

int in[N],out[N],id[N],T=1;
vi v[N];
void euler_tour(int x,int p=0)
{
    in[x]=T;
    id[T++]=x;
    for(int y:v[x])
        if(y!=p) euler_tour(y,x);
    out[x]=T;
}
ll seg[4*N],lazy[4*N],mx[4*N],mn[4*N],a[4*N];

void modify(int ind)
{
    seg[ind]=seg[ind<<1]+seg[ind<<1|1];
    mx[ind]=max(mx[ind<<1],mx[ind<<1|1]);
    mn[ind]=min(mn[ind<<1],mn[ind<<1|1]);
}
void build(int ind,int l,int r)
{
    if(l==r)
    {
        seg[ind]=a[l];
        mx[ind]=a[l];
        mn[ind]=a[l];
        return ;
    }
    int m=(l+r)>>1;
    build(ind<<1,l,m);build(ind<<1|1,m+1,r);
    modify(ind);
}

void pushdown(int ind,int l,int r)
{
    if(lazy[ind]==-1||r<l) return;
    mx[ind]=lazy[ind];
    mn[ind]=lazy[ind];
    seg[ind]=1ll*(r-l+1)*lazy[ind];
    
    if(l!=r)
    lazy[ind<<1]=lazy[ind],
    lazy[ind<<1|1]=lazy[ind];
    lazy[ind]=-1;
    
}
bool breakCondition(int ind,int l,int r,int start,int end,int x)
{
    if(l>r||end<l||start>r||mx[ind]<=x)
        return true;
    return false;
}
bool tagCondition(int ind,int l,int r,int start,int end,int x)
{
    if(start<=l&&r<=end&&mn[ind]>=x) return true;
    return false;
}
void rangeUpd(int ind,int l,int r,int start,int end,int x)
{
    pushdown(ind,l, r);
    if(breakCondition(ind,l,r,start,end,x)) return ;
    if(tagCondition(ind,l,r,start,end,x))
    {
        mx[ind]=x;
        lazy[ind]=mx[ind];
        pushdown(ind,l,r);
        return;
    }
    int m=(l+r)>>1;
    rangeUpd(ind<<1,l,m,start,end,x);
    rangeUpd(ind<<1|1,m+1,r,start,end,x);
    modify(ind);
}

ll query(int ind,int l, int r,int start,int end)
{
    pushdown(ind,l,r);
    if(l>r||end<l||r<start) return 0ll;
    if(start<=l&&r<=end) return seg[ind];
    int m=(l+r)>>1;
    return query(ind<<1,l,m,start,end)+
    query(ind<<1|1,m+1,r,start,end);
}
int main()
{
    int n,q,x,y;
    cin>>n>>q;
    int b[n+1];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    euler_tour(1);
    T--;
    for(int i=1;i<=T;i++)
        a[i]=b[id[i]];
    build(1,1,T);
    memset(lazy,-1,sizeof lazy);
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            cin>>x>>y;
            rangeUpd(1,1,T,in[x],out[x]-1,y); 
        }
        else
        {
            cin>>x;
            cout<<query(1,1,T,in[x],out[x]-1)<<"\n";
        }
    }
    return 0;
}
