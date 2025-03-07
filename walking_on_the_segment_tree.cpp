#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+7;
int arr[mx];
int tree[4*mx]; 
///https://codeforces.com/problemset/problem/1354/D
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=tree[2*id]+tree[2*id+1];
}
void update(int id,int l,int r,int k,int val)
{
    if(l==r)
    {
        tree[id]+=val;
        return;
    }
    int mid=(l+r)/2;
    if(k<=mid)
    {
        update(2*id,l,mid,k,val);
    }
    else
    {
        update(2*id+1,mid+1,r,k,val);
    }
    tree[id]=tree[2*id]+tree[2*id+1];
    return;

}
int query(int id,int l,int r,int k)
{
    if(l==r)
    {
        return l;

    }
    int mid=(l+r)/2;
    if(tree[2*id]>=k)   ///bamer ta ki k er theke beshi kina 
    {
        return query(id*2,l,mid,k);
    }
    else
    {
        return query(id*2+1,mid+1,r,k-tree[2*id]);  ////bamer gula bad dite hbe jehetu ami dan dike jacchi
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[x]++;
    }
    int N=1e6;
    build(1,1,N);
    int sz=n;
    while(q--)
    {
        int k;
        cin>>k;
        if(k<0)
        {
            k=-k;
            sz--;
            int x=query(1,1,N,k);
            update(1,1,N,x,-1);
        }
        else
        {
            update(1,1,N,k,1);
            sz++;
        }
    }
    if(sz>0)
    {
       cout<<query(1,1,N,1)<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}
