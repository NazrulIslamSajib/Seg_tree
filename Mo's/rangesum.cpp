///(n+q)*sqrt(n)
#include<bits/stdc++.h>
using namespace std;

const int maxn = 200002;
int K, ans[maxn], a[maxn], sum;

struct Query{
    int index, L, R;
    bool operator < (const Query &other) const {
		int block_own = L/K;
		int block_other = other.L/K;
		if(block_own == block_other)
            return R < other.R;
		return block_own < block_other;
	}
}query[maxn];

void add(int index){
    sum+=a[index];
}

void remove(int index){
    sum-=a[index];
}

int main(){
    int n;
    cin>>n;
    
    K = sqrt(n);
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    int q;
    cin >> q;
    
    for(int i=0;i<q;i++){
        cin >> query[i].L >> query[i].R;
        query[i].index = i;
    }
    sort(query, query+q);
    int L=0, R=-1;
    for(int i=0;i<q;i++){
        while(R<query[i].R) add(++R);
        while(L<query[i].L) remove(L++);
        while(R>query[i].R) remove(R--);
        while(L>query[i].L) add(--L);
        ans[query[i].index] = sum;
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
