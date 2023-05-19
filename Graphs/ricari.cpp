#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int board[2005][2005];
bool used[2005][2005];
queue<pair<int, int>> spis;
int dist = 0;
int rem = 1;
int res = 0;
int counter = 0;

int hDir[8] = {2, 2, 1, -1, -2, -2, 1, -1};
int vDir[8] = {1, -1, 2, 2, 1, -1, -2, -2};

bool isValid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n && board[x][y] >= 0;
}

void bfs(int x1, int y1){
    spis.push({x1, y1});
    used[x1][y1] = true;
    while(!spis.empty()){
        int x = spis.front().first;
        int y = spis.front().second;
        spis.pop();
        rem--;
        for(int i = 0; i < 8; i++){
            int adjx = x + hDir[i];
            int adjy = y + vDir[i];
            if(isValid(adjx, adjy) && !used[adjx][adjy]){
                if(board[adjx][adjy] == 1){
                    res = dist + 1;
                    counter++;
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


int main(){ // -1 = hole; 1 = knight; 
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        board[a][b] = -1;
    }

    for(int i = 0; i < k; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        board[a][b] = 1;
    }

    int a, b;
    scanf("%d%d", &a, &b);
    board[a][b] = -1;

    bfs(a, b);

    printf("%d %d", counter, res);
}