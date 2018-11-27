/* Problem Statement:- Given two integers N and K, find the Kth positive integer which is divisible by atleast one of the factors (except 1) of N. */

/* Solution :- It can be easily understood that we only need to consider the prime factors as all the other factors must be a multiple of some prime factor and so all numbers divisible by such numbers is already divisible by the prime factor. Now the next step of the solution is to find the number of numbers divisible by the factors from 1 to say any number x. This can be obtained by using inclusion-exclusion principle. It can be clearly observed that for any y greater than x the number of numbers divisible by factors for 1 to y is greater than or equal to 1 to x. So we can apply binary search to obtain the number where the number of numbers divisible by the factors is equal to k.*/


#include <bits/stdc++.h>
using namespace std;

long long int a[1000001];

void soe()                                       //Sieve to find lowest prime factor
{
	long long int i,j;
	for(i=2;i<=1000;i++)
	{
		if(a[i]==i)
		{
			for(j=i*i;j<=1000000;j+=i)
			{
				if(a[j]==j)
					a[j]=i;
			}
		}
	}
}

int main()
{
    long long int t,n,k,flag,low,mid,high,val,val1,cnt,ans,i,j,l;
    scanf("%lld",&t);
    for(i=2;i<=1000000;i++)
    	a[i]=i;
    soe();
    long long int b[7],index1,c[128][2],index2;
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&n,&k);
        val=n;
        index1=0;
        j=2;
        while(j<=sqrt(val))                  //Storing prime factors
        {
            if(val%j==0)
            {
            	while(val%j==0)
            		val/=j;
            	b[index1++]=j;
            }
            j++;
        }
        if(val>1)
        	b[index1++]=val;
        index2=0;
        long long int pow_set_size=pow(2,index1);
        for(j=1;j<pow_set_size;j++)   // Inclusion-Exclusion
        {
            val1=1;
            cnt=0;
            for(l=0;l<index1;l++) 
            { 
                if(j & (1<<l))
                {
                    if(1000000000000000000/val1>=b[l])
                    val1=val1*b[l];
                    else
                    val1=1000000000000000001;
                    cnt++;
                }
            }
            c[index2][0]=val1;
            if(cnt%2!=0)
            c[index2][1]=1;
            else
            c[index2][1]=0;
            index2++;
        }
        low=1;
        high=1000000000000000000;
        while(low<=high)                  //Binary Search
        {
            if(low==high)
            {
                ans=low;
                break;
            }
            mid=(low+high)/2;
            val=0;
            for(j=0;j<index2;j++) 
            {
                if(c[j][1]==1)
                val+=mid/c[j][0];
                else
                val-=mid/c[j][0];
            }
            if(val<k)
            low=mid+1;
            else
            high=mid;
        }
        cout<<ans<<endl;
    }
    return 0;
} 


