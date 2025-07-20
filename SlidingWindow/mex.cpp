#include<bits/stdc++.h>
using namespace std;
///https://cses.fi/problemset/task/3219
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
         long long n,k;
         cin>>n>>k;
         long long arr[n+10];
         for(int i=1;i<=n;i++)
         {
             cin>>arr[i];
         }
         set<long long>st;
         map<long long,long long>mp;
         for(int i=0;i<=k;i++)
         {
             st.insert(i);
         }
         arr[0]=-1;
         for(int i=1;i<=n;i++)
         {
             if(i>=k)
             {
                  mp[arr[i-k]]--;
                  if(mp[arr[i-k]]==0)
                  {
                      st.insert(arr[i-k]);
                  }
                  if(st.find(arr[i])!=st.end())
                  {
                      st.erase(arr[i]);
                  }
                  mp[arr[i]]++;
                  cout<<*st.begin()<<" ";
             }
             else
             {
                 if(st.find(arr[i])!=st.end())
                 {
                     st.erase(arr[i]);
                 }
                 mp[arr[i]]++;
             }
         }
    }
    return 0;
}
