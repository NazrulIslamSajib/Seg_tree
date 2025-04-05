#include<bits/stdc++.h>
using namespace std;
const int mx=6e4+10;
typedef pair<long long,long long> pii;
vector<pii>arr[mx];
long long dis[mx][3];
///https://vjudge.net/problem/UVA-12950
///amake bolche tumi 1 theke c te jao sortest distance ber koro
///kintu tomake even node gula bebohar korte hbe.
void dijkstra(int s,int d)
{
    for(int i=1;i<=d;i++)
    {
        dis[i][0]=INT_MAX;///even distance
        dis[i][1]=INT_MAX;///odd distance
    }
    priority_queue<pair<long long,pii>,vector<pair<long long,pii>>,greater<pair<long long,pii>>>pq;
    pq.push({0,{1,0}});
    while(!pq.empty())
    {
        long long d=pq.top().first;
        auto node=pq.top().second;
        int u=node.first;
        int k=node.second;
        pq.pop();
        if(d>dis[u][k]) continue;
        for(auto x:arr[u])
        {
            long long v=x.first;
            long long w=x.second;
            if(k==1 && d+w<dis[v][0])
            {
                dis[v][0]=d+w;
                pq.push({d+w,{v,0}});
            }
            else if(k==0 && d+w<dis[v][1])
            {
                dis[v][1]=d+w;
                pq.push({d+w,{v,1}});

            }
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
        int n,m;
        while(cin>>n>>m)
        {
            for(int i=1;i<=n;i++)
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
            dijkstra(1,n);
            if(dis[n][0]<INT_MAX)
            {
                cout<<dis[n][0]<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}



