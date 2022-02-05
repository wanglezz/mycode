#include<bits/stdc++.h>
#define n 30
#define repeat_time 1000
using namespace std;
double ability[n],ans_mini,mini,sum[n/3];
int flag[n],ans_flag[n],temp;
void init()
{
	for(int i=0;i<n/3;i++)
	{
		flag[i]=i;
	}
	for(int i=n/3;i<n;i++)
	{
		flag[i]=-1;
	}
	mini=9999999;
}
int main()
{
	ans_mini=-1;
	srand(unsigned(time(NULL)));
	for(int i=0;i<n;i++)
	{
		cin>>ability[i];
	}
	for(int i=0;i<repeat_time;i++)
	{
		init();
		for(int j=0;j<n/3;j++) 
		{
			sum[j]=ability[j];
			temp=rand()%n;
			while(flag[temp]!=-1)
			{
				temp=rand()%n;
			}
			flag[temp]=j;
			sum[j]+=ability[temp];
			
			temp=rand()%n;
			while(flag[temp]!=-1)
			{
				temp=rand()%n;
			}
			flag[temp]=j;
			sum[j]+=ability[temp];
			mini=min(mini,sum[j]);
		}
		if (mini>ans_mini)
		{
			ans_mini=mini;
			for(int j=0;j<n;j++)
			{
				ans_flag[j]=flag[j];
			}
		}
	}
	cout<<ans_mini<<endl<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ans_flag[i]<<endl;
	}
} 

