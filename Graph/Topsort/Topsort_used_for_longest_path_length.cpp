#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
vector<int>arr[mx];
int indegree[mx];
long long dis[mx];
///https://atcoder.jp/contests/dp/tasks/dp_g
///maximum path lenght
///ami top sort jeta ber korbo seta ke reverse ber korbo tahole tar deancestor
///tahole tar niche maximum jeta ache oi path ta ami follow korbo
///child gula theke maximum nibo arki eivabe agabo
///Dag hole kintu kora jabe ei kaj ta
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
         int n,m;
         cin>>n>>m;
         for(int i=1;i<=n;i++)
         {
             dis[i]=1;
             indegree[i]=0;
         }
         for(int i=1;i<=m;i++)
         {
             int u,v;
             cin>>u>>v;
             arr[u].push_back(v);
             indegree[v]++;
         }
         queue<int>q;
         for(int i=1;i<=n;i++)
         {
            if(indegree[i]==0)
            {
                q.push(i);
            }
         }
         vector<long long>ans;
         while(!q.empty())
         {
             int u=q.front();
             ans.push_back(u);
             q.pop();
             for(auto v:arr[u])
             {   indegree[v]--;
                 if(indegree[v]==0)
                 {
                     q.push(v);
                 }
             }
         }
         reverse(ans.begin(),ans.end());
         for(auto u:ans)
         {
             long long max1=0;
             for(auto v:arr[u])
             {
                 max1=max(max1,dis[v]);
             }
             dis[u]=max1+1;
         }
         long long max1=0;
         for(int i=1;i<=n;i++)
         {
             max1=max(max1,dis[i]);
         }
         cout<<max1-1<<endl; ///answer e 1 komai likhte bolche
    }
    return 0;
}


