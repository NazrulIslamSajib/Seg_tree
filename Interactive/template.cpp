#include<bits/stdc++.h>
using namespace std;
int cnt=0;
bool query(int mid)
{
    cnt++;
    if(cnt>limit)
    {
        assert(0); ///ekhane dukle program crash korbe tokhn run time error dibe
    }
}
int main()
{
    ios::sync_with_stdio(false); ////eigula deoya jabe na.
    cin.tie(0);
    long long tt;
    cin>>tt;
    while(tt--)
    {
            ///protita output er pore flush korte hoy. but c++ e endl dilei flush hoye jay.
            ///endl na dile idleness limit exceeded dibe. karon hocche ami je query korchi se
            ///sathe sathe answer pabe na . endl dile sathe sathe output pabe.

            ///assert(0) dile jodi  run time error ase thole bujbo ami query limit beshi kore felchi
            ///assert(0) deoyar pore wrong answer ase tahole bujbo ami guess e vul korchi.
            ///assert(0) oi condition ta true hole program ta crash korbe.
            ///example
            int cnt=0;
            query(mid); ///eta value practice query function 

    }
    return 0;
}



