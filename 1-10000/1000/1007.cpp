#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Point{
    int x,y;
};

void MinMatch(vector<Point>&V,int N){
    int R = N / 2;
    vector<bool>v(N);

    ll x,y;
    ll min = 32e12 + 1,local = 0;

    fill(v.begin(),v.begin()+R,true);
    do{
        x = y = 0;
        for (int i=0;i<N;i++){
            if (v[i]){
                x += V[i].x;
                y += V[i].y;
            }
            else{
                x -= V[i].x;
                y -= V[i].y;
            }
        }
        local = x * x + y * y;
        if (min > local) min = local;

    }while(prev_permutation(v.begin(),v.end()));

    long double res = sqrt(min);
    cout << fixed;
    cout.precision(7);
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,N;
    Point p;

    cin >> T;
    for (int i=0;i<T;i++){
        cin >> N;
        vector<Point>V;
        for (int i=0;i<N;i++){
            cin >> p.x >> p.y;
            V.push_back(p);
        }
        MinMatch(V,N);
    }
}

/*
TC :

nC(n/2) * n * T 

20C10 = 184756
20C10 * 20 = 3695120

좌표 합 최대 : (200,000 * 20)^ 2 * 2 =  
*/

/*
배운 것:

- next_permutation
https://stackoverflow.com/questions/9430568/generating-combinations-in-c


- 조합

- aeb -> a * 10 ^ b

- 제곱근 정확하게 출력하기

- `std::sqrt` 와 관련된 다른 글
https://www.acmicpc.net/board/view/103111
*/

/*
더 궁금한 점:

Q:
20C10이렇게 하면, 사실 여기서는 N/2 묶음으로 두 덩이씩 
분할만 하면 되므로, 총 경우의 수는 20C10 / 2가 된다. 
하지만, prev_permutation을 사용하면 20C10의 경우를 다 확인하게 되므로..


Q:
prev_permutation은 어떻게 작동할까?


Q : 수 자체가 해당 자릿수까지 구해진건지.
아니면 수는 정확하게 구했는데 출력이 짤린건지.

A : 출력이 짤림.
cout << fixed;
cout.precision(7);
하면 됨.
*/