#include "../ps_header.h"

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