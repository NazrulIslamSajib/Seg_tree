#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
int tree[4*mx];
int arr[mx];
map<int,int>mp;
///https://vjudge.net/problem/Kattis-turbo
///problem say dane eder ke nije der position e takhte thaole koto ta swap lagbe bolte
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=tree[2*id]+tree[id*2+1];
}
int query(int id,int l,int r,int L,int R)
{
    if(l>R || r<L)
    {
       return 0;
    }
    if(L<=l && r<=R)
    {
        return tree[id];
    }
    int mid=(l+r)>>1;
    int p=query(id*2,l,mid,L,R);
    int q=query(id*2+1,mid+1,r,L,R);
    return p+q;
}
void update(int id,int l,int r,int k,int val)
{
    if(l==r)
    {
        tree[id]=0;
        return;
    }
    int mid=(l+r)>>1;
    if(k<=mid)
    {
        update(2*id,l,mid,k,val);
    }
    else
    {
        update(2*id+1,mid+1,r,k,val);
    }
    tree[id]=tree[2*id]+tree[id*2+1];
}
int main()
{
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            mp[arr[i]]=i;
        }
        build(1,1,n);
        int l=1,r=n,x=1,ans=0;
        while(l<r)
        {
            if(x%2)
            {
               cout<<(query(1,1,n,1,mp[l]-1))<<endl;
               update(1,1,n,mp[l],0);
               l++;
            }
            else
            {
                cout<<(query(1,1,n,mp[r]+1,n))<<endl;
                update(1,1,n,mp[r],0);
                r--;
            }
            x++;

        }
        cout<<0<<endl;

    }
    return 0;
}

