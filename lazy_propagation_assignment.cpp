#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
long long arr[mx];
long long tree[mx*4];
long long lazy[mx*4];
bool flag[mx*4];
////https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/C
///assignment
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id]=0;
        lazy[id]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=tree[id*2]+tree[id*2+1];
}
void propagate(int id,int l,int r)
{
    if(flag[id]==true)
    {
    if(l!=r)
    {
        lazy[2*id]=lazy[id];
        lazy[2*id+1]=lazy[id];
        flag[2*id+1]=true;
        flag[2*id]=true;
    }
    tree[id]=lazy[id];
    lazy[id]=0;
    flag[id]=false;
    }
    return;
}
void update(int id,int l,int r,int L,int R,int val)
{
    propagate(id,l,r);
    if(l>R || r<L)
    {
       return;
    }
    if(L<=l && r<=R)
    {
        lazy[id]=val;
        flag[id]=true;
        propagate(id,l,r);
        return;
    }
    int mid=(l+r)>>1;
    update(2*id,l,mid,L,R,val);
    update(2*id+1,mid+1,r,L,R,val);
    tree[id]=tree[2*id]+tree[id*2+1];
}
long long query(int id,int l,int r,int L,int R)
{
    propagate(id,l,r);
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
       build(1,1,n);
       for(int i=1;i<=q;i++)
       {
           int type;
           cin>>type;
           if(type==1)
           {
               int l,r,val;
               cin>>l>>r>>val;
               l++;
               update(1,1,n,l,r,val);
           }
           else
           {
               int k;
               cin>>k;
               k++;
               cout<<query(1,1,n,k,k)<<endl;
           }
       }
    }
    return 0;
}


