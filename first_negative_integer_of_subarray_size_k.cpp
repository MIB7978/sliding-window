#include<bits/stdc++.h>
#define ll long long int
#define cin(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define fast ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define forl(i,a,n) for( i=a;i<n;i++)
#define ld long double
#define cout(a,n) for(int h=0;h<n;h++)cout<<a[h]<<" ";
#define mod 1000000009
#define nl cout<<"\n";
#define de cout<<"here";
using namespace std;

// brute force
vector<int> getsubarray(int arr[],int n,int k )
{
	vector<int> v;
	for(int i=0;i<=n-k;i++)
	{
		int num = 0;
        for(int j = i;j<i+k;j++)
        {
            if(arr[j]<0)
            {
            	num=arr[j];
            	break;
            }
        }
        v.push_back(num);
	}
	return v;
}

// optimised
vector<long long> optimised(int arr[],int n ,int k )
{
	vector<long long> v; 
	list<long long> l;
	int i,j;
	i=j=0;
	while(j<n)
	{
		if(arr[j]<0)
			l.push_back(arr[j]);
		if(j-i+1 == k)
		{
			if(!l.empty())
			v.push_back(l.front());
		   else
		   	v.push_back(0);
		   if(l.front()==arr[i])
		   	l.pop_front();

		   i++;
		}
		j++;
	}
	return v;
}

int main()
{
 fast
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,k ; 
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    vector<long long> v = optimised(arr,n,k);
    for(int i:v)
    	cout<<i<<" ";

}