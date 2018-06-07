/*
Puzzle Me
---------------------------------------------------------------

As Foo and Bar are good buddies, they are playing a game.

Game is as follows :-

Foo and bar both can choose numbers between [1-10] (inclusive 1 and 10).
They keep a sum(total) of all the chosen numbers .
The first player to make a total of greater than or equal to n during its turn, wins.
If both players play optimally.

Predict the winner for every test case.

Example

Input: 
2 
12 
Bar 
33 
Foo

Output 
Bar 
Bar

Explanation

For first test case,

Bar is the first player so, Bar can choose any number between [1 -10] . and similarly Foo can also choose any number between [1 -10] .

Bar chooses 1

Foo chooses 1

  TOTAL =   2   after their first moves
Now,

Bar chooses 10

 TOTAL =   12   after Bar second moves
As Bar chooses 10 and achieved a total >= 12 already.So,Foo looses.

Input Format

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer n
The second line of each test case contains a string Bar or Foo,the player who starts the game.
Constraints

1<=T<=10^6
1<=n<=10^18
Output Format

For each test case, output the winner name i.e. Bar or Foo

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long
const ll p=1e9+7;

int main()
{
   // std::ios_base::sync_with_stdio(false);
  //  cin.tie(0);cout.tie(0);
  ll n,i,t,j,m;
  string s;
  cin>>t;
  while(t--)
  {
    cin>>n;
    cin>>s;
    if(s=="Foo")
    {
      if(n%11==0)
        cout<<"Bar\n";
      else
        cout<<"Foo\n";
    }
    else
    {
      if(n%11==0)
        cout<<"Foo\n";
      else
        cout<<"Bar\n";
    }
 }
    
}