#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
int arr[mx];
int tree[4*mx][2];
///https://www.spoj.com/problems/KGSS/
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id][0]=arr[l];
        tree[id][1]=-1;
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    int a=tree[id*2][0],b=tree[id*2][1];
    int c=tree[id*2+1][0],d=tree[id*2+1][1];
    vector<int>v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    sort(v.begin(),v.end());
    tree[id][0]=v[3];
    tree[id][1]=v[2];
}
void update(int id,int l,int r,int k,int val)
{
    if(l==r)
    {
        tree[id][0]=val;
        tree[id][1]=-1;
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
    int a=tree[id*2][0],b=tree[id*2][1];
    int c=tree[id*2+1][0],d=tree[id*2+1][1];
    vector<int>v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    sort(v.begin(),v.end());
    tree[id][0]=v[3];
    tree[id][1]=v[2];

}
pair<int,int>query(int id,int l,int r,int L,int R)
{
    if(l>R || r<L)
    {
        return {-1,-1};
    }
    if(L<=l && r<=R)
    {
        return {tree[id][0],tree[id][1]};
    }
    int mid=(l+r)>>1;
    auto p=query(2*id,l,mid,L,R);
    auto q=query(2*id+1,mid+1,r,L,R);
    int a=p.first,b=p.second,c=q.first,d=q.second;
    vector<int>v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    sort(v.begin(),v.end());
    return {v[3],v[2]};

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
        }
        build(1,1,n);
        int q;
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            char c;
            cin>>c;
            if(c=='U')
            {
                int k,val;
                cin>>k>>val;
                update(1,1,n,k,val);
            }
            else
            {
                int l,r;
                cin>>l>>r;
                long long ans=query(1,1,n,l,r).first+query(1,1,n,l,r).second;
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
