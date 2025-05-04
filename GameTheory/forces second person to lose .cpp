#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+10;
bool vis[mx]; 
///bar bar second peroson ke losing state e pathai dicchi
///https://cses.fi/problemset/task/1729/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
        int n,k;
        cin>>n>>k;
        int arr[k+10];
        for(int i=1;i<=k;i++)
        {
            cin>>arr[i];
        }
        vis[0]=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i-arr[j]>=0)
                {
                    if(vis[i-arr[j]]==false)
                    {
                        vis[i]=true;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                cout<<"W";
            }
            else
            {
                cout<<"L";
            }
        }
        cout<<endl;
    }
    return 0;
}


