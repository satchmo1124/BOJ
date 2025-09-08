#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll N,F;
    cin >> N;
    cin >> F;
    int left = N % 100;
    N -= left;
    
    ll tmp;
    int i;
    for (i=0;i<100;i++){
        tmp = N + i;
        if (tmp % F == 0) break; 
    }
    if (i<10){
        cout << "0" << i;
    }
    else{
        cout << i;
    }
}

/*
Q : 안 나눠떨어질 수도 있나
*/