#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
int value[mx];
vector<pair<int,int>>arr[mx];
int subtree[mx];
int weight[mx]; 
///https://codeforces.com/contest/682/problem/C
void dfs1(int u,int par)
{
   subtree[u]=1;
   for(auto [v,w]:arr[u])
   {
       if(v==par)
       {
           continue;
       }
       dfs1(v,u);
       subtree[u]=subtree[v]+subtree[u]; ///nijer ager ta and tar child er subtree
   }
}
void dfs2(int u,int par)
{
    for(auto [v,w]:arr[u])
    {
        if(v==par)
        {
            continue;
        }
        weight[v]=weight[u]+w;
        if(weight[v]<0)
        {
            weight[v]=0;
        }
        dfs2(v,u);
    }
}
int ans=0;
void dfs3(int u,int par)
{
    for(auto [v,w]:arr[u])
    {
        if(v==par)
        {
           continue;
        }
        if(weight[v]>value[v])
        {
            ////cout<<v<<" "<<value[v]<<" "<<weight[v]<<endl;
            ans+=subtree[v];
        }
        else
        {
            dfs3(v,u);
        }
    }
}
int main()
{
    long long tt=1;
   /// cin>>tt;
    while(tt--)
    {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++)
       {
           cin>>value[i];
       }
       for(int i=1;i<=n-1;i++)
       {
           int u,val;
           cin>>u>>val;
           arr[i+1].push_back({u,val});
           arr[u].push_back({i+1,val});
       }
       dfs1(1,-1);
       dfs2(1,-1);
       dfs3(1,-1);
       /*
       for(int i=1;i<=n;i++)
       {
           cout<<i<<" "<<weight[i]<<endl;
       }
       */
       cout<<ans<<endl;
    }
    return 0;
}
