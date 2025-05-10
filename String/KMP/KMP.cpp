#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+10;
int failure[nmax];
///Failure hocche i-th position er jonno maximum koto lenght eder suffix prefix same thakbe
/*
 aabaabaaa
 at : 0 0
 at : 1 1
 at : 2 0
 at : 3 1
 at : 4 2
 at : 5 3
 at : 6 4
 at : 7 5
 at : 8 2

*/
int KMP(string &s)
{
    int cur=0,mxcur=0;
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
        string p;
        cin>>p;
        string s;
        cin>>s;
        s=p+"$"+s;
        KMP(s);
        for(int i=0;i<s.size();i++)
        {
            cout<<"faillure : at "<<i<<" "<<failure[i]<<endl;
            if(failure[i]==p.size())
            {
               cout<<" Matching : "<<i<<endl;
            }
        }
    }
    return 0;
}



