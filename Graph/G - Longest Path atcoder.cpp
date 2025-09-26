#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+2;
vector<int>arr[mx];
int in[mx];
queue<int>q;
int in1[mx];
int level[mx]; 
///https://atcoder.jp/contests/dp/tasks/dp_g
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
        long long n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
             int u,v;
             cin>>u>>v;
             arr[u].push_back(v);
             in[v]++;
        }
        for(int i=1;i<=n;i++)
        {
             if(in[i]==0)
             {
                 q.push(i);
             }
        }
        while(!q.empty())
        {
             long long u=q.front();
             q.pop();
             for(auto v:arr[u])
             {
                  level[v]=max(level[v],level[u]+1);
                  in1[v]++;
                  if(in1[v]==in[v])
                  {
                      q.push(v);
                  }
             }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,level[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

