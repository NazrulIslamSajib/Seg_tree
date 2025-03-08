#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
int tree[4*mx][2];
int mp[4*mx];
int arr[mx];
///https://www.hackerrank.com/contests/codeagon2015/challenges/sherlock-and-subarray-queries/problem
void build(int id,int l,int r)
{
     if(l==r)
     {
         tree[id][0]=arr[l];
         tree[id][1]=1;
         return;
     }
     int mid=(l+r)>>1;
     build(id*2,l,mid);
     build(id*2+1,mid+1,r);
     tree[id][0]=max(tree[id*2][0],tree[id*2+1][0]);
     if(tree[id*2][0]==tree[id*2+1][0])
     {
         tree[id][1]=tree[id*2][1]+tree[id*2+1][1];
     }
     else
     {
         if(tree[id][0]==tree[id*2][0])
         {
             tree[id][1]=tree[id*2][1];
         }
         else
         {
             tree[id][1]=tree[id*2+1][1];
         }
     }

}
pair<int,int>query(int id,int l,int r,int L,int R)
{
    if(l>R || r<L)
    {
       return {INT_MIN,0};
    }
    if(L<=l && r<=R)
    {
        return {tree[id][0],tree[id][1]};
    }
    int mid=(l+r)>>1;
    auto  p=query(id*2,l,mid,L,R);
    auto  q=query(id*2+1,mid+1,r,L,R);
    int mx=max(p.first,q.first);
    if(mx==p.first && mx==q.first)
    {
        return {mx,p.second+q.second};
    }
    else if(mx>p.first)
    {
        return {mx,q.second};
    }
    else
    {
        return {mx,p.second};
    }
}

int main()
{
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
       int n,q;
       cin>>n>>q;
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
       }
        build(1,1,n);
        /*
       for(int i=1;i<=9;i++)
       {
           cout<<tree[i][0]<<" ";
       }
       cout<<endl;
       for(int i=1;i<=9;i++)
       {
           cout<<tree[i][1]<<" ";
       }
       cout<<endl;
       */
       for(int i=1;i<=q;i++)
       {
           int l,r;
           cin>>l>>r;
           cout<<query(1,1,n,l,r).second<<endl;

       }
    }
    return 0;
    //maximum ber koro then eder count
}

