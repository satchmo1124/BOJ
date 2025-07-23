#include <bits/stdc++.h>
using namespace std;


/*
1. Naive Popcount

Time Complexity : O(32) (since unsigned integer has 32bit)

Check whether each bit is 1 with "&" operator. 
Check next bit with right shift (>>).   

*/
int naive_popcount(unsigned int n){
    int ret = 0;
    for (; n; n >>= 1) if (n & 1) ret++;
    return ret;
}


/*
2. Naive Popcount2 

Time Complexity : O(P) , where P is number of 1 bits.

ex)

n         =  01000110
n - 1     =  01000101 
n & n - 1 =  01000100

n         =  01000100
n - 1     =  01000011
n & n - 1 =  01000000

n         =  01000000
n - 1     =  00111111
n & n - 1 =  00000000

n & n - 1 하게되면 n의 가장 오른쪽에 있는 1인 비트를 제거할 수 있다. 

*/
int naive_popcount2(unsigned int n){
    int ret = 0;
    for (; n; n &= n - 1) ret++;
    return ret;
}

/*
3. Lookup Table

Time Complexity : O(2)

Assume that DB[i] is popcount for i in [0,65536). (65536 = 2^16)
Then for 32bit integer, divide with 16 bits and add popcount vals using DB.

*/
uint8_t DB[65536];
int DB_popcount(unsigned int n) {
    return DB[n & 0xFFFF] + DB[n >> 16];
}


/*
parallel counting 

Time Complexity : O(log(c)) (c : bit numbers)

m1 = 0x55555555 = 01010101010101010101010101010101(2) -> 0,1 패턴이 2개씩 반복
m2 = 0x33333333 = 00110011001100110011001100110011(2) -> 0,1 패턴이 4개씩 반복
m3 = 0x0F0F0F0F = 00001111000011110000111100001111(2) -> 0,1 패턴이 8개씩 반복
m4 = 0x00FF00FF = 00000000111111110000000011111111(2) -> 0,1 패턴이 16개씩 반복
m5 = 0x0000FFFF = 00000000000000001111111111111111(2) -> 0,1 패턴이 32개씩 반복

즉, m(i) 는 0,1 패턴이 2^i 개씩 반복

아래의 연산 1번은 길이 2인 패턴을 적용해 
( n >> 1 & m1 ) + (n & m1) 을 연산한다. 
연산 과정은 길이 2인 패턴이 약간 Convolution Layer 느낌으로다가 
결과가 "n을 2개씩 묶었을때 1의 개수"가 되도록 한다. 



*/

int popcount(unsigned int n){
    n  = (n >>  1 & 0x55555555) + (n & 0x55555555);
    n  = (n >>  2 & 0x33333333) + (n & 0x33333333);
    n  = (n >>  4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n  = (n >>  8 & 0x00FF00FF) + (n & 0x00FF00FF);
    n  = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}


/******************************/



int signed_popcount(int signed_n){
    unsigned int n = signed_n;
    n  = (n >>  1 & 0x55555555) + (n & 0x55555555);
    n  = (n >>  2 & 0x33333333) + (n & 0x33333333);
    n  = (n >>  4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n  = (n >>  8 & 0x00FF00FF) + (n & 0x00FF00FF);
    n  = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}

int main(){
    int n = 27834;
    cout << "popcount : " << popcount(n) << "\n";
    cout << "signed_popcount : " << signed_popcount(n) << '\n';
}

//https://blog.naver.com/jinhan814/222540111549
