#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10005];
bool used[10005];
int n;

void dfs(int node){
    used[node] = true;
    for(int i = 0; i < graph[node].size(); i++){
        if(!used[graph[node][i]]){
            dfs(graph[node][i]);
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

    dfs(7);

    printf("%d", used[3]);

}