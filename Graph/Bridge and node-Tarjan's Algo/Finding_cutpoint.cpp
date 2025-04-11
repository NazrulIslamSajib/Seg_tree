#include<bits/stdc++.h>
using namespace std;
int clk=1;
const int mx=1e5;
vector<pair<int,int>>bridges;
bool vis[mx];
int st[mx];
int low[mx],n,m;
vector<int>arr[mx];
int adjcmp[mx];
///undirected graph using Tarjan’s Algorithm finding cut point.
void dfs(int u,int par)
{
    st[u]=low[u]=clk;
    clk++;
    bool parent=false;
    vis[u]=true;
    int children=0;
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
            if(low[v]>=st[u] && par!=-1) ///v theke u er upore jaite pare nai
            {
               adjcmp[u]++;
               children++;
            }
        }
    }
    if(par==-1 && children>1) /// root er jodi 2 bar tar odik child thake
    {
        adjcmp[u]=children-1; ///aro koto gula extra new component pabo . ager ta dora lagbe na root.
    }
}
void finding_cutpoint()
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        adjcmp[i]=0;
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
        finding_cutpoint();
        for(int i=1;i<=n;i++)
        {
            if(adjcmp[i]>=1)
            {
                cout<<"Cutpoint :--> "<<i<<" "<<"korle koyta hbe extra : "<<adjcmp[i]<<endl;
            }
        }



    }
    return 0;
}



