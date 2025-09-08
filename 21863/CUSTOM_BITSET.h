#pragma once
typedef unsigned long long int ulld;
#define MAX_BIT_N 65536
#define N 1024
class CUSTOM_BITSET {
private:
	ulld a[N];
	static int cnt;
public:
	CUSTOM_BITSET();
	CUSTOM_BITSET(const CUSTOM_BITSET& z);

	CUSTOM_BITSET& operator =(const CUSTOM_BITSET& z);
	void operator &=(const CUSTOM_BITSET& z);
	void operator |=(const CUSTOM_BITSET& z);
	void operator ^=(const CUSTOM_BITSET& z);
	void operator <<=(const int xx);
	void operator >>=(const int xx);

	void setbit(int i, bool v);
	void setvalue(int i, ulld x);
	bool getbit(int i);

	static int getcnt();
};