#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n, m;
vector<int> graph[200005];
bool used[200005];
map<int, int> myMap;
int key = 1;
int components = 0;

void dfs(int node){
    used[node] = true;
    for(int i = 0; i < graph[node].size(); i++){
        if(!used[graph[node][i]]){
            dfs(graph[node][i]);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);    
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);

        if(!myMap[a]){
            myMap[a] = key++;
        }
        if(!myMap[b]){
            myMap[b] = key++;
        }

        graph[myMap[a]].push_back(myMap[b]);
        graph[myMap[b]].push_back(myMap[a]);
    }

    for(int i = 1; i < key; i++){
        if(!used[i]){
            dfs(i);
            components++;
        }
    }
    //cout << "key=" << key << " components=" << components << endl;

    printf("%d", n - key + components + 1);
}