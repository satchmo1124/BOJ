#include <iostream>

using namespace std;


int main(){

    int N;
    cin >> N;

    int res = N;
    int cycle = 0;
    int a,b,tmp;
    do{
        a = res / 10;
        b = res % 10;

        tmp = (a + b) % 10;
        a = b;
        b = tmp;
        
        res = a * 10 + b;

        cycle++;
    }while(res != N);

    cout << cycle;
}

/*
26
-> 8 

68
8 14
84

4 12
42

2 6
26


N == 0 -> 1


*/