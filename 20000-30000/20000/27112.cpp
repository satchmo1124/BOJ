#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task{
    int d;
    int t;
};

bool cmp(Task a,Task b){
    if (a.d != b.d) return a.d < b.d;
    return a.t < b.t;
}

int main(){
    int N;
    cin >> N;
    vector<Task>v;
    Task task;

    int max_d = 0; // 최종 작업 일자
    
    for (int i=0;i<N;i++){
        cin >> task.d >> task.t;
        if (max_d < task.d) max_d =task.d;
        v.push_back(task);
    }
    sort(v.begin(),v.end(),cmp);

    int d = 0;
    int t = 0;


    bool able = true;

    for (int i=0;i<N;i++){
        task = v[i];
        while(task.t){
            task.t--;
            
            if (d < task.d){
                d++;
                if (d % 7 == 5) {d += 2;}
            }
            else{ t++;}

            if (t > task.d) {
                able = false;
                break;
            }
            
        }
        if (!able){
            cout << -1;
            return 0;
        }
    }
    cout << t;
}


/*
자. 이 개같은 문제 어케 품. 
시간외 근무를 최소로 하고 싶음. 
월 ~ 금 평시 근무. 토 일은 쉼. (놀토 없음 ㅇㅇ)

주 7일 야근 가능. 

마감 기한 : d
걸리는 시간  : t 

d = 4 면 4일까지 해서 끝내야함. 

자 그래서 d,t가 주어졌을떄 야근 최대한 안 하려면 어케 해야 함?

이론 1: 
일단 마감기한 급한 놈들부터 우선적으로 채워넣기. 
마감기한 순 오름차순 정렬. 그리고 평시 근무 번호로 채워넣기.

만약 평시 근무 기한 꽉 찼으면 시간 외 근무로 넣기.

1 5 4
2 6 2
3 2 1
4 9 1
5 10 3

주의할 점 : 6,7일은 평시 근무 없음. 

*/