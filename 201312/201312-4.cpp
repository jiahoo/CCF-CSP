/*
	author:jiahoo
	dp
*/
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
#define freopen(); freopen("in.txt","r",stdin);

long long a[1000][1000];
int main(){
    freopen();
    int n;cin>>n;
    a[0][0] = 1;
    for(int i=1;i<n;++i){
        int j = i-1;
        a[i][0] = a[j][0]%mod;
        a[i][1] = (a[j][0] + a[j][1]*2)%mod;
        a[i][2] = (a[j][0] + a[j][2])%mod;
        a[i][3] = (a[j][1] + a[j][3]*2)%mod;
        a[i][4] = (a[j][1] + a[j][2] + a[j][4]*2)%mod;
        a[i][5] = (a[j][3] + a[j][4] + a[j][5]*2)%mod;
    }
    cout<<a[n-1][5]<<endl;
}
