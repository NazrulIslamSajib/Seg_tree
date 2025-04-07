#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
vector<int>arr[mx];
int indegree[mx];
long long dis[mx];
///count all possible path
///top sort e reverse korle er shesher child er koto gula path ache seta jog kore felobo
/// sheshe sob path gula jog korle all possible hye jabe
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
                 max1+=dis[v];
             }
             dis[u]=max1+1;
         }
         long long max1=0;
         for(int i=1;i<=n;i++)
         {
             max1+=dis[i] ;///sob gula jodi jog kori tahole kintu all possible path peye gechi
         }
         cout<<max1<<endl;
    }
    return 0;
}


