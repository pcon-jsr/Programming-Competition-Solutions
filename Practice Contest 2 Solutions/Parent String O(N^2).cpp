/* Parent String

You are given two strings 's1' and 's2'. You need to find the total number of unique shortest strings, having both strings(s1 and s2) as its subsequence.

*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

char ch[51],cha[51];
int len1,len2;
long long int ans,val;

int main() {
    int t,i,j,k;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf(" %s %s",ch,cha);
        len1=strlen(ch);
        len2=strlen(cha);
        ans=0;
        long long int a[len1+1][len2+1],b[len1+1][len2+1];
        //Array a to find length of supersequence
        //Array b to find number of such sequences
        for(j=0;j<=len2;j++)
            a[0][j]=j;
        for(j=1;j<=len1;j++)
            a[j][0]=j;
        for(j=1;j<=len1;j++)
        {
            for(k=1;k<=len2;k++)
            {
                if(ch[j-1]==cha[k-1])
                    a[j][k]=1+a[j-1][k-1];
                else
                    a[j][k]=1+min(a[j-1][k],a[j][k-1]);
            }
        }
        for(j=0;j<=len1;j++)
        {
            for(k=0;k<=len2;k++)
            b[j][k]=0;
        }
        if(ch[len1-1]==cha[len2-1])
            b[len1-1][len2-1]=1;
        else
        {
            if(a[len1-1][len2]<a[len1][len2-1])
            b[len1-1][len2]=1;
            else if(a[len1-1][len2]>a[len1][len2-1])
            b[len1][len2-1]=1;
            else
            {
                b[len1-1][len2]=1;
                b[len1][len2-1]=1;
            }
        }
        for(j=len1;j>=0;j--)
        {
            for(k=len2;k>=0;k--)
            {
                if(j==0 && k==0)
                    break;
                if(j==0)
                    b[j][k-1]+=b[j][k];
                else if(k==0)
                    b[j-1][k]+=b[j][k];
                else if(ch[j-1]==cha[k-1])
                    b[j-1][k-1]+=b[j][k];
                else if(a[j-1][k]<a[j][k-1])
                    b[j-1][k]+=b[j][k];
                else if(a[j-1][k]>a[j][k-1])
                    b[j][k-1]+=b[j][k];
                else
                {
                    b[j-1][k]+=b[j][k];
                    b[j][k-1]+=b[j][k];
                }
            }
        }
        cout<<b[0][0]<<endl;
    }
    return 0;
}
