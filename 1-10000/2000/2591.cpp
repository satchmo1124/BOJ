#include <iostream>

using namespace std;


int dp[41]; //dp[i] : i길이의 문자열로 가능한 카드의 배열 


int DP(string S){
	int l = S.length();
	if (dp[l] != -1) {
		return dp[l];
	}

    bool prefix_1 = S[0] != '0';
    bool prefix_2 = ((S[0]-'0') * 10 + S[1]-'0') <= 34;

    /*
    prefix_1 : 1자리 prefix로 쪼갤 수 있는지
    prefix_2 : 2자리 prefix로 쪼갤 수 있는지
    */

    if (!prefix_1){
        dp[l] = 0;
        return dp[l];
    }

	if (prefix_2){
		dp[l] = DP(S.substr(1)) + DP(S.substr(2));
	}
	else{
		dp[l] = DP(S.substr(1));
	}
	return dp[l];
}


int main(){
    string S;
    
    cin >> S;

    for (int i=0;i<41;i++){
        dp[i] = -1;
    }

    int l = S.length();

    if (S[l-1] == '0') dp[1] = 0;
    else dp[1] = 1;

    if (l==1){
        cout << dp[1];
        return 0;
    }

    int prefix_2 = (S[l-2]-'0') * 10 + S[l-1]-'0';
    
    if (S[l-2] == '0') {
        dp[2] = 0;
    }
    else if (prefix_2 <= 34){
        dp[2] = 1 + dp[1];
    }
    else{
        dp[2] = dp[1];
    }

    cout << DP(S);
}