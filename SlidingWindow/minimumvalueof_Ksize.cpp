#include<bits/stdc++.h>
using namespace std;
///https://cses.fi/problemset/task/3221/
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
         long long ans=0,cnt=0;
         deque<long long>dq;
         for(int i=1;i<=n;i++)
         {
             if(i>=k)
             {
                   if(!dq.empty() && dq.front()==i-k)
                   {
                       dq.pop_front();

                   }
                   while(!dq.empty() && arr[dq.back()]>arr[i])
                   {
                      dq.pop_back();
                   }
                   dq.push_back(i);
                   ans^=arr[dq.front()];
                  //// cout<<dq.front()<<" ";
             }
             else
             {

                   while(!dq.empty() && arr[dq.back()]>arr[i])
                   {
                      dq.pop_back();
                   }
                   dq.push_back(i);

             }
         }
         cout<<ans<<endl;

    }
    return 0;
}
