#include <iostream>
#include <vector>
#include <queue>
#include <deque>

#define swap(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    bool a;
    int b;
    vector<bool>A;
    deque<int>d;

    
    cin >> N;

    for (int i=0;i<N;i++){
        cin >> a;
        A.push_back(a);
    }
    int e;
    for (int i=0;i<N;i++){
        cin >> e;
        if (A[i] == 0){
            d.push_front(e);
        }
    }
    cin >> M;
    for (int i=0;i<M;i++){
        cin >> e;
        d.push_back(e);
    }
    for (int i=0;i<M;i++){
        cout << d.front() << " ";
        d.pop_front();
    }
}

/*

O(M*N) -? 100000 * 100000 = 10,000,000,000

*/