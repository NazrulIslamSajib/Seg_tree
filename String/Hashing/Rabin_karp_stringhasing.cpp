#include<bits/stdc++.h>
using namespace std ;
typedef long long int ll;
const int mx=1e6+10; 
///2 ta sub string same kina check kortechi
namespace H{  ///namespace based modularation subida hocche reuse kora jay array function tai eta korchi
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
           H[i]=(H[i-1]*base+s[i])%prime; /// h[i]=h[i-1]*x+s[i] mane age chilo ax^2+bx+c then hbe ax^3+bx^2+cx+d hbe
       }
   }
   ll hashval(int L,int R)
   {
       if(L==0) return H[R]; /// 0-5 dile to just H'[5] dilei hoye jay.
       ll ret=(H[R]-H[L-1]*power[R-L+1])%prime;
       if(ret<0) return (ret+prime)%prime;
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
           H[i]=(H[i-1]*base+s[i])%prime; /// h[i]=h[i-1]*x+s[i] mane age chilo ax^2+bx+c then hbe ax^3+bx^2+cx+d hbe
       }
   }
   ll hashval(int L,int R)
   {
       if(L==0) return H[R]; /// 0-5 dile to just H'[5] dilei hoye jay.
       ll ret=(H[R]-H[L-1]*power[R-L+1])%prime;
       if(ret<0) return (ret+prime); ///minus er karone eta korchi
   }

}
pair<ll,ll>hashval(ll L,ll R) ///ekhane ase hash val call kortechi 2 ta. 2 ta keno korteci karon collision jeno na hoy more accurate hoy
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
    ///cin>>tt;
    H::preval();
    H1::preval();
    while(tt--)
    {
       string s;
       cin>>s;
       H::buildHash(s);
       H1::buildHash(s);
       int q;
       cin>>q;
       while(q--)
       {
           long long L1,R1,L2,R2;
           cin>>L1>>R1>>L2>>R2;
           if(R1-L1+1!=R2-L2+1)
           {
               cout<<"NO"<<endl;
               continue;
           }
           if(hashval(L1,R1)==hashval(L2,R2)) ///O(1)
           {
               cout<<"YES"<<endl;
           }
           else
           {
               cout<<"NO"<<endl;
           }

       }

    }
    return 0;
}



