#include <bits/stdc++.h>
using namespace std;



int main(){
    string s;
    while(1){
        getline(cin,s);
        if (s == "#"){
            break;
        }
        int cnt = 0;
        for (int i=0;i<s.length();i++){
            char c = s[i];
            if (c >= 'A' && c <= 'Z')  c += 'a'-'A'; 
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}


/*
string to hashmap...? func 구현..ㄱ?
*/