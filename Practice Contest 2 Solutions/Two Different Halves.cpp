/*Two Different Halves

Given a string containing characters from a-z, find if it is possible to rearrange the string in such a way such that first half of the string has no characters present in the second half of the string. The length of the string is even.

*/


#include <bits/stdc++.h>
using namespace std;
 
char ch[10001];
int a[5001][27],b[26];
 
int main() {
	int t,len,i,j,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
	    scanf(" %s",ch);
	    len=strlen(ch);
	    for(j=0;j<26;j++)
	    b[j]=0;
	    for(j=0;j<=len/2;j++)  
            {
		for(k=0;k<=26;k++)  
		a[j][k]=0;        
            } 
	    for(j=0;j<len;j++)
	    b[ch[j]-97]++;
	    for(j=0;j<=26;j++)
	    a[0][j]=1;
	    for(j=1;j<=len/2;j++)
	    a[j][0]=0;
	    for(j=1;j<=len/2;j++)  
	    {
		for(k=1;k<=26;k++)  
		{
		    a[j][k]=a[j][k-1];
		    if(j>=b[k-1])
		    {
		        if(a[j-b[k-1]][k-1]==1)
		        a[j][k]=1;
		    }
		    //a[j][k]=a[j][k]||a[j-b[k-1]][k-1];
		}
            }
            if(a[len/2][26]==1)
            printf("YES\n");
            else
            printf("NO\n");
	}
	return 0;
}
