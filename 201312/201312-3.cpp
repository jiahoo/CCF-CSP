#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
#define freopen(); freopen("in.txt","r",stdin);


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int n = heights.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX)); //dp -> minst height from i to j
        dp[1][1] = heights[0];
        for(int i=1;i<=n;++i) dp[i][i] = heights[i-1];
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                dp[i][j] = min(dp[i][j-1],heights[j-1]);
            }
        }
        int ans = 0;
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;++j){
                ans = max(ans,(j-i+1)*dp[i][j]);
            }
        }
        return ans;
    }
};
int main(){
    freopen();
    int n;cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;++i) cin>>heights[i];
    Solution solution;
    cout<<solution.largestRectangleArea(heights)<<endl;
}
