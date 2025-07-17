#include <iostream>
#include <queue>
#include <functional>

using namespace std;

struct cmp {
    bool operator()(int a,int b) {  // b가 a보다 우선순위가 높다. 그러한가?
        if (b == 20){
            return true;
        }
        else if (b % 10 == 0 && b != 10){
            if (a == 20) return false;
            else if (a % 10 == 0 && a != 10){
                return a > b; // 둘 다 10의 배수면 둘 중 작은 수
            }
            else {
                return true;
            }
        }
        else if (b > 10){
            if (a <= 10) {
                return true;
            }
            else{
                return false;
            }
        }
        else {
            return false;
        }
        
    }
};

int main(){
    int N,M;
    cin >> N >> M;

    priority_queue<int,vector<int>,cmp>pq;
    
    int cake;

    for (int i=0;i<N;i++){
        cin >> cake;
        pq.push(cake);
    }

    for (int i=0;i<M;i++){
        cake = pq.top();
        pq.pop();
        if (cake <= 10) pq.push(cake);
        else{
            pq.push(10);
            pq.push(cake-10);
        }
    }
    int cnt = 0;
    while(!pq.empty()){
        if (pq.top() == 10) cnt++;
        pq.pop();
    }
    cout << cnt;
}
