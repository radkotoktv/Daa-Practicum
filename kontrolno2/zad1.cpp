#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
char board[605][605];
bool used[605][605];
int dist;
int rem;
int res;
int result = 0;

int hDir[4] = {0, 1, 0, -1};
int vDir[4] = {1, 0, -1, 0};

bool isValid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m && board[x][y] != '#';
}

void init(){
    dist = 0;
    rem = 1;
    res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            used[i][j] = false;
        }
    }
}

void bfs(int x1, int y1){
    init();
    queue<pair<int, int>> spis;
    spis.push({x1, y1});
    used[x1][y1] = true;
    while(!spis.empty()){
        int x = spis.front().first;
        int y = spis.front().second;
        spis.pop();
        rem--;
        for(int i = 0; i < 4; i++){
            int adjx = x + hDir[i];
            int adjy = y + vDir[i];
            if(isValid(adjx, adjy) && !used[adjx][adjy]){
                if(board[adjx][adjy] == 'f'){
                    res = dist + 1;
                    return;
                }
                used[adjx][adjy] = true;
                spis.push({adjx, adjy});
            }
        }
        if(rem == 0){
            rem = spis.size();
            dist++;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        scanf("%s", &board[i][1]);
    }

    int x, y;
    for(int i = 0; i < k; i++){
        scanf("%d%d", &x, &y);
        board[x][y] = 'f'; // 'f' == food;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] != '#' && board[i][j] != 'f'){
                bfs(i, j);
                result += res;
            }

        }
    }

    printf("%d", result);

}