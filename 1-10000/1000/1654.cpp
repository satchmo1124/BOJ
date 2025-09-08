#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int K,N;
    cin >> K >> N;
    vector<int>cable(K,0);
    for (int i=0;i<K;i++) cin >> cable[i];
    int max_len = *max_element(cable.begin(),cable.end());
    
    ll l = 0;
    ll h = max_len;
    ll m;
    ll cable_n = 0;
    while(l < h){
        m = (l + h + 1) / 2;
        cable_n = 0;
        for (int i=0;i<K;i++) {
            cable_n += cable[i] / m;
        }
        if (cable_n >= N ){
            l = m;
        }
        else{
            h = m - 1;
        }
    }
    cout << l;    
}










/*
이미 갖고 있는 랜선 개수  : K 
필요한 랜선 개수 : N 

만들 수 있는 랜선의 최대 길이 =? 

아이디어 : 

만들 수 있는 랜선 개수가 가장 많으려면 랜선의 길이 단위가 가장 작아야 한다. 즉 최댓값 구하는 척 하는 최솟값 문제. 


0~최대 길이 까지 범위 잡기.
그리고 절반씩 줄이면서 길이 선택. 해당 길이로 N개 이상 만들 수 있으면 길이 줄이기. 




*/