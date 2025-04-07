#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
vector<int>arr[mx];
int indegree[mx];
///eta bfs diye korchi indegree concept diye
///kono node er indegree 0 hoya mane tar kaj ney take push kore deoya and
///eder child gula ke indegree 1 komiye deoya. jar indegree 0 asbe take push kore deoya
///if cycle thake seta bujbo vector er size n er soman na karon sob gula indegree 0 hoy nai
///https://cses.fi/problemset/task/1679/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
   // cin>>tt;
    while(tt--)
    {
       int n,m;
       cin>>n>>m;
       for(int i=1;i<=n;i++)
       {
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
       vector<int>ans;
       while(!q.empty())
       {
           int u=q.front();
           for(auto v:arr[u])
           {
               indegree[v]--;
               if(indegree[v]==0)
               {
                   q.push(v);
               }
           }
           ans.push_back(u);
           q.pop();
       }
       if(ans.size()==n)
       {
           for(auto x:ans)
           {
               cout<<x<<" ";
           }
           cout<<endl;
       }
       else
       {
           cout<<"IMPOSSIBLE"<<endl;
           ///karon DAG peye gechi
       }
    }
    return 0;
}



