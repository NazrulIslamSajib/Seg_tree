#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
long long tree[4*mx];
long long lazy[4*mx];
bool vis[4*mx];
const int mod=1e9+7;
///https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/C
void build(long long id,long long l,long long r)
{
    lazy[id]=0;
    if(l==r)
    {
        tree[id]=0;
        return;
    }
    long long mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=(tree[2*id]&tree[2*id+1]);
}
void propagate(int id,int l,int r)
{
    if(vis[id]==true)
    {

    if(l!=r)
    {
      lazy[2*id] = (lazy[2*id]|lazy[id]);
      lazy[2*id+1] = (lazy[2*id+1]|lazy[id]);
      vis[2*id]=true;
      vis[2*id+1]=true;
    }
    tree[id]=(tree[id]|lazy[id]);
    lazy[id]=0;
    vis[id]=false;
    }
}
void update(long long id,long long l,long long r,long long L,long long R,long long val)
{
    propagate(id,l,r);
    if(l>R || r<L)
    {
        return;
    }
    if(L<=l && r<=R)
    {
        lazy[id]=(lazy[id]|val);
        vis[id]=true;
        propagate(id,l,r);
        return;

    }
    long long mid=(l+r)>>1;
    update(2*id,l,mid,L,R,val);
    update(2*id+1,mid+1,r,L,R,val);
    tree[id]=(tree[id*2]&tree[id*2+1]);
}
long long query(long long id,long long l,long long r,long long L,long long R)
{
    propagate(id,l,r);
    if(l>R || r<L)
    {
        return (1LL<<60)-1; ///key point etai chilo
    }
    if(L<=l && r<=R)
    {
        return tree[id];
    }
    int mid=(l+r)>>1;
    long long p=query(2*id,l,mid,L,R);
    long long q=query(2*id+1,mid+1,r,L,R);
    return (p&q);
}

int main()
{
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
                long long l,r,val;
                cin>>l>>r>>val;
                l++;
                update(1,1,n,l,r,val);
            }
            else
            {
                long long l,r;
                cin>>l>>r;
                l++;
                cout<<query(1,1,n,l,r)<<endl;
            }
        }

    }
    return 0;
}

