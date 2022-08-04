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


bool chkanagram(string s,map<char,int> m )
{
	map<char,int> chk;

     for(int i=0;i<s.length();i++){
     	chk[s[i]]++;
     }
     for(auto i:m)
     {
     	 if(chk.count(i.first)==0||chk[i.first]!=i.second)
     	 	return false;
     }
    return true; 	
}

int getAnagram(string s,string t)
{
	int count = 0;
	map<char,int> m;
	int n = s.length();
	int k = t.length();
	for(int i=0;i<k;i++)
		m[t[i]]++;
      for(int i=0;i<=n-k;i++)
      {
      	string temp="";
         for(int j=i;j<i+k;j++)
           temp+=s[j];
        if(chkanagram(temp,m)==true)
        	count++;
      }
      return count;
}

// optimised 
int optimised(string s,string t)
{
   int n = s.length();
   int k = t.length();
   int i , j;
   i=j=0;
   map<char ,int> m ;
   for(int i=0;i<k;i++)
   	m[t[i]]++;
   int count = m.size();
   int res = 0;
   while(j<n)
   {
      if(m.count(s[j])!=0)
      {
      	   m[s[j]]--;
      	   if(m[s[j]]==0) count--;
      }
      if(j-i+1 == k)
      {
      	   if(count==0)
      	   	res++;
      	   if(m.count(s[i])!=0)
      	   {
      	   	   if(m[s[i]]==0)
      	   	   	count++;
      	   	   m[s[i]]++;
      	   }
      	   i++;
      }
      j++;
   }
   return res;	 
}
int main()
{
 fast
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string txt,pat;
    cin>>txt>>pat;

    cout<<optimised(txt,pat);


}
