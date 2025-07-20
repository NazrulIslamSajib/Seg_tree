#include<bits/stdc++.h>
using namespace std;
///https://cses.fi/problemset/task/1076
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
   //// cin>>tt;
    while(tt--)
    {
         long long n,k;
         cin>>n>>k;
         long long arr[n+10];
         for(int i=1;i<=n;i++)
         {
             cin>>arr[i];
         }
         if(k==1)
         {
            for(int i=1;i<=n;i++)
            {
                cout<<arr[i]<<" ";
            }
            continue;
         }
         multiset<long long>st1,st2;
         vector<long long>v;
         for(int i=1;i<=k;i++)
         {
            v.push_back(arr[i]);
         }
         sort(v.begin(),v.end());
         for(int i=0;i<(k+1)/2;i++)
         {
             st1.insert(v[i]);
         }
         for(int i=(k+1)/2;i<k;i++)
         {
             st2.insert(v[i]);
         }
         cout<<*st1.rbegin()<<" ";
         for(int i=k+1;i<=n;i++)
         {
               if(st1.find(arr[i-k])!=st1.end())
               {
                    auto it=st1.find(arr[i-k]);
                    st1.erase(it);
                    long long num=*st2.begin();
                    auto it1=st2.find(num);
                    st2.erase(it1);
                    st1.insert(num);
                    if(num<=arr[i])
                    {
                       st2.insert(arr[i]);
                    }
                    else
                    {
                       long long num1=*st1.rbegin();
                       auto it3=st1.find(num1);
                       st1.erase(it3);
                       st2.insert(num1);
                       st1.insert(arr[i]);
                    }
               }
               else
               {
                    auto it=st2.find(arr[i-k]);
                    st2.erase(it);
                    if(*st1.rbegin()<=arr[i])
                    {
                        st2.insert(arr[i]);
                    }
                    else
                    {
                       long long num1=*st1.rbegin();
                       auto it3=st1.find(num1);
                       st1.erase(it3);
                       st2.insert(num1);
                       st1.insert(arr[i]);
                    }
               }
               cout<<*st1.rbegin()<<" ";
         }
         cout<<endl;
    }
    return 0;
}

