#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> a(N, 0);
	vector<int> dp(N, 0);

	for (int i=0; i<N; i++)
		cin >> a[i];

	dp[0] = a[0];

	for (int i = 1; i < N; i++)
		dp[i] = max(dp[i-1]+a[i], a[i]);

	cout << *max_element(dp.begin(), dp.end()) << "\n";
	return 0;
}

/*

dp[i] : 1 ~ i 까지 고려했을때 최대 구간합

dp[i] = max(dp[i-1] + a[i] , a[i])

만약에 

dp[i-1]이랑 a[i]랑 합하려 하는데 
사실 dp[i-1]는 j ~ i-k까지의 합이고 해당 부분이 i랑 이어져있지 않는다면?

ㄴㄴ 상관없음. 
왜냐하면 뭐가 됐든 dp[i-1] + a[i] , a[i] 둘다 무조건 뒷 인덱스랑 이어짐. (1부터 해보셈)

다만 이 과정에서 dp[i]가 증가하다가 감소할수도 있음.(a[i]가 음수인 경우)
하지만 마지막에 *max_element(v.begin(),v.end())로 전체 중에서 최대값 구할거기 때문에 ㄱㅊ. 
*/