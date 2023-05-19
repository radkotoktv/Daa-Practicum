#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[1005];
int visited[1005];

void dfs(int node){
    visited[node] = 1;
    for(int i = 0; i < graph[node].size(); i++){
        if(!visited[graph[node][i]]){
            dfs(graph[node][i]);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    for(int i = 0; i < rooms.size(); i++){
        for(int j = 0; j < rooms[i].size(); j++){
            graph[i].push_back(rooms[i][j]);
        }
    }

    dfs(0);

    for(int i = 0; i < rooms.size(); i++){
        if(visited[i] == 0) return false;
    }
    return true;
}

int main(){
    
}