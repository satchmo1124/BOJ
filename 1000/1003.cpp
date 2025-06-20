#include <iostream>

using namespace std;


// int fibonacci(int n) {
//     if (n == 0) {
//         printf("0");
//         return 0;
//     } else if (n == 1) {
//         printf("1");
//         return 1;
//     } else {
//         return fibonacci(n-1) + fibonacci(n-2);
//     }
// }

int zero[41]; // zero[i] := i번째 index가 출력하는 0의 개수
int one[41];

int zero_fib(int N){
    if (zero[N] != -1){
        return zero[N];
    }
    zero[N] = zero_fib(N-1) + zero_fib(N-2);

    return zero[N];
}

int one_fib(int N){
    if (one[N] != -1){
        return one[N];
    }
    one[N] = one_fib(N-1) + one_fib(N-2);

    return one[N];
}

int main(){
    int T;
    cin >> T;

    for (int i=0;i<41;i++){
        zero[i] = one[i] = -1;
    }

    zero[0] = 1; zero[1] = 0;
    one[0] = 0; one[1] = 1;

    for (int i=0;i<T;i++){
        int N;
        cin >> N;
        cout << zero_fib(N) << " " << one_fib(N) << '\n';
    }
}