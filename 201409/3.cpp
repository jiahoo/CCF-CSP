#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define freopen(); freopen("in.txt","r",stdin);

void ComputePrefix(string s,int next[]){    //KMP献上，没用上
    int n = s.length();
    int q,k;
    next[0] = 0;
    for(k=0,q=1;q<n;q++){
        while(k>0 && s[k]!=s[q])
            k = next[k];
        if(s[k]==s[q])
            k++;
        next[q] = k;
    }
}
bool KMPMatcher(string text,string pattern) {
    int n = text.length();
    int m = pattern.length();
    int next[pattern.length()];
    ComputePrefix(pattern, next);

    for(int i=0,q=0;i<n;i++) {
        while(q>0 && pattern[q]!=text[i])
            q = next[q];
        if(pattern[q]==text[i])
            q++;
        if(q==m)
        {
            return i-m+1;
            q=0;
        }
    }
    return false;
}


bool judge(string s, string str, bool flag) {
    int i = 0;
    int j = 0;
    int s_size = s.size();
    int str_size = str.size();
    while(i!=s_size && j!=str_size) {
        if((flag && s[i] == str[j])||(!flag&&tolower(s[i])==tolower(str[j]))) {

            //cout<<"ij = "<<s[i]<<str[j]<<" ";
            ++i;
        }
        else i = 0;
        ++j;
    }
    if(i == s_size)
        return true;
    else return false;
}

int main() {
    freopen();
    string s;cin>>s;
    bool flag;cin>>flag;
    int n;cin>>n;
    while(n--) {
        string str;cin>>str;
        if(judge(s, str, flag)) cout<<str<<endl;
    }
}
