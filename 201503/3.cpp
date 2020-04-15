/*
还有点问题
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
static const auto _ = []() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
#define freopen(); freopen("in.txt","r",stdin);

int months[][2] = {
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};
bool runnian(int year) {
    return (year%4==0&&year%100!=0)||(year%400==0);
}
int which_day_of_the_week(int year, int month) {
    int totalDay = 0;
    for(int i=1850;i<year;++i) {
        if(runnian(i)) totalDay += 366;
        else totalDay += 365;
    }
    for(int i = 0;i<month - 1; ++i) {
        totalDay += months[i][int(runnian(i))];
    }
    return totalDay % 7 + 2;
}
int main() {
    freopen();
    int a, b, c; cin>>a>>b>>c;
    int ys, yt; cin>>ys>>yt;
    ys = min(ys, yt);
    yt = max(ys, yt);
    for(int i = ys; i <= yt; ++i) {
        int day = which_day_of_the_week(i, a);
        //cout<<day<<endl;
        int cnt;
        /*
        if(d2 <= months[a][runnian(i)])
            printf("%d/%02d/%02d\n",i,a,d2);
        else cout<<"none"<<endl;
            */
    }
    return 0;
}
