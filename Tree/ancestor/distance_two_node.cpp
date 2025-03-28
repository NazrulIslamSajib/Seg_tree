#include<bits/stdc++.h>
using namespace std;
const int mx=1e5;
vector<pair<int,int>>arr[mx];
int ancestor[mx][25];
long long value[mx];
int depth[mx];
///https://www.spoj.com/problems/QTREE2/
///2 ta node er modde distance
void dfs(int u,int par)
{
    for(auto [v,w]:arr[u])
    {
        if(v==par) continue;
        depth[v]=depth[u]+1;
        value[v]=value[u]+w;
        for(int i=0;i<=20;i++)
        {
          ancestor[v][i]=-1;
        }
        ancestor[v][0]=u;
        for(int i=1;i<=20;i++)
        {
            int v1=ancestor[v][i-1];
            if(v1==-1) break;
            ancestor[v][i]=ancestor[v1][i-1];
        }
        dfs(v,u);
    }
}
int getAncestor(int x,int k)
{
    for(int i=0;i<=20;i++)
    {
        if((1<<i)&k)
        {
            x=ancestor[x][i];
            if(x==-1)
            {
                return -1;
            }
        }
    }
    return x;
}
int get_lca(int x,int y)
{
    if(depth[x]>depth[y])
    {
        x=getAncestor(x,depth[x]-depth[y]);
    }
    else
    {
        y=getAncestor(y,depth[y]-depth[x]);
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--)
    {
        if(ancestor[x][i]==ancestor[y][i])
        {

        }
        else
        {
            x=ancestor[x][i];
            y=ancestor[y][i];
        }
    }
    return ancestor[x][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            depth[i]=0;
            arr[i].clear();
        }
        for(int i=1;i<=n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            arr[u].push_back({v,w});
            arr[v].push_back({u,w});
        }
        for(int i=0;i<=20;i++)
        {
            ancestor[1][i]=-1;
        }
        memset(ancestor,-1,sizeof(ancestor));
        dfs(1,-1);
        while(1)
        {
            string s;
            cin>>s;
            if(s=="DIST")
            {
                int u,v;
                cin>>u>>v;
                int lca=get_lca(u,v);
                long long ans=value[u]+value[v]-2*value[lca];
                cout<<ans<<endl;
            }
            else if(s=="KTH")
            {
               int u,v,k;
               cin>>u>>v>>k;
               k--;
               int lca=get_lca(u,v);
               int d1=depth[lca];
               int d2=depth[u];
               if(d2-d1>=k)
               cout<<getAncestor(u,k)<<endl;
               else
               {
                   int totalv=depth[v]-depth[lca];
                   int k1=k-(d2-d1);
                   k1=totalv-k1;
                   cout<<getAncestor(v,k1)<<endl;
               }
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}


