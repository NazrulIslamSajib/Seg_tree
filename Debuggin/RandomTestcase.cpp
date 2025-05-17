#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
int main()
{

  int n=rng()%5+1; ///1 theke 5 pojjonot value asbe
  cout<<n<<endl; ///input n
  for(int i=0;i<n;i++)
  {
      cout<<int(rng()%10)-5<<" ";///-5 theke 4 er modde value dibe
  }

 return 0;
}
