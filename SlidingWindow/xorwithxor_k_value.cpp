#include<bits/stdc++.h>
using namespace std; 
///https://cses.fi/problemset/result/13694596/
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
         long long sum=0,ans=0;
         for(int i=1;i<=k;i++)
         {
             sum^=arr[i];
         }
         ans^=sum;
         for(int i=k+1;i<=n;i++)
         {
             sum^=arr[i-k];
             sum^=arr[i];
             ans^=sum;
         }
         cout<<ans<<endl;

    }
    return 0;
}
