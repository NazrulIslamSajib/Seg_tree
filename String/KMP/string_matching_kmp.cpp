#include<bits/stdc++.h>
using namespace std;
const int nmax=2e6+10;
int failure[nmax];
///https://cses.fi/problemset/task/1753
long long KMP(string &s)
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
        mxcur=max(mxcur,cur);
    }
    return mxcur;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
/// cin>>tt;
    while(tt--)
    {
       string s,t;
       cin>>s>>t;
       s=t+"$"+s;
       long long ok=KMP(s);
       long long ans=0;
       for(int i=0;i<s.size();i++)
       {
           if(failure[i]>=t.size())
           {
               ans++;
           }
       }
       cout<<ans<<endl;
    }
    return 0;
}



