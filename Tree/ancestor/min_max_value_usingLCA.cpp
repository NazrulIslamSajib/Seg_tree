#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
vector<pair<int,int>>arr[mx];
int ancestor[mx][25];
int depth[mx];
pair<int,int>table[mx][25];
const int mx1=1e18;
///min max value using lca
///https://www.spoj.com/problems/DISQUERY/
void dfs(int u,int par,int val)
{
     ancestor[u][0]=par;
     table[u][0]={val,val};
     for(int i=1;i<=20;i++)
     {
        int v1=ancestor[u][i-1];
        if(v1==-1) break;
        ancestor[u][i]=ancestor[v1][i-1];
        table[u][i]={min(table[u][i-1].first,table[v1][i-1].first),
        max(table[u][i-1].second,table[v1][i-1].second)};
    }
    for(auto [v,value]:arr[u])
    {
        if(v==par) continue;
        depth[v]=depth[u]+1;
        dfs(v,u,value);
    }
}
pair<int,pair<int,int>> getAncestor(int x,int k)
{
    pair<int,int>p={mx1,-1};
    for(int i=0;i<=20;i++)
    {
        if((1<<i)&k)
        {
            p={min(p.first,table[x][i].first),max(p.second,table[x][i].second)};
            x=ancestor[x][i];
            if(x==-1)
            {
                return {-1,{-1,-1}};
            }
        }
    }
    return {x,p};
}
pair<int,int> get_lca(int x,int y)
{
    pair<int,int>p={mx1,-1};
    if(depth[x]>depth[y])
    {   auto q=getAncestor(x,depth[x]-depth[y]);
        x=q.first;
        p={min(p.first,q.second.first),max(p.second,q.second.second)};
    }
    else
    {
        auto q=getAncestor(y,depth[y]-depth[x]);
        y=q.first;
        p={min(p.first,q.second.first),max(p.second,q.second.second)};
    }
    if(x==y) return p;
    for(int i=19;i>=0;i--)
    {
        if(ancestor[x][i]==ancestor[y][i])
        {

        }
        else
        {
            int min1=min(table[x][i].first,table[y][i].first);
            p.first=min(p.first,min1);
            int max1=max(table[x][i].second,table[y][i].second);
            p.second=max(max1,p.second);
            x=ancestor[x][i];
            y=ancestor[y][i];
        }
    }
    int min1=min(table[x][0].first,table[y][0].first);
    p.first=min(p.first,min1);
    int max1=max(table[x][0].second,table[y][0].second);
    p.second=max(max1,p.second);
    return p;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
        int n,q;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            arr[u].push_back({v,w});
            arr[v].push_back({u,w});
        }
        memset(ancestor, -1, sizeof(ancestor));
        dfs(1,-1,0);
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            pair<int,int>p=get_lca(x,y);
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
    return 0;
}
