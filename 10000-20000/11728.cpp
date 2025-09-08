#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N,M;
    cin >> N >> M;
    vector<int>A(N,0);
    vector<int>B(M,0);

    for (int i=0;i<N;i++) cin >> A[i];
    for (int i=0;i<M;i++) cin >> B[i];

    auto a_it = A.begin();
    auto b_it = B.begin();

    while(a_it != A.end() && b_it != B.end()){
        if (*a_it > *b_it){
            cout << *b_it << " ";
            b_it++;
        }
        else{
            cout << *a_it << " ";
            a_it++;
        }
    }
    while(a_it !=A.end()) {
        cout << *a_it << " ";
        a_it++;
    }
    while(b_it !=B.end()) {
        cout << *b_it << " ";
        b_it++;
    }

}