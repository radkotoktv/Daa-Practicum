#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> graph[1024];// = {{5, 2, 3, 4}, {1, 6}, {1, 4, 5}, {3, 1, 6}, {1, 8, 10, 3}, {2, 7}, {6, 8}, {7, 5, 9}, {8}, {5}};
int used[1024];
queue<int> spis;
int levels[1024];

void bfs(int start){
    used[start] = 1;
    spis.push(start);
    int level = 1;
    levels[start] = 1;
    int nodesOfLevel = 1; // kolko vurha ima ot tekushtoto nivo;
    while(!spis.empty()){
        int temp = spis.front();
        spis.pop();
        nodesOfLevel--;
        levels[temp] = level;
        for(int i = 0; i < graph[start].size(); i++){
            if(!used[graph[start][i]]){
                spis.push(graph[start][i]);
                used[graph[start][i]] = 1;
            }
        }
    }
    if(nodesOfLevel == 0){
        level++;
        nodesOfLevel = spis.size();
    }
}

int main(){
    scanf("%d%d", &n, &m);
    int from, to;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &from, &to);
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int source = 1;
    bfs(1);
    for(int i = 1; i <= n; i++){
        printf("%d\n", levels[i]);
    }

    
}