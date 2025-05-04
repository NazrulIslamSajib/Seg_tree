#include<bits/stdc++.h>
using namespace std; 
///https://cses.fi/problemset/task/1730/ 
///mane hocche xor korle zero asle first bekti ta here jabe. na hole jotbi karon  non zero asle se ekta move e oi sob gula xor 
///zero korte parbe. tai second bekti ta here jabe . eta just ekta filer er jonno i
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
       long long x=0;
       for(int i=1;i<=n;i++)
       {
           long long y;
           cin>>y;
           x^=y;
       }
       cout<<((x!=0)?"first":"second")<<endl;
    }
    return 0;
}
