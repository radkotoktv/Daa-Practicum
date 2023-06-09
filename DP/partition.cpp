#include <iostream>

using namespace std;

int n;
long long dp[100005];
const long long mod = 1e9 + 7;

int main(){
    scanf("%d", &n);
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    long long sum = 0;
    for(int i = 6; i < n; i++){
        sum += (sum + dp[i - 3]) % mod;
        dp[i] = (sum + 1) % mod;
    }

    printf("%d", dp[n - 1]);
}