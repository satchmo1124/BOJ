#include <iostream>
using namespace std;


int main(){

    int G[50][50] = {0,};

    int G_row[50] = {0,};
    
    
    int N,M;
    cin >> N >> M;

    for (int i=0;i<N;i++){
        string s;
        cin >> s;
        for (int j=0;j<s.length();j++){
            G[i][j] = s[j]-'0';
        }
        G_row[i] = 0;
    }
    
    

    int K;
    cin >> K;

    if (K > M) { 
        K = K - 2 * ((K-M+1)/2); // K 최소화
    }

    int row_max = 0;

    for (int i=0;i<N;i++){
        // 행 하나 고르기
        if (G_row[i]){continue;} // 이미 이전에 본 행

        int zero_num = 0; 
        
        // 해당 행의 0개수 세기

        for (int j=0;j<M;j++){
            if (!G[i][j]){
                zero_num++;
            } 
        }

        int row_num = 1; // 중복 행 개수
        bool is_equal = true; 
        
        // 같은 행인지 체크 , 중복되는 행 개수 구하기

        for (int other_i=0;other_i<N;other_i++){
            if (other_i == i) continue;
            is_equal = true;

            for (int j=0;j<M;j++){
                if (G[i][j]!=G[other_i][j]){
                    is_equal =false;
                    break;
                }
            }
            if (is_equal){
                G_row[other_i] = 1;
                row_num += 1;
            }
        } 

        // K번으로 불을 킬 수 있는지 체크
        
        if (zero_num <= K && (zero_num % 2 == K % 2)){
            if (row_max < row_num ){
                row_max = row_num;
            }
        }
    }
    cout << row_max ;
}


// for (int i=0;i<N;i++){
    //     for (int j=0;j<M;j++){
    //         cout << G[i][j]<<" ";
    //     }
    //     cout << '\n';
    // }
