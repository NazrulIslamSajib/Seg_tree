#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
int arr[mx];
int tree[4*mx];
int index[4*mx];
int ans;
///https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/D
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id]=arr[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=max(tree[id*2],tree[id*2+1]);
}
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
        update(2*id,l,mid,k,val);
    }
    else
    {
        update(2*id+1,mid+1,r,k,val);
    }
    tree[id]=max(tree[id*2],tree[id*2+1]);
}
int query(int id,int l,int r,int val,int j)
{

    if(l==r)
    {
        if(tree[id]>=val && l>=j)
        {
            return l;
        }
        else
        {
            return 0;
        }
    }
    int mid=(l+r)>>1;
    int res=0;
    if(tree[2*id]>=val && mid>=j)
    {
        res=query(id*2,l,mid,val,j);
    }
    if(res==0)
    {
        res=query(2*id+1,mid+1,r,val,j);
    }
    return res;
}
int main()
{
    long long tt=1;
  ///  cin>>tt;
    while(tt--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        n++;
        arr[n]=INT_MAX;
        build(1,1,n);
        for(int i=1;i<=q;i++)
        {
            int type;
            cin>>type;
            if(type==2)
            {
                int x,l;
                cin>>x>>l;
                l++;
                int ans=query(1,1,n,x,l);
                if(ans==n)
                {
                    cout<<-1<<endl;
                }
                else
                {
                    cout<<ans-1<<endl;
                }
            }
            else
            {
                int k,val;
                cin>>k>>val;
                k++;
                update(1,1,n,k,val);
            }
        }
    }
    return 0;
}
