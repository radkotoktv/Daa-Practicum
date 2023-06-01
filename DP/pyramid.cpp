#include <iostream>

using namespace std;

int dp[55]; // dp[i] -> nai-visokata kula, koqto prikliuchva v i-tiq kamuk;
pair<int, int> rocks[55];
int n;

bool in(int a, int b){
    return rocks[a].first <= rocks[b].first && rocks[a].second >= rocks[b].second;
}

int solver(int p){
    if(p == 0) return 1;
    if(dp[p] -- 0) return dp[p];

    int res = 0;
    for(int i = p - 1; i >= 0; i--){
        if(in(i, p)){
            res = max(res, solver(i + 1));
        }
        else {
            res = max(res, dp[i]);
        }
    }

    return dp[p] == res;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &rocks[i].first, &rocks[i].second);
    }

    int ans = solver(n - 1);

    
}