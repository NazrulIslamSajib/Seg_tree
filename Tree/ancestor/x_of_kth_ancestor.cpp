#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
vector<int>arr[mx];
int ancestor[mx][25];
///https://cses.fi/problemset/task/1687/
///ekhane ekta i er ekek ta ancestor deya ache . amake bolte hbe x er kth ancestor ke
void dfs(int u,int par)
{
    for(auto v:arr[u])
    {
        if(v==par) continue;
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
            int x,k;
            cin>>x>>k;
            cout<<getAncestor(x,k)<<endl;
        }
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
vector<int> arr[mx];
int ancestor[mx][20];

void dfs(int u, int par) {
    for (int i = 0; i < 20; i++) {
        ancestor[u][i] = -1;
    }
    ancestor[u][0] = par;

    for (int i = 1; i < 20; i++) {
        int v1 = ancestor[u][i - 1];
        if (v1 == -1) break;
        ancestor[u][i] = ancestor[v1][i - 1];
    }

    for (auto v : arr[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
}

int getAncestor(int x, int k) {
    for (int i = 0; i < 20; i++) {
        if (k & (1 << i)) {
            x = ancestor[x][i];
            if (x == -1) return -1;
        }
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        arr[u].push_back(i);
    }

    dfs(1, -1);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << getAncestor(x, k) << endl;
    }

    return 0;
}
*/


