#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N,K,tmp;
    cin >> N >> K;
    
    vector<int>v;
    for (int i=0;i<N;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    ll l = 0;
    ll h = *max_element(v.begin(),v.end());


    while (l < h){
        ll mid = (l + h + 1)/2;
        ll local_sum = 0;
        for (int i=0;i<N;i++){
            local_sum += v[i] / mid;
        }
        if (local_sum >= K){
            l = mid;
        }
        else{
            h = mid - 1;
        }
    }
    cout << l;
}