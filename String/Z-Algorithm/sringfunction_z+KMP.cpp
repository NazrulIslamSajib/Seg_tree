#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+10;
int failure[nmax];
///https://cses.fi/problemset/task/2107/
void KMP(string &s)
{
    long long cur=0,mxcur=0;
    failure[0]=cur;
    for(int i=1;i<s.size();i++)
    {
        while(cur!=0 && s[cur]!=s[i])
        {
            cur=failure[cur-1];
        }
        if(s[cur]==s[i])
        {
            cur++;
        }
        failure[i]=cur;
    }

}
vector<long long>Z(string &s) ///time complexity O(n)
{

    long long n  =s.size();
    vector<long long> z(n);
    long long l = 0, r = 0;
    for(int i =1;i<n;i++)
    {
        if(i<r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
        {
            z[i]++;
        }
        if(i+z[i]>r)
        {
            l = i;
            r =i+z[i];
        }
    }
    return z;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       string s;
       cin>>s;
       KMP(s);
       vector<long long>z=Z(s);
       for(int i=0;i<z.size();i++)
       {
           cout<<z[i]<<" ";
       }
       cout<<endl;
       for(int i=0;i<s.size();i++)
       {
           cout<<failure[i]<<" ";
       }
       cout<<endl;

    }
    return 0;
}
