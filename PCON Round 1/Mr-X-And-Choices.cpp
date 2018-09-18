/*--------------------------------
Problem Statement
https://www.hackerrank.com/contests/pcon-round-1/challenges/mr-x-and-choices
Explanation
The question required a simple implementation in STL.
You were required to sort the input according to following criteria
a) Sort in decreasing order according to the sum of co-ordinates
b) Sort in ascending order according to the x co-ordinate(smaller x should be given higher preference)
------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
    int val1=a.first+a.second;
    int val2=b.first+b.second;
    if(val1!=val2) //Comparing on the basis of sum only when the sums are different
    {
        return (val1>val2);  //Return true if 'a' is supposed to come before 'b' after sorting
    }
    //Comparing on the basis of x(first value) if the sums are different
    return (a.first<b.first);    //Return true if 'b' is supposed to come before 'a' after sorting
    
}
int main()
{
    int n;
    cin>>n;
    assert(n>=1 && n<= 1000000);
    int x,y;
    vector< pair<int,int> > v(n);
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        assert(x>=1 && x<= 1000000);
        assert(y>=1 && y<= 1000000);
        v.push_back({x,y});
    }
    int k;
    cin>>k;
    assert(k<=n);
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<k;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    return 0;
}
