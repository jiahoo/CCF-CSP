#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define freopen(); freopen("in.txt","r",stdin);

/*typedef struct node{
    int row;
    int col;
    int step;
    node(){}
    node(int r,int c,int s){
        row = r;
        col = c;
        step = s;
    }
}Point;
*/

int dirs[5] = {-1, 0, 1, 0, -1};
int buyer[1001][1001];
int isvisited[1001][1001];
int n,m,k,d;
int x,y,c;
int buyer_num;
//queue<Point> q;
queue<pair<int, int>> que;
long long bfs()
{
    long long ans = 0;
    while(!que.empty()/*!q.empty()*/){
        //Point temp = q.front();
        auto temp = que.front();
        //q.pop();
        que.pop();
        for(int i = 0 ; i < 4 ; i++){
            auto temp2 = temp;
            x = temp.first/n + dirs[i];
            y = temp.first%n + dirs[i+1];
            temp2.second = temp.second + 1;
            //v.row = temp.row+dirs[i];
            //v.col = temp.col+dirs[i+1];
            //v.step = temp.step+1;
            if(x < 0 || x >= n || y < 0 || y >= n){
                continue;
            }
            if(isvisited[x][y]){
                continue;
            }
            if(buyer[x][y] > 0){
                isvisited[x][y] = 1;
                ans += buyer[x][y]*temp2.second;
                buyer_num--;
                if(buyer_num == 0){
                    return ans;
                }
            }
            isvisited[x][y] = 1;
            temp2.first = x*n + y;
            que.push(temp2);
        }
    }
}

int main() {
    //freopen();
    cin>>n>>m>>k>>d;
    buyer_num = 0;
    for(int i=0;i<m;++i){
        cin>>x>>y;
        isvisited[x-1][y-1] = 1;
        //q.push(Point(x-1,y-1,0));
        que.push(pair<int,int>((x-1)*n+(y-1),0));
    }
    for(int i=0;i<k;++i){
        cin>>x>>y>>c;
        if(buyer[x-1][y-1]==0) ++buyer_num;
        buyer[x-1][y-1] += c;
    }
    for(int i=0;i<d;++i){
        cin>>x>>y;
        isvisited[x-1][y-1] = 1;
    }
    long long ans = bfs();
    cout<<ans<<endl;
}
