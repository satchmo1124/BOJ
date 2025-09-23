#include "../ps_header.h"

int is_prime2(int n) {
	int i, sqrn;
	sqrn = (int)sqrt(n);//#include <math.h> 사용, sqrn 정수형으로 변환
	for (i = 2; i <= sqrn; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}