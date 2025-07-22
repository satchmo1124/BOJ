#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;


int main(){
    int N,M;
    cin >> N >> M;
    priority_queue<int,vector<int>>A;
    priority_queue<int,vector<int>>B;

    int a,b;
    
    for (int i=0;i<N;i++){
        cin >> a; A.push(a);
    }

    for (int i=0;i<M;i++){
        cin >> b; B.push(b);
    }

    while (!B.empty()){
        b = B.top();

        int b_len = B.size();
        while(b != 0 && !A.empty()){
            a = A.top();
            if (a >= b_len){
                A.pop();
                b--;
            }
            else{
                cout << "NO";
                return 0;
            }
        }
        B.pop();

        if (A.empty()){
            break;
        }
        
    }
    if (!B.empty()){
        cout << "NO";
        return 0;
    }
    cout << "YES";
    
}

/*
큰 사역을 한번에 병사 써서 없애고 다음 사역 봐야지
큰 사역 하나씩 줄인다음 끝내기 전에 다른 사역 뽑고 그러면 안 됨.

*/