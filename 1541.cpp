#include <bits/stdc++.h>
using namespace std;


int Solve(vector<char>oper,vector<int>num,int L){
    int res = num[0];
    int local_sum = 0;
    int tmp;
    bool is_neg = false; // 이전에 -가 나왔는지

    int i = 1;
    char op;
    while(i<L){
        tmp = num[i];
        op = oper[i-1];

        if (op == '+'){
            if (is_neg){
                local_sum += tmp;
            }
            else{
                res += tmp;
            }
        }
        else if (op == '-'){
            if (is_neg){
                res -= local_sum;
                local_sum = tmp;
            }
            else{
                local_sum += tmp;
                is_neg = true;
            }
        }
        i++;
    }
    if (is_neg){
        res -= local_sum; 
    }
    return res;
}

int main(){
    string input,tmp;
    cin >> input;

    vector<char>oper;
    vector<int>num;

    int n=0;
    int idx=0;
    int len = input.length();
    for (int i=0;i<len;i++){
        if (input[i] == '-' || input[i] == '+'){
            tmp = input.substr(idx,i-idx);
            n = 0; idx = i+1;
            for (int i=tmp.length()-1;i>=0;i--){
                n +=  (tmp[i]-'0') * pow(10,tmp.length()-1-i);
            }
            num.push_back(n);


            oper.push_back(input[i]);
        }
    }
    tmp = input.substr(idx,len-idx);
    n = 0;
    for (int i=tmp.length()-1;i>=0;i--){
        n +=  (tmp[i]-'0') * pow(10,tmp.length()-1-i);
    }
    num.push_back(n);
    

    int L = num.size();
    cout << Solve(oper,num,L);
}