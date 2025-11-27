#include <bits/stdc++.h>
using namespace std;

bool is_pattern(vector<int>P,int len){
    int i=0;
    if (P[i]){
        // 1
        case_1:
        if (++i == len) return false;

        if (P[i]) return false;
        // 0
        if (++i == len) return false;
        
        if (P[i]) return false;
        // 0
        case_1_1:

        if (++i == len) return false;
        while(i < len && P[i] == 0) i++;
        if (i == len) return false;
        // 1
        if (++i == len) return true;
        if (P[i]){
            // 1
            while(i < len && P[i] == 1) i++; // 1+
            if (i == len) return true;
            //0
            if (++i == len) return false;
            if (P[i]){
                // 1
                goto case_2_1;
            }
            else{
                // 0
                goto case_1_1;
            }
        }
        else{
            // 0
            goto case_2;
        }
    }
    else{
        // 0
        case_2:
        if (++i == len) return false;
        if (P[i]){
            // 1
            case_2_1:
            if (++i == len) return true;
            if (P[i]) goto case_1;
            else goto case_2;
        }
        else{
            // 0
            return false;
        }
    }
}

int main(){
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        string S;
        cin >> S; 
        int len = S.length();
        vector<int>P;
        for (int i=0;i<(int)S.length();i++) P.push_back(S[i]-'0');
        if (is_pattern(P,len)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }   
}




    // auto iter = P.begin();
    
    // if (*iter++){
    //     case_1:
    // }
    // else{
    //     case_2:
    //     // 0
    //     if (iter == P.end()) return false;
    //     if (*iter++){
    //         // 1
    //         if (iter == P.end()) return true;
    //         if (*iter++) {
    //             // 1
                 
    //         }
    //         else{
    //             // 0
    //         }
    //     }
    //     // 0
    //     else return false;
    // }