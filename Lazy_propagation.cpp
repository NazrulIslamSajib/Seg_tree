#include<bits/stdc++.h>
using namespace std;
///https://cses.fi/problemset/task/1651
const int mx=2e5+10;
int arr[mx];
long long tree[4*mx];
long long lazy[4*mx]; ///eta lazy'r jonno rakhchi mane niche jeno ar na jaoya lage ekhanei store kore dichi.
///lazy progation lage ekta range ke update korar kkhetre se khetre nicher dike jabe na oi range er modde paile
///sekhane update kore dibe pore query korar somoy nijer ta niye tar child e propagate kore dibe.
void build(int id,int l,int r)
{
    lazy[id]=0;
    if(l==r)
    {
        tree[id]=arr[l];
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
    long long tt=1;
   // cin>>tt;
    while(tt--)
    {
       int n,q;
       cin>>n>>q;
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
       }
       build(1,1,n);
       while(q--)
       {
           int type;
           cin>>type;
           if(type==1)
           {
               int l,r,val;
               cin>>l>>r>>val;
               update(1,1,n,l,r,val);
           }
           else
           {
               int k;
               cin>>k;
               cout<<query(1,1,n,k,k)<<endl;
           }
       }
    }
    return 0;
}

