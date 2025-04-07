#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
typedef pair<int,int>pii;
vector<pii>arr[mx];
long long dis[mx],n;
long long par[mx];
///https://lightoj.com/problem/country-roads 
///ekta node deoya thakbe bolte hbe oi node theke koto onnno node e jaite minimum kon value hbe seta bolte 
///oi value gula hbe oi pather maximum
void dijkstra(long long t,long long w1)
{
    for(int i=0;i<n;i++)
    {
        dis[i]=LLONG_MAX;
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,t});
    dis[t]=0;
    while(!pq.empty())
    {
        pii p=pq.top();
        int u=p.second;
        long long d=p.first;
        pq.pop();
        if(d>dis[u]) continue;
        for(auto x:arr[u])
        {
            long long cost=x.second;
            long long v=x.first;
            if(max(cost,d)<dis[v])
            {
                pq.push({max(cost,d),v});
                dis[v]=max(cost,d);

            }
        }
    }
    ////cout<<"sajib"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    cin>>tt;
    for(int tc=1;tc<=tt;tc++)
    {
         int m;
         cin>>n>>m;
         for(int i=0;i<n;i++)
         {
             arr[i].clear();
         }
         for(int i=1;i<=m;i++)
         {
             int u,v,w;
             cin>>u>>v>>w;
             arr[u].push_back({v,w});
             arr[v].push_back({u,w});
         }
         int q;
         cin>>q;
         dijkstra(q,0);
         cout<<"Case "<<tc<<":"<<endl;
         for(int i=0;i<n;i++)
         {
             if(dis[i]==LLONG_MAX) cout<<"Impossible"<<endl;
             else
             cout<<dis[i]<<endl;
         }

       }
    return 0;
}
