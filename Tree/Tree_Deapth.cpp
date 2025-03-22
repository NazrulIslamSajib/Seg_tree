#include<bits/stdc++.h>
using namespace std;
int deapth[100010];
vector<int>arr[100010];
///https://www.spoj.com/problems/PT07Z/
///ekhane 2 bar dfs calate hbe prothome root theke farest node nibo jar deapth beshi
///then oi node theke abar dfs calale most deapth ber hoye jabe..
///deapth mane hocche 1 ta mode theke arek ta node e jaoyar durotto.
void dfs(int u,int par)
{

    for(auto v:arr[u])
    {
      if(v==par)
      {
        continue;
      }
      deapth[v]=deapth[u]+1;
      dfs(v,u);

    }
    return;
}
int main()
{
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       int n;
       cin>>n;
       for(int i=1;i<=n-1;i++)
       {
           int u,v;
           cin>>u>>v;
           arr[u].push_back(v);
           arr[v].push_back(u);
       }
       dfs(1,-1);
       int most=1;
       for(int i=1;i<=n;i++)
       {
           if(deapth[i]>deapth[most])
           {
              most=i;
           }
       }
       for(int i=1;i<=n;i++)
       {
           deapth[i]=0;
       }
       dfs(most,-1);
       int ans=0;
       for(int i=1;i<=n;i++)
       {
           if(deapth[i]>deapth[most])
           {
              most=i;
              ans=deapth[i];
           }
       }
       cout<<ans<<endl;



    }
    return 0;
}

