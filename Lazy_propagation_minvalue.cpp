#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;;
int arr[mx];
long long tree[4*mx];
long long lazy[4*mx]; 
///https://codeforces.com/contest/52/problem/C
void build(int id,int l,int r)
{
     lazy[id]=0;
     if(l==r)
     {
         tree[id]=arr[l];
         return;
     }
     int mid=(l+r)>>1;
     build(2*id,l,mid);
     build(2*id+1,mid+1,r);
     tree[id]=min(tree[2*id],tree[id*2+1]);
}
void propagate(int id,int l,int r)
{
    if(l!=r)
    {
        lazy[id*2]+=lazy[id];
        lazy[id*2+1]+=lazy[id];
    }
    tree[id]+=lazy[id]; ///(r-l+1) gun deoya lagbe na karon sob kkhetre to samne value jog hbe
    lazy[id]=0;

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
        lazy[id]+=val;
        propagate(id,l,r);
        return;
    }
    int mid=(l+r)>>1;
    update(id*2,l,mid,L,R,val);
    update(id*2+1,mid+1,r,L,R,val);
    tree[id]=min(tree[id*2],tree[id*2+1]);
}
long long query(int id,int l,int r,int L,int R)
{
    propagate(id,l,r);
    if(l>R || r<L)
    {
        return 1e18;
    }
    if(L<=l && r<=R)
    {
       return tree[id];
    }
    int mid=(l+r)>>1;
    long long p=query(2*id,l,mid,L,R);
    long long q=query(2*id+1,mid+1,r,L,R);
    return min(p,q);
}
int main()
{
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
       }
       build(1,1,n);
       int q;
       cin>>q;
       cin.ignore();
       while(q--)
       {
           string s;
           getline(cin,s);
           string tmp;
           vector<int>v;
           for(int i=0;i<s.size();i++)
           {
               if(isspace(s[i]))
               {
                   int num=stoi(tmp);
                   v.push_back(num);
                   tmp="";
               }
               else
               {
                   tmp+=s[i];
               }
           }
           int num=stoi(tmp);
           v.push_back(num);
          /// cout<<v.size()<<endl;
           if(v.size()==2)
           {
               int l=v[0],r=v[1];
               l++;
               r++;
               if(l<=r)
               {
                   cout<<query(1,1,n,l,r)<<endl;
               }
               else
               {
                   int left=query(1,1,n,l,n);
                   int right=query(1,1,n,1,r);
                   ///cout<<l<<" "<<r<<endl;
                   cout<<min(left,right)<<endl;
               }
           }
           else
           {
              int l=v[0],r=v[1],val=v[2];
              l++;
              r++;
              if(l<=r)
              {
                  update(1,1,n,l,r,val);
              }
              else
              {
                  update(1,1,n,l,n,val);
                  update(1,1,n,1,r,val);
              }
           }


       }
    }
    return 0;
}
