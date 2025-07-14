#include<bits/stdc++.h>
using namespace std;
///https://cses.fi/problemset/task/3405/
///best sliding window I saw .

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
         long long n,k;
         cin>>n>>k;
         long long x,a,b,c;
         cin>>x>>a>>b>>c;
         long long arr[n+10];
         arr[1]=x;
         for(int i=2;i<=n;i++)
         {
             arr[i]=(((arr[i-1]*a)%c)+(b%c))%c;
         }
         long long suff[n+10],pre[n+10];
         pre[0]=0;
         suff[n+1]=0;
         for(int i=1;i<=n;i++)
         {
             if(i%k==1)
             {
                 pre[i]=arr[i];
             }
             else if(k==1)
             {
                 pre[i]=arr[i];
             }
             else
             {
                 pre[i]=pre[i-1]|arr[i];
             }
         }
         for(int i=n;i>=1;i--)
         {
             if(i%k==0)
             {
                 suff[i]=arr[i];
             }
             else
             {
                 suff[i]=suff[i+1]|arr[i];
             }
         }
         long long ans=0;
         for(int i=1;i<=n;i++)
         {
             if(i>=k)
             {
                 ans^=(pre[i]|suff[i-k+1]);
             }
         }
         cout<<ans<<endl;


    }
    return 0;
}
