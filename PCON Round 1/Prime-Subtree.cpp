/*Challenge Link:- https://www.hackerrank.com/contests/pcon-round-1/challenges/prime-subtree/problem
The solution of the problem is to create a sum tree where each node has a value 1 or 0 if the given value of the node is prime or not.
We preprocess the answer for all nodes in a single dfs traversal.
The dfs starts from the root node i.e., node 1 and then goes on until it finds a leaf node.
The leaf node will have only one other node connected to it that is the parent node except for node 1 can have the same property.
So for a leaf node if the value is prime it has answer 1 otherwise 0.
Now for every other node, we just add the answers of all the child nodes plus 1 or 0 accordingly if the value of that node itself is prime or not.
Now since we have obtained answers for all the nodes, we can answer the query directly without applying dfs everytime.
*/
#include <bits/stdc++.h>
using namespace std;

int a[1000001],b[500001],ans[500001];

vector <int> v1[500001];

void soe()                                                //To find if a number is prime
{
	int i,j;
	for(i=2;i<=1000;i++)
	{
		if(a[i]==1)
		{
			for(j=i*i;j<=1000000;j+=i)
			{
				a[j]=0;
			}
		}
	}
}

void dfs(int node, int par)
{
	int i,j;
	if(v1[node].size()==1 && node!=1)                         //Check for the leaf node
	{
		if(a[b[node]]==1)
			ans[node]=1;
		else
			ans[node]=0;
		return;
	}
	for(i=0;i<v1[node].size();i++)                           //DFS Traversal
	{
		if(v1[node][i]!=par)
			dfs(v1[node][i],node);
	}
	for(i=0;i<v1[node].size();i++)                           //Obtaining answer from their
	{                                                        //Child
		if(v1[node][i]!=par)
			ans[node]+=ans[v1[node][i]];
	}
	if(a[b[node]]==1)                                       //Checking if the node value
		ans[node]+=1;                                   //is prime
}

int main()
{
	int n,u,v,q,i,j;
	scanf("%d",&n);
	for(i=2;i<=1000000;i++)
	{
		a[i]=1;
	}
	soe();
	a[1]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%d %d",&u,&v);
		v1[u].push_back(v);
		v1[v].push_back(u);
	}
	dfs(1,-1);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d",&u);
		printf("%d\n",ans[u]);
	}
	return 0;
}
