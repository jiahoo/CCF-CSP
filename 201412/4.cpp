#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
static const auto _ = []() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
#define freopen(); freopen("in.txt","r",stdin);

class Node {
public:
    int a, b, c;
};
vector<Node> res;
int node[100000]; //每个节点
int Rank[100000]; //树的高度

//初始化n个节点
void Init(int n){
    for(int i = 0; i < n; i++){
        node[i] = i;
        Rank[i] = 0;
    }
}
//查找当前元素所在树的根节点(代表元素)
int find(int p){
    /*if(x == node[x])
        return x;
    return node[x] = find(node[x]); //在第一次查找时，将节点直连到根节点
    */
    while (p != node[p]) {
        node[p] = node[node[p]]; // 路径压缩，使得下次查找更快
        p = node[p];
    }
    return p;
}
//合并元素x， y所处的集合
void Unite(int x, int y){
    //查找到x，y的根节点
    x = find(x);
    y = find(y);
    if(x == y)
        return ;
    //判断两棵树的高度，然后在决定谁为子树
    if(Rank[x] < Rank[y]){
        node[x] = y;
    }else{
        node[y] = x;
        if(Rank[x] == Rank[y]) Rank[x]++;
    }
}
//判断x，y是属于同一个集合
bool same(int x, int y){
    return find(x) == find(y);
}



int main() {
    freopen();
    int n, m;cin>>n>>m;
    for(int i=0;i<m;++i) {
        Node nd;
        cin>>nd.a>>nd.b>>nd.c;
        res.push_back(nd);
    }
    sort(res.begin(), res.end(),[](const Node& x, const Node& y) {
        return x.c < y.c;
    });
    Init(n);
    int sum = 0;
    for(const auto& nnn:res) {
        if(find(nnn.a)!=find(nnn.b)) {
            sum += nnn.c;
            Unite(nnn.a, nnn.b);
        }
    }
    cout<<sum<<endl;
}
