#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
int arr[mx];
int tree[4*mx];
vector<pair<int,int>>v[mx];
int ans[mx];
map<int,int>mp;
///https://cses.fi/problemset/task/1734/
///problem says koto ranger er modde distinct value ber korte.
///ami sob somoy last elemnet niye kaj korbo then seta ke 1 korbo er previos e joto gula
///same element ache sei gula 0 kore dibo tahole ar somossa hocche na.
///1,2,3,4,5,5 ......last elemnt  hbe.
void update(int id,int l,int r,int k,int val)
{
    if(l==r)
    {
        tree[id]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(k<=mid)
    {
        update(id*2,l,mid,k,val);
    }
    else
    {
        update(id*2+1,mid+1,r,k,val);
    }
    tree[id]=tree[id*2]+tree[id*2+1];
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
    int p=query(2*id,l,mid,L,R);
    int q=query(2*id+1,mid+1,r,L,R);
    return p+q;
}
int main()
{
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
       long long n,q;
       cin>>n>>q;
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
       }
       for(int i=1;i<=q;i++)
       {
           int l,r;
           cin>>l>>r;
           v[r].push_back({l,i});
       }
       for(int i=1;i<=n;i++)
       {

           update(1,1,n,i,1);
           if(mp[arr[i]]!=0)
           {
               update(1,1,n,mp[arr[i]],0);
           }
           mp[arr[i]]=i;
           for(auto p:v[i])
           {
               int l=p.first;
               int id=p.second;
               int val=query(1,1,n,l,i);
               ans[id]=val;
           }
       }
       for(int i=1;i<=q;i++)
       {
           cout<<ans[i]<<endl;
       }

    }
    return 0;
}

