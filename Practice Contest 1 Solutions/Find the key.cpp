/*

Find the Key
--------------------------------------------



You are given two strings : 's1' and 's2'. 's2' is the encrypted form of the 's1'. Each string is encrypted using a specific key.

The encryption algorithm is as follows :

String 's1' is divided into 'z' non-overlapping substrings of length x_1, x_2, x_3....x_z. Sum of length of all the substrings is equal to the length of 's1'. All the substrings have a non-zero length.
Now all the characters in each of the 'z' substrings are circularly right rotated by 'y' (Circular right rotation of character 'a' by 5 gives 'f', similarly circular right rotation of character 'w' by 6 gives 'c') . Hence, 'i'th substring of length 'x_i' is circularly right rotated by 'y_i' (0<=y_i<=25). No two consecutive substrings have the same y_i.
The key for the encription of string s1 is : x_1 y_1 x_2 y_2 x_3 y_3 ..... x_z y_z
You'll be given the string s1 and s2, and you have to print the key.

For better understanding of the problem, check the sample input/output.

Input Format

There are 'T' test cases. Each test case consist of two strings, s1 and s2 on different lines.

Constraints

1<= T <=100

1<= length of s1, length of s2 <= 10^5

length of s1 = length of s2

s1 and s2 consists of only smaller case english alphabets.

Output Format

Print the key for each test case on a new line. For exact format, check the sample input/output.

Sample Input 0

2
harrypotter
kdccjttyyjr
hermionegranger
jgtqmsriksbohfs


Sample Output 0

2 3 3 11 1 4 4 5 1 0 
3 2 6 4 6 1 


Explanation 0

In the first test case:

"ha" (length = 2) right rotated by 3 gives "kd".(x_1 = 2 and y_1 = 3)

"rry" (length = 3) right rotated by 11 gives "ccj".(x_2 = 3 and y_2 = 11)

"p" (length = 1) right rotated by 4 gives "t".(x_3 = 1 and y_3 = 4)

"otte" (length = 4) right rotated by 5 gives "tyyj".(x_4 = 4 and y_4 = 5)

"r" (length = 1) right rotated by 0 gives "r".(x_5 = 1 and y_5 = 0)

Hence representing the key as "x_1 y_1 x_2 y_2 x_3 y_3 x_4 y_4 x_5 y_5" gives "2 3 3 11 1 4 4 5 1 0"



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
vector< pair<ll, ll> > polygon;  




int main() {
   ios_base::sync_with_stdio(false);   
   int t, it;
   cin>>t;
   while(t--)
   {
      string s1, s2;
      int i, j, n, x, y;
      cin>>s1>>s2;
      n = s1.length();

      for(i=0; i<n;)
      {
        x = (s2[i] - s1[i] + 26)%26;
        y = 0;
        while(i<n && (s2[i] - s1[i] + 26)%26 == x)
        {
          i++;
          y++;
        }

        cout<<y<<" "<<x<<" ";
      }
      cout<<endl;
   }
   
   return 0;
} 