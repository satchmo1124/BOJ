#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll S,C,tmp;
    cin >> S >> C;
    vector<int>v; // 파 길이
    for (int i=0;i<S;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    ll l = 0;
    ll h = *max_element(v.begin(),v.end());
    while (l < h){
        ll mid  = (l + h + 1) /2;
        ll local_sum = 0;

        for (int i=0;i<S;i++){
            local_sum += v[i] / mid;
        }
        if (local_sum >= C){
            l = mid;
        }
        else{
            h = mid -1 ;
        }
    }
    ll res = accumulate(v.begin(),v.end(),0L) - C * l;
    cout << res;
}