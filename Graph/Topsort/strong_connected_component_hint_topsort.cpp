#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
vector<int>arr1[mx];
vector<int>arr2[mx];
int vis1[mx];
int vis2[mx];
vector<int>ans;
vector<int>ans1[mx];
///https://cses.fi/problemset/task/1682/
///eta hocche strong connected component
///strong connected component ki ? seta hocce kono ekta u-->v hole v--U hbe.
///korbo protome ekta normal dfs calabo sekhan theke ekebare backtrak kore vector e push
///korbo then oi verter ke revese kore abar dfs calabo arek ta je adaceny matrix ulto ache
///seta modde dfs calbo ekhn jara jara visited hbe tara mile ekta strong connected component
///karon ulto korle kintu direction change hoye jay tai one way gula off hoye jay ..
///ei karone jegula visited hbe tarai actual strong connected component
void dfs(int u)
{
    if(vis1[u]==1)
    {
        return;
    }
    vis1[u]=1;
    for(auto v:arr1[u])
    {
        if(vis1[v]==0)
        {
            dfs(v);
        }
    }
    ans.push_back(u);
    ///cout<<u<<" ";
}
void dfs1(int u,int par)
{
    if(vis2[u]==1)
    {
        return;
    }
    vis2[u]=1;
    for(auto v:arr2[u])
    {
        if(vis2[v]==0)
        {
            dfs1(v,par);
        }
    }
    ans1[par].push_back(u);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
//    cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            vis1[i]=0;
            vis2[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            arr1[u].push_back(v);
            arr2[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis1[i]==0)
            {
                dfs(i);
            }
        }
        reverse(ans.begin(),ans.end());
        vector<long long>took;
        for(auto u:ans)
        {
            if(vis2[u]==0)
            {
                dfs1(u,u);
                took.push_back(u);

            }
        }
        if(took.size()==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
            reverse(took.begin(),took.end());
            for(int i=0;i<2;i++)
            {
                cout<<took[i]<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}


