#include <bits/stdc++.h>
#define ll long long
using namespace std;




int main(){
    int K,tmp;
    cin >> K;
    vector<int>v;
    for (int i=0;i<K;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    int Q;
    cin >> Q;
    
    if (K == 0){
        for (int i=0;i<Q;i++){
            ll T,p;
            cin >> T >> p;
            cout << T + 1 <<'\n';        
        }
        return 0;
    }
    
    vector<int>rev_v = v;
    reverse(rev_v.begin(),rev_v.end());
    ll v_min = v[0];
    ll v_max = v[K-1];

    for (int i=0;i<Q;i++){
        ll T,p;
        cin >> T >> p;
        vector<ll>P;
        vector<ll>rev_P = P;
        reverse(rev_P.begin(),rev_P.end());

        for (ll j=0;j<=T;j++){
            tmp = p - T + 2 * j;
            P.push_back(tmp);
        }
        int res = 0;
    
       

        if (v_max < p) {
            res = P.end() - upper_bound(P.begin(),P.end(),v_max);
        }
        else if (p < v_min){
            reverse(P.begin(),P.end());
            res = P.end() - upper_bound(P.begin(),P.end(),v_min,greater<>());
        }
        else{
            int obst_upper = *upper_bound(v.begin(),v.end(),p);
            int obst_lower = *upper_bound(rev_v.begin(),rev_v.end(),p,greater<>());

            int lower = upper_bound(P.begin(),P.end(),obst_lower) - P.begin();
            int upper = rev_P.begin() - upper_bound(rev_P.begin(),rev_P.end(),obst_upper,greater<>());

            int res = upper - lower;
            // for (auto it = P.begin();it!=P.end();it++){
            //     if (obst_lower < *it && *it < obst_upper) res++;
            // }
        }
        cout << res << '\n';
    }
}