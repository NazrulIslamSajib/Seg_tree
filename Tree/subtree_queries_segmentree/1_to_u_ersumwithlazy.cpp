#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
long long values[mx];
vector<int>arr[mx];
long long tree[4*mx];
long long lazy[4*mx];
vector<int>dfsarr;
int st[mx];
int en[mx];
///https://cses.fi/problemset/task/1138/
///1 theke u node er values gular sum bolte hbe
///update e kintu u e update korle er sum tree te change asbe tai oi ranger er update
long long sum[mx];
void dfs(int u,int par)
{
    sum[u]=values[u];
    if(par!=-1)
    {
        sum[u]+=sum[par];
    }
    dfsarr.push_back(u);
    st[u]=dfsarr.size();
    for(auto v:arr[u])
    {
        if(v==par) continue;
        dfs(v,u);
    }
    en[u]=dfsarr.size();
}
void build(int id,int l,int r)
{
    lazy[id]=0;
    if(l==r)
    {
        int pos=dfsarr[l-1];
        tree[id]=sum[pos]; ///l er position to dfsarr[l]
        return;
    }
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=tree[id*2]+tree[id*2+1];
}
void propagate(int id,int l,int r) ///nijer ta rekhe nicher dike diye dilo lazy er value ta.
{
    if(l!=r)
    {
      lazy[2*id]+=lazy[id];
      lazy[2*id+1]+=lazy[id];
    }
    tree[id]+=(r-l+1)*lazy[id];
    lazy[id]=0;
}
void update(int id,int l,int r,int L,int R,int val)
{
    propagate(id,l,r); ///jehetu nicher dike jao lagbe tai ekbar propagate korte hbe.
    if(l>R || r<L)
    {
        return;
    }
    if(L<=l && r<=R)
    {
        lazy[id]+=val; /// lazy te age ja chilo ekhn tar sathe val ta jog korchi.
        propagate(id,l,r); ///nicher chlld gulo ke diye dichi and lazy r man gula 0 kore dichi.
        return;
    }
    int mid=(l+r)>>1;
    update(2*id,l,mid,L,R,val);
    update(2*id+1,mid+1,r,L,R,val);
    tree[id]=tree[id*2]+tree[id*2+1];
}
long long query(int id,int l,int r,int L,int R)
{
    propagate(id,l,r); ///jehetu search kortechi tai nicher dike jaoyar somoy propagate kore jacchi/ distribute kore jacchi
    if(l>R || r<L)
    {
        return 0;
    }
    if(L<=l && r<=R)
    {
        return tree[id];
    }
    int mid=(l+r)>>1;
    long long p=query(2*id,l,mid,L,R);
    long long q=query(2*id+1,mid+1,r,L,R);
    return p+q;
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
        for(int i=1;i<=n;i++)
        {
            cin>>values[i];
        }
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        dfs(1,-1);
        build(1,1,n);
        ///cout<<"hoice"<<endl;
        for(int i=1;i<=q;i++)
        {
            int type;
            cin>>type;
            if(type==1)
            {
                int s,x;
                cin>>s>>x;
                long long difference=x-values[s];
                values[s]=x;
                update(1,1,n,st[s],en[s],difference);
            }
            else
            {
                int s;
                cin>>s;
                cout<<query(1,1,n,st[s],st[s])<<endl;
            }
        }
    }
    return 0;
}


