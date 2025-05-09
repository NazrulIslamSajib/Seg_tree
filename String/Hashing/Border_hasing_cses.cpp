#include<bits/stdc++.h>
using namespace std ;
typedef long long int ll;
const int mx=2e6+10;
///https://cses.fi/problemset/task/1732
namespace H{
   const int prime=1e9+7;
   ll base=1000003;
   ll power[mx];
   ll H[mx];
   void preval()
   {
       power[0]=1;
       for(int i=1;i<mx;i++)
       {
           power[i]=(power[i-1]*base)%prime;
       }
   }
   void buildHash(string &s)
   {
       H[0]=s[0];
       for(int i=1;i<s.size();i++)
       {
           H[i]=(H[i-1]*base+s[i])%prime;
       }
   }
   ll hashval(int L,int R)
   {
       if(L==0) return H[R];
       ll ret=(H[R]-H[L-1]*power[R-L+1])%prime;
       if(ret<0) ret=(ret+prime);
       return ret;
   }
}
namespace H1{
   const int prime=1e9+9;
   ll base=1e8;
   ll power[mx];
   ll H[mx];
   void preval()
   {
       power[0]=1;
       for(int i=1;i<mx;i++)
       {
           power[i]=(power[i-1]*base)%prime;
       }
   }
   void buildHash(string &s)
   {
       H[0]=s[0];
       for(int i=1;i<s.size();i++)
       {
           H[i]=(H[i-1]*base+s[i])%prime;
       }
   }
   ll hashval(int L,int R)
   {
       if(L==0) return H[R];
       ll ret=(H[R]-H[L-1]*power[R-L+1])%prime;
       if(ret<0) ret=(ret+prime);
       return ret;
   }

}
pair<ll,ll>hashval(ll L,ll R)
{
    ll ret1=H::hashval(L,R);
    ll ret2=H1::hashval(L,R);
    return {ret1,ret2};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    H::preval();
    H1::preval();
   /// cin>>tt;
    while(tt--)
    {
       string s;
       cin>>s;
       H::buildHash(s);
       H1::buildHash(s);
       ll last=s.size()-1;
       vector<ll>v;
       for(int i=0;i<s.size();i++)
       {
            ll next=last-i;
            if(next!=0 && hashval(0,i)==hashval(next,last))
            {
                v.push_back(i+1);
            }
       }
       for(auto x:v)
       {
           cout<<x<<" ";
       }
       cout<<endl;

    }
    return 0;
}


