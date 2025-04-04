///ekta tree ke ami array te niye aschi seta ke bole dfs
///https://cses.fi/problemset/task/1137/
///problem says ekta deooya ache bolte hbe oi sub tree er modde values koto
///bar bar eta change o korbe
#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
long long values[mx];
vector<long long>arr[mx];
vector<long long>dfsarr;
int st[mx];
int en[mx];
long long tree[4*mx];
typedef long long ll;
void dfs(int u,int par)
{
    dfsarr.push_back(u); ///dfs array eta eta dara u gulo ke sajabo ete er position pabo se kothay array store korbo.
    st[u]=dfsarr.size(); ///start u ta koto position rakhchi
    for(auto v:arr[u])
    {
        if(v==par) continue;
        dfs(v,u);
    }
    en[u]=dfsarr.size(); ///u er sub tree kothay shesh hoice seta rakhchi
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id]=values[dfsarr[l-1]]; ///0 base dfsarr// dfsarray er l position e kon value ache setar values mane weight

        return;
    }
    ll mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=tree[id*2]+tree[id*2+1];
}
void update(int id,int l,int r,int k,int val)
{
    if(l==r)
    {
        tree[id]=val;
        return;
    }
    ll mid=(l+r)>>1;
    if(k<=mid)
    {
        update(2*id,l,mid,k,val);
    }
    else
    {
        update(2*id+1,mid+1,r,k,val);
    }
    tree[id]=tree[id*2]+tree[id*2+1];
}
ll query(int id,int l,int r,int L,int R)
{
    if(r<L || l>R)
    {
        return 0;
    }
    if(L<=l && r<=R)
    {
        return tree[id];
    }
    ll mid=(l+r)>>1;
    ll p1=query(id*2,l,mid,L,R);
    ll p2=query(id*2+1,mid+1,r,L,R);
    return p1+p2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
   /// cin>>tt;
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
      /// cout<<"Hoise"<<endl;
       for(int i=1;i<=q;i++)
       {
           int type;
           cin>>type;
           if(type==1)
           {
               int s,x;
               cin>>s>>x;
               update(1,1,n,st[s],x); ///s er node er man ami st[s] kon position e ache oi position e ami x bosabo
           }
           else
           {
               int s;
               cin>>s;
               cout<<query(1,1,n,st[s],en[s])<<endl; ///range st[u] to en[u]

           }
       }
    }
    return 0;
}



