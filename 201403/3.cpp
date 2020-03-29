/*
参照 写法
*/
#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define freopen(); freopen("in.txt","r",stdin);

int main(){
    freopen();
    int type[128] = {0}; //1为无参数，2为有参数
    string s,t;cin>>s;
    for(int i=0;i<s.size();++i) {
        if(s[i+1]==':'){
            type[s[i++]] = 2;
        }
        else{
            type[s[i]] = 1;
        }
    }
    int n;scanf("%d%*c", &n);
    for(int i=0;i<n;++i) {
        getline(cin,s);
        //cout<<"s:"<<s<<endl;
        stringstream ss(s);
        map<char,string> mp;
        ss>>s;  //吸收命令行工具
        while(ss>>s){
            if(s.size()==2&&s[0]=='-'&&type[s[1]]==1) {
                mp[s[1]] = "";
            }
            else if(s.size()==2&&s[0]=='-'&&type[s[1]]==2&&ss>>t){
                mp[s[1]] = t;
            }
            else break;
        }
        cout<<"Case "<<i+1<<":";
        for(auto&p:mp){
            if(type[p.first]==1) cout<<" -"<<p.first;
            else cout<<" -"<<p.first<<" "<<p.second;
        }
        cout<<endl;
    }
}
