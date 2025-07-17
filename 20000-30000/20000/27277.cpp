#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,tmp;
    cin >> N;

    vector<int>v;   

    for (int i=0;i<N;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());

    int tot = 0;
    tot += v[N-1];
    int front = 0;
    int back = N-2;
    while(back > front) {
        tot += v[back--] - v[front++];
    }
    cout << tot;
}