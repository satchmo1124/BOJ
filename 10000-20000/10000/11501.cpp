#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define ll long long 

struct Stock {
    int i;
    int val;
};

bool stock_sort(Stock s1,Stock s2) {
    if (s1.val == s2.val){
        return s1.i < s2.i;
    }
    return s1.val > s2.val;
}

bool compare(){
    ll x1 = pow(2,31) -1;
    ll x2 = pow(10,10);
    return x1 < x2;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //if (compare()) cout << "unsigned int can't handle 10^10" << '\n';

    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int N;
        cin >> N;

        vector<int>price;
        vector<Stock>stock;
        
        for (int i=0;i<N;i++){
            Stock s;
            s.i = i; cin >> s.val;
            price.push_back(s.val);
            stock.push_back(s);
        }

        sort(stock.begin(),stock.end(),stock_sort);

        int stock_i = 0;
        int price_i = 0;
        
        ll tot = 0;

        for (; price_i < N ;price_i++) {

            while (stock[stock_i].i < price_i) {
                stock_i++;
            }
            
            if (price_i <= stock[stock_i].i) {
                int margin  = stock[stock_i].val - price[price_i]; 
                if (margin <= 0) {
                    stock_i++;
                    continue;
                }
                tot += margin;
            }
        }
        cout << tot << '\n';
    }
}

/*
위에서 인덱스 설정할 때 이미 지나간 price의 인덱스를 비교하면 안 된다. 
N <= 1,000,000
주가 <= 10,000
이므로 최대 이익을 나타내는 변수는 unsigned int ㄱㄱ ->이것도 아님.
long long 으로 해야함. 

왜일까..

int ->  [-2^16 , 2^16)
unsigned int -> 이론상 [0,2^31)

Max_N = 10^6
Max_stock = 10^4

Max_N * Max_stock = 10^10

2^31 vs 10^10

2^21 vs 5^10
4^10 * 2 vs 5^10

2 vs (5/4) ^ 10



*/