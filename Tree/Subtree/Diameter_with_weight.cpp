#include<bits/stdc++.h>
using namespace std;
int deapth[100010];
vector<pair<int,int>>arr[100010];
///https://lightoj.com/problem/farthest-nodes-in-a-tree#google_vignette
void dfs(int u,int par)
{

    for(auto [v,w]:arr[u])
    {
      if(v==par)
      {
        continue;
      }
      deapth[v]=deapth[u]+w;
      dfs(v,u);
    }
    return;
}
int main()
{
    long long tt=1;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
       int n;
       cin>>n;
       for(int i=0;i<=n;i++)
       {
           arr[i].clear();
       }
       for(int i=1;i<=n-1;i++)
       {
           int u,v,w;
           cin>>u>>v>>w;
           arr[u].push_back({v,w});
           arr[v].push_back({u,w});
       }
       dfs(1,-1);
       int most=1;
       for(int i=0;i<=n;i++)
       {
           if(deapth[i]>deapth[most])
           {
              most=i;
           }
       }
       for(int i=0;i<=n;i++)
       {
           deapth[i]=0;
       }
       dfs(most,-1);
       int ans=0;
       for(int i=0;i<=n;i++)
       {
           if(deapth[i]>deapth[most])
           {
              most=i;
              ans=deapth[i];
           }
       }
       cout<<"Case "<<t<<": "<<ans<<endl;



    }
    return 0;
}

