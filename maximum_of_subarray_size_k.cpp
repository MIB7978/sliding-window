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

vector<int> maximum_of_size(int arr[],int n,int k)
{
   vector<int> v ;
   for(int i=0;i<=n-k;i++)
   {
   	int mx = INT_MIN;
       for(int j = i;j<i+k;j++)
         mx = max(mx,arr[j]);
        v.push_back(mx);
   }
   return v;
}

// optimised 
vector<int> optimised(int arr[],int n,int k)
{
	vector<int> v ; 
	 list<int> l;
	 int i,j;
	 i=j=0;
	 while(j<n)
	 {
	 	 while(!l.empty() && l.back()<arr[j])
	 	 	l.pop_back();
	 	 l.push_back(arr[j]);
	 	 if(j-i+1 == k)
	 	 {
	 	 	  v.push_back(l.front());
	 	 	  if(arr[i]==l.front())
	 	 	  	l.pop_front();
	 	 	  i++;
	 	 }
	 	 j++;
	 }
	 return v ; 
}

int main()
{
 fast
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n , k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    	vector<int> v =optimised(arr,n,k);
       for(int i : v)
       	  cout<<i<<" ";


}