#include<bits/stdc++.h>
using namespace std;
///https://cses.fi/problemset/task/1648/
typedef long long ll;
const int mx=2e5+2;
ll tree[4*mx];
ll arr[mx];
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id]=arr[l];  ///oi id er jaygay ami amar array er elemnet bosaichi
        return;
    }
    ll mid=(l+r)>>1;
    build(2*id,l,mid); ///vag korle to left child
    build(2*id+1,mid+1,r); ///right child
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
    if(k<=mid) ///mid kintu l,r theke aste jeta original size.
    {
        update(2*id,l,mid,k,val);  /// jotokkhon mojjonto mid ta k er choto hbe totokkhon left child
    }
    else
    {
        update(2*id+1,mid+1,r,k,val);  ///right child
    }
    tree[id]=tree[id*2]+tree[id*2+1];
}
ll query(int id,int l,int r,int L,int R)
{
    if(r<L || l>R)
    {
        return 0;  ///segment er bahire cole gele 0
    }
    if(L<=l && r<=R)
    {
        return tree[id]; /// segment er vitore hle niye felbo
    }
    ll mid=(l+r)>>1;
    ll p1=query(id*2,l,mid,L,R);
    ll p2=query(id*2+1,mid+1,r,L,R);
    return p1+p2; ///left child right child mile jog
}
int main()
{
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       ll n,q;
       cin>>n>>q;
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
       }
       build(1,1,n);  ///id =1 hoy shurute , 1 theke n pojjonto update;
       while(q--)
       {
         int type;
         cin>>type;
         if(type==2)
         {
             int L,R;
             cin>>L>>R;
             cout<<query(1,1,n,L,R)<<endl; ///id=1,1-n puro segment then L,R segment er sum
         }
         else
         {
             int k,val;
             cin>>k>>val;
             update(1,1,n,k,val);
         }
       }

    }
    return 0;
}

