#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll gcd(ll a, ll b){
    if (a < b) swap(a,b);
    ll r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}

int main(){
    int N;
    cin >> N;
    ll tmp;
    if (N == 1){
        cout << 4;
        return 0;
    }
    vector<ll>v;
    for (int i=0;i<N;i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    ll n1 = v[N-2];
    ll n2 = v[N-1];
    cout << lcm(n1,n2);
}