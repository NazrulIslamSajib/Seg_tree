#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mx=100010;
int grendy[mx];
///Sprague-Grundy theory
///https://vjudge.net/problem/HDU-1536 
///ekhane bola mane xor korle to jodi zero tahole protom bakti here jabe . onnothay first bekti jitbe. kintu eta just ekta pile er jonno chilo . multi piler jonno 
///grundy theory . jeta grendy value gular xor korle jodi zero ase tahole first bekti here jabe. 
void precal(vector<int>&v)
{
    for(int i=1;i<mx;i++)
    {
        vector<int>reach;
        for(auto x:v)
        {
            if(i-x>=0)
            {
                reach.push_back(grendy[i-x]);
            }
        }
        int cnt=0;
        sort(reach.begin(),reach.end());
        for(int x:reach)
        {
            if(x==cnt)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        grendy[i]=cnt;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
   // cin>>tt;
    while(tt)
    {
       int n;
       cin>>n;
       if(n==0)
       {
           break;
       }
       vector<int>v;
       for(int i=1;i<=n;i++)
       {
           int x;
           cin>>x;
           v.push_back(x);
       }
       precal(v);
       int m;
       cin>>m;
       for(int i=1;i<=m;i++)
       {
           int l;
           cin>>l;
           int xor1=0;
           for(int j=1;j<=l;j++)
           {
               int x;
               cin>>x;
               xor1^=grendy[x];
           }
           if(xor1==0)
           {
               cout<<'L';
           }
           else
           {
               cout<<"W";
           }
       }
       cout<<endl;
    }
    return 0;
}


