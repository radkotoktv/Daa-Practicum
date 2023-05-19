#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[10005];
bool used[10005];
queue<int> spis;
int n;

void bfs(int node){
    used[node] = true;
    spis.push(node);
    while(!spis.empty()){
        int top = spis.front();
        spis.pop();
        for(int i = 0; i < graph[top].size(); i++){
            if(!used[graph[top][i]]){
                spis.push(graph[top][i]);
                used[graph[top][i]] = true;
            }
        }
    }
    
}

int main(){
    scanf("%d", &n);

    int start, end;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &start, &end);

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    bfs(3);

    printf("%d", used[8]);

}