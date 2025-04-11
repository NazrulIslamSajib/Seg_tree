#include<bits/stdc++.h>
using namespace std;
int clk=1;
const int mx=1e5;
vector<pair<int,int>>bridges;
bool vis[mx];
int st[mx];
int low[mx],n,m;
vector<int>arr[mx];
///undirected graph using Tarjan’s Algorithm.
void dfs(int u,int par)
{
    st[u]=low[u]=clk;
    clk++;
    bool parent=false;
    vis[u]=true;
    for(auto v:arr[u])
    {
        if(v==par && parent==false) ///double edge thakle tai dichi
        {
            parent=true;
            continue;
        }
        if(vis[v]==true) ///agei visited hoye geche
        {
           low[u]=min(low[u],st[v]);
        }
        else if(vis[v]==false)
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>st[u]) ///v theke u er upore jaite pare nai
            {
                bridges.push_back({u,v});
            }
        }
    }
}
void finding_bridge()
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            dfs(i,-1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {

        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        finding_bridge();
        for(auto [x,y]: bridges)
        {
            cout<<x<<" "<<y<<endl;
        }

    }
    return 0;
}



