#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
typedef pair<int,int>pii;
vector<pii>arr[mx];
long long dis[mx],n;
long long par[mx];
void dijkstra()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=LLONG_MAX;
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,1});
    par[1]=-1;
    dis[1]=0;
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
            if(cost+d<dis[v])
            {
                pq.push({cost+d,v});
                dis[v]=cost+d;
                par[v]=u;

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
   // cin>>tt;
    while(tt--)
    {
         int m;
         cin>>n>>m;
         for(int i=1;i<=m;i++)
         {
             int u,v,w;
             cin>>u>>v>>w;
             arr[u].push_back({v,w});
             arr[v].push_back({u,w});
         }
         dijkstra();
         int q;
         cin>>q;
         for(int i=1;i<=q;i++)
         {
        int ask;
        cin>>ask;
        vector<int> path;
        int temp = ask;
        while (temp != -1) {
            path.push_back(temp);
            temp = par[temp];
        }
        reverse(path.begin(), path.end());
        for (int node : path) {
            cout << node << " ";
        }
        cout<<endl;
         }
    }
    return 0;
}



