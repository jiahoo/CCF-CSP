#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define freopen(); freopen("input.txt","r",stdin);


struct node {
public:
    int x, y;
    node(){}
    node(int x_, int y_){x = x_;y = y_;}
    bool operator <(const node &oth)const
	{
		if(x!=oth.x)
			return x<oth.x;
		return y<oth.y;
	}
}Node[1010];
int mark[5];
map<node, int> mp;
int main() {
    freopen();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    for(int i=0;i<n;++i) {
        int x, y;cin>>x>>y;
        mp[node(x,y)] = 1;
        //cout<<Node[i].x<<" "<<Node[i].y<<endl;
        Node[i].x = x;
        Node[i].y = y;
        //cout<<Node[i].x<<" "<<Node[i].y<<endl;
        //cout<<mp[node(x, y)]<<endl;
    }
    for(int i=0;i<n;++i) {
        int x = Node[i].x;
        int y = Node[i].y;
        int cnt = 0;
        if(mp[node(x-1,y)]&&mp[node(x,y+1)]&&mp[node(x,y-1)]&&mp[node(x+1,y)]) {
            cnt += mp[node(x-1,y-1)] + mp[node(x-1,y+1)] + mp[node(x+1,y-1)] + mp[node(x+1,y+1)];
            ++mark[cnt];
        }
    }
    for(int i=0;i<5;++i) cout<<mark[i]<<endl;
    return 0;
}

