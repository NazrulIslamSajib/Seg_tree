https://codeforces.com/contest/2149/problem/G 
#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int>index[mx];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    while(tt--)
    {
         long long n,q;
         cin>>n>>q;
         long long arr[n+10];
         map<long long,long long>mp,mp1;
         for(int i=1;i<=n;i++)
         {
             cin>>arr[i];

             if(!mp.count(arr[i]))
             {
                 mp[arr[i]]=mp.size();
                 mp1[mp[arr[i]]]=arr[i];
             }
             arr[i]=mp[arr[i]];
         }
         for(int i=1;i<=n;i++)
         {
             index[arr[i]].push_back(i);
         }
         while(q--)
         {
               long long l,r;
               cin>>l>>r;
               long long need=((r-l+1)/3)+1;
               vector<long long>v;
                for(int i=1;i<=50;i++)
                {
                     long long x=rng()%(r-l+1)+l;
                     x=arr[x];
                     if(l>index[x].back())
                     {
                         continue;
                     }
                     long long lo=0,hi=(index[x].size())-1,l1=-1,r1=-1;
                     while(lo<=hi)
                     {
                         long long mid=(lo+hi)>>1;
                         if(index[x][mid]<l)
                         {
                             lo=mid+1;
                         }
                         else
                         {   l1=mid;
                             hi=mid-1;
                         }
                     }
                     lo=0,hi=(index[x].size())-1;
                     while(lo<=hi)
                     {
                         long long mid=(lo+hi)>>1;
                         if(index[x][mid]<=r)
                         {
                             r1=mid;
                             lo=mid+1;
                         }
                         else
                         {
                             hi=mid-1;
                         }
                     }
                     if(r1-l1+1>=need && l1!=-1 && r1!=-1)
                     {

                         if(v.size()==1 && v[0]!=mp1[x])
                         {
                              v.push_back(mp1[x]);
                         }
                         if(v.empty())
                         {
                             v.push_back(mp1[x]);
                         }
                         if(v.size()==2)
                         {
                             break;
                         }
                     }
                }
                if(!v.empty())
                {
                    if(v.size()>=2)
                    {
                         if(v[0]>v[1])
                         {
                             swap(v[0],v[1]);
                         }
                    }
                    for(auto x:v)
                    {
                        cout<<x<<" ";
                    }
                    cout<<endl;
                }
                else
                {
                    cout<<-1<<endl;
                }

         }
          for(int i=1;i<=n;i++)
         {
             index[arr[i]].clear();
         }

    }
    return 0;
}
