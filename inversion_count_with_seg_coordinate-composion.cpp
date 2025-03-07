#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
int arr[mx];
int tree[4*mx],n;
///https://www.spoj.com/problems/INVCNT/
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=tree[id*2]+tree[2*id+1];
}
int query(int id,int l,int r,int L,int R)
{
    if(l>R|| r<L)
    {
        return 0;
    }
    int mid=(l+r)>>1;
    if(L<=l && r<=R)
    {
        return tree[id];
    }
    int p=query(id*2,l,mid,L,R);
    int q=query(id*2+1,mid+1,r,L,R);
    return p+q;
}
void update(int id,int l,int r,int k,int val)
{
   if(l==r)
   {
       tree[id]+=val;
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
void compression()
{
    map<int,int>mp;
    int now=1;
    set<int>st;
    for(int i=1;i<=n;i++)
    {
        st.insert(arr[i]);
    }
    for(auto x:st)
    {
        mp[x]=now;
        now++;
    }
    for(int i=1;i<=n;i++)
    {
        arr[i]=mp[arr[i]];
    }

}
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {


       cin>>n;
       for(int i=1;i<=n;i++)
       {

           cin>>arr[i];
       }
       compression();
       build(1,1,n);
       long long ans=0;
       for(int i=1;i<=n;i++)
       {
           ans+=query(1,1,n,arr[i]+1,n); /// dekho ami amar dan dike joto gula ache tader sum gulai to amar inversion tai noy ki
           ///karon sei gulai to ami age process korchi .mane age asche lets say 5 3 1 40 50 ....
           ///5 er jonno nai pichone karon ekhono ase nai
           ///3 er jonno kintu 5 age asche tai 1 jog hbe kanron 3 5
           ///1 er jonno 2 ta hbe karon 1 3 5
           ///40 jonno 0 ta 1 3 5 40 , 40 pichone nai kintu
           ///50 er jonno 0
           update(1,1,n,arr[i],1);
       }
       cout<<ans<<endl;
    }
    return 0;
}

