//https://www.hackerrank.com/contests/pcon-round-1/challenges/01divisors/problem

//This problem can be solved using BIT or segment tree

//1. We will preprocess number of divisors upto max element.
//2. We will sort query in ascending order of L.
//3. For every query we will first update all number 
//   till L in BIT. Now, we can query from BIT
//   total numbers whose  divisors is less than X.

//   Note: update(X) denotes we have found a number with divisor X.
//         Hence, for every number I<=L, we will call update(number_of_divisors(I)).

//Time complexity to calculate number of divisors O(Xlog(X)) 
//where X is max element(i.e 5*10^6).

//Time complexty to answer total query O(T*log(maximum_number_of_divisors)).

#include <bits/stdc++.h>
using namespace std;
const int N=5000010;

//noOfDivisors[i] will store the number of divisors of i.
//ans[i] will store the answer of ith query.
//BIT array for store the number of divisors.
int noOfDivisors[N],ans[N],BIT[N];


//structure to store the query.
struct fun{
    int l,x,id;
}q[N];


bool cmp(fun a, fun b)
{
    return a.l<b.l;
}


void upd(int x)
{
    while(x<=500)
    {
        BIT[x]+=1;
        x+=(x&-x);
    }
}


int query(int x)
{
    x=min(x,500);
    int r=0;
    while(x)
    {
        r+=BIT[x];
        x-=(x&-x);
    }
    return r;
}


int main()
{
    // number of divisor is calculated for all
    //numbers < N in Nlog(N).
    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
            noOfDivisors[j]++;
    }
    int t,l,x;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>l>>x;
        q[i]={l,x,i};
    }

    // query is sorted in ascending order of l.
    sort(q,q+t,cmp);

    //processed denotes that we have updated the divisors
    //in BIT upto the number processed.
    int processed=0;
    for(int i=0;i<t;i++)
    {
        while(processed<q[i].l)
        {
            upd(noOfDivisors[++processed]);
        }
        ans[q[i].id]=query(q[i].x-1);
    }

    for(int i=0;i<t;i++) cout<<ans[i]<<"\n";
    return 0;
}
