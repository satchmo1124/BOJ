#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long 
using namespace std;

/*
0 : A
1 : B
2 : C
3 : D
4 : E
5 : F

*/

int main(){
    ull N;
    cin >> N;
    
    vector<int>dice(6,0);

    int min = 51;
    int max = 0;
    
    
    for (int i=0;i<6;i++) {
        cin >> dice[i];
        if (min > dice[i]) min = dice[i];
        if (max < dice[i]) max = dice[i];
    }

    if (N==1){
        int sum = 0;
        for (int i=0;i<6;i++){
            sum += dice[i];
        }
        sum -= max;
        cout << sum;
        return 0;
    }
    

    int first = min; 

    int second = 101;

    for (int i=0;i<6;i++){
        for (int j=i+1;j<6;j++){
            if ((i == 0 && j == 5) || (i == 1 && j == 4) || (i==2 && j==3)) continue;
            if (second > dice[i] + dice[j]) second = dice[i] + dice[j];
        }
    }

    
    int third = 151;

    int list[8][3] = {
        {0,1,2},
        {0,1,3},
        {0,2,4},
        {0,3,4},
        {5,1,2},
        {5,1,3},
        {5,2,4},
        {5,3,4}
    };

    for (int i=0;i<8;i++){
        int list_sum = dice[list[i][0]] + dice[list[i][1]] + dice[list[i][2]];
        if (third > list_sum) third = list_sum;
    }

   

    ull one_side = first * (N-2) * (5*N -6);
    ull two_side = second * 4 * (2*N-3);
    ull three_side = third * 4;
    

    ull res = one_side + two_side + three_side;
    
    cout << res;
}


/*

 근데 그걸 떠나서. 
 N이 int일 때랑 ull일 때랑 값이 다름. 
 ull일 때는 
 249999200000600
 int일 때는 
 2038602328 임. 

 아마도 5*N-6할때 overflow나서 그런가?  중간에 세 항끼리 곱하는 과정에서 overflow 났을수도. 
 보통 곱셈의 결과를 레지스터에 저장하는데 이게 int면 rdi인가 거기에 저장되는데 그게 비트 제한나서 곱하다가 오버플로우 ㅇㅇ. 
 그래서 만약 곱해서 큰 수가 나온다면, 그 곱하는 항들 안에 있는 변수도 메모리를 크게 설정해줘야함. 
 */


 /*
 
근데 이해가 안 되는게.
(N-2) * (4*N -6) 랑 (4*(N-2)*(N-1) + (N-2)*(N-2)) 랑 계산하면 값이 다르게 나옴. 
 는 틀림. 왜냐면 오른쪽 계산하면 5*N-6임. 


 */