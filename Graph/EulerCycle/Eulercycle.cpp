#include <bits/stdc++.h>
using namespace std;
const int MX =1e5+10;
map<int,multiset<int>> g;
vector<int> path;
bool vis1[MX];
set<int>visited;
vector<int>adj[MX];
bool vis[MX];
///Eulerian cylce|Circuit mane hocche same start node and ending node
///Traverse Each node Exacly one times
////https://cses.fi/problemset/task/1691/
void add_edge(int u, int v) {
    g[u].insert(v);
    g[v].insert(u);
    adj[u].push_back(v);
    adj[v].push_back(u);

}
void dfs(int u) {

    while(!g[u].empty())
    {
        int v = *g[u].begin();
        g[u].erase(g[u].find(v));
        g[v].erase(g[v].find(u));
        dfs(v);
        path.push_back(v);
    }
}
void viss(int u) ///component check kortechi.
{
    visited.insert(u);
    vis1[u]=true;
    for(auto v:adj[u])
    {
        if(vis1[v]==false)
        {
            viss(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        add_edge(u, v);
    }
    int odd=0;
    int start=-1;
    for (int i=1;i<=n;i++)
    {
        if (g[i].size()%2 == 1)
        {
            odd++;
            if (start==-1)
                start=i;
        }
    }
    if(odd>=1) ///sob gula jodh jodh thakte hbe
    {
       cout << "IMPOSSIBLE\n";
       return 0;
    }
    if (start == -1)
        start=1;
    viss(start); ///1 er odik component thakle hbe na
    dfs(start);
    if((int)path.size()!=m) ///m ta path thaktei hobe sheser jonno arek ta start
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(auto x:path)
    {
        cout<<x<<" ";
    }
    cout<<start<<" "<<endl; ///start diye je shuru korchi seta to print hocche na tai eta dichi
    return 0;
}
