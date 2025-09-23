#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string s;
    cin >> N;

    int cnt = 0;
    int n = 666;
    while(1){
        s = to_string(n);
        for (int i=1;i<s.length()-1;i++){
            if (s[i-1] == '6' && s[i] == '6' && s[i+1] == '6') {
                cnt++;
                break;
            }
        }
        if (cnt == N) break;
        n++;
    }
    cout << n;
}