#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
vector<int>arr[mx];
int ancestor[mx][25];
int depth[mx];
///https://cses.fi/problemset/task/1688
void dfs(int u,int par)
{
    for(auto v:arr[u])
    {
        if(v==par) continue;
        depth[v]=depth[u]+1;
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
int get_lca(int x,int y)///least common ancestor
{
    if(depth[x]>depth[y]) ///2 tar level same korar jonno boro take choto kortechi
    {
        x=getAncestor(x,depth[x]-depth[y]);
    }
    else
    {
        y=getAncestor(y,depth[y]-depth[x]);
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--) ///upor theke nicher dike astechi
    {
        if(ancestor[x][i]==ancestor[y][i])
        {
          /// ith ancestor same hole kichu kora na
        }
        else
        {
            x=ancestor[x][i]; ///na hole tar oto ith value ta dekha lagbe
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
    ///cin>>tt;
    while(tt--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=2;i<=n;i++)
        {
            int u;
            cin>>u;
            arr[u].push_back(i);
        }
        for(int i=0;i<=20;i++)
        {
            ancestor[1][i]=-1;
        }
        dfs(1,-1);
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            cout<<get_lca(x,y)<<endl; ///least common ancestor ber korte hbe
        }
    }
    return 0;
}

