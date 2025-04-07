#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
vector<int>arr[mx];
map<int,int>vis;//0 nonvisited/1 visiting/2 visited
vector<int>ans;
int f=0;
/// topological order hocce 1--5--7
///kono vabe u--->v te jaoya jay tohole obbosoi u ta v er age push hbe
///https://cses.fi/problemset/task/1679/
///dfs caliye dekhbo shesh pojjonto jekhane jaoya jay sekhane jobo
///then eta ke vector e push korbo jodi vis==1 hoy tahole dekho ekhono dfs
///shesh hoy nai kintu se node abar jaiteche hole eta cycle ache tokhn Impossible
///then reverse korbo vector take karon tokhon topolocial order pabo.
void dfs(int u)
{
    if(vis[u]==2)
    {
        return;
    }
    vis[u]=1;
    for(auto v:arr[u])
    {
        if(vis[v]==1)
        {
            f=1;
            return;
        }
        else if(vis[v]==0)
        {
            dfs(v);
        }
    }
    vis[u]=2;
   /// cout<<u<<" ";
   ans.push_back(u);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
   // cin>>tt;
    while(tt--)
    {
       int n,m;
       cin>>n>>m;
       for(int i=1;i<=m;i++)
       {
           int u,v;
           cin>>u>>v;
           arr[u].push_back(v);
       }
       for(int i=1;i<=n;i++)
       {
           if(vis[i]==0)
           {
               dfs(i);
           }
       }
       if(f)
       {
       cout<<"IMPOSSIBLE"<<endl;
       continue;
       }
       reverse(ans.begin(),ans.end());
       for(auto x:ans)
       {
           cout<<x<<" ";
       }
       cout<<endl;
    }
    return 0;
}



