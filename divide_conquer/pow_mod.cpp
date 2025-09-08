#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

//A^B (mod M) 빨리 구하는 법


/*
1. Exponentiation By Squaring 

x^y 에서 y를 이진수로 생각. y = dk dk-1 dk-2 ... d0 라 하자. 
이때 di = 1인 경우, 결과에 x^(2^i)를 곱하면 된다.  

TC : O(log y) -> loop가 log y만큼 돌아가므로
*/
ll power_modular_init(ll x,ll y){
    ll res = 1;
    while (y > 0){
        if (y & 1) res *= x;
        x *= x; // x의 계수가 1,2,4,...로 2의 거듭제곱만큼 증가한다. 
        y >>= 1;
    }
    return res;
}

ll power_mod_with_div(ll x,ll y,ll M){
    ll res = 1;
    while(y>0){
        if (y & 1) res = res * x % M;
        x = x * x % M;
        y >>= 1;
    }
    return res;
}

/*
위의 코드에서 res * x 할 때 이미 오버플로우 일어날 수 있음. (각각이 sqrt(2^63-1) 보다 크거나 같은 경우)
long long : 64bits -> [-2^63,2^263) 
그래서 곱셈이 문제이므로, 이를 덧셈 연산을 통해 중계해주면 오버플로우 피할 수 있음.
*/


/*
x가 2^62인 경우 
*/

ll add_modular(ll x,ll y,ll M){
    const ull threshold = (1UL << 62); // 2^62
    if (M >= (ll)threshold){
        ull ux = (ull)x % (ull) M;
        ull uy = (ull)y % (ull) M;

        ull res = (ux + uy) % (ull)M;
        return (ll)res;
    }
       
    else{
        x %= M;
        y %= M;
        if (x < 0) x += M;
        if (y < 0) y += M;
        
        ll res = (x + y) % M ;
        return res;
    }
}


ll multiply_modular (ll x, ll y, ll M) { // x * y (mod M)
    // x를 y번 더하기
	ll res = 0;
	while (y > 0) {
		if (y & 1) {
			//res = (res + x) % M; // %가 +보다 우선순위 높아서 괄호.
            res = add_modular(res,x,M);
		}
		//x = (x + x) % M;
        x = add_modular(x,x,M);
		y >>= 1;
	}
	return res;
}

ll power_modular_ (ll x, ll y, ll M) { // x ^ y (mod M)
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = multiply_modular (res, x, M); // res = res * x % M;
		}
		x = multiply_modular (x, x, M);
		y >>= 1;
	}
	return res;
}

ll power_modular(__int128_t x,ll y,__int128_t M){
    ll res = 1;
    while (y > 0){
        if (y & 1){
            res = (__int128_t)res * x % M;
        }
        x =  x * x % M;
        y >>= 1;
    }
    return res;
}

int main(){
   
}





/*
ll add_modular(ll x,ll y,ll M){
    if (x >= M - y || y >= M - x){
        return (x - M) + y;
    }
    else{
        return x + y;
    }
}

 ll x,y,m;
    x = (1UL << 62) + 2;
    y = (1UL << 62) + 2;
    m = 2;
    cout << add_modular(x,y,m); -> -9223372036854775806
*/