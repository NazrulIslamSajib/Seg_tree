#include<bits/stdc++.h>
using namespace std;
///https://codeforces.com/contest/2132/problem/D
///https://www.geeksforgeeks.org/dsa/count-sum-of-digits-in-numbers-from-1-to-n/
///geeksforgeeks
long long sumOfDigits(long long n) {

    if (n < 10)
        return n * (n + 1) / 2;
    long long d = log10(n);
    vector<long long> a(d + 1);
    a[0] = 0, a[1] = 45;
    for (long long i = 2; i <= d; i++)
        a[i] = a[i - 1] * 10 + 45 * ceil(pow(10, i - 1));
    long long p = ceil(pow(10, d));
    long long msd = n / p;
    return msd * a[d] + (msd * (msd - 1) / 2) * p +
    	msd * (1 + n % p) + sumOfDigits(n % p);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    while(tt--)
    {
        long long n;
        cin>>n;
        ///cout<<ans<<endl;
        if(n<=10)
        {
            long long ans=(n*(n+1))/2;
            if(n>=1 && n<=9)
            {
                cout<<ans<<endl;
            }
            else
            {
                cout<<46<<endl;
            }
            continue;
        }

        long long ans1=11;
        ///n-=100;
        long long prev=10,main=11,next=10,k=1e18;
        for(long long i=100;i<=k;i*=10)
        {
             long long num=i,p=0;
             while(num)
             {
                 num=num/10;
                 p++;
             }
             ans1+=((p-1)*(i-prev))+1;
             prev=i;
             if(ans1<=n)
             {
                 next=i;
                 main=ans1;
             }
             else
             {
                 break;
             }
        }
        long long l=next,r=1e18,p=log10(next)+1,last=next,index=next;
      ///  cout<<l<<" "<<r<<endl;
        while(l<=r)
        {
            long long mid=(l+r)>>1;
            long long ok=main+(p*(mid-next));
            if(ok<=n)
            {
                last=ok;
                index=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        ///cout<<index<<endl;
        long long uttor=sumOfDigits(index);
        for(long long i=index+1;i<=1e18;i++)
        {
             string s=to_string(i);
             for(int j=0;j<s.size();j++)
             {
                  if(last+1<=n)
                  {
                      last++;
                      uttor+=s[j]-'0';
                      if(last==n)
                      {
                          break;
                      }
                  }
             }
             if(last==n)
             {
                 break;
             }
        }
        cout<<uttor<<endl;


    }
    return 0;
}
