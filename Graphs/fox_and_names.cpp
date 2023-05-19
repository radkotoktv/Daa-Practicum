#include <iostream>
#include <vector>

using namespace std;

int n;
char words[101][101];
vector<char> adjList[256];
bool visited[256];
bool onPath[256];
vector<char> s;

bool topSort(char u){
    if(onPath[u]){
        return true;
    }
    onPath[u] = true;

    for(char v : adjList[u]){
        if(!visited[v] && topSort(v)){
            return true;
        }
    }
    onPath[u] = false;
    visited[u] = true;

    s.push_back(u);

    return false;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", &words[i][0]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int index = 0;
            while(words[i][index] != '\0' && words[i][index] == words[j][index]){
                index++;
            }
            if(words[i][index] != '\0' && words[j][index] == '\0'){
                printf("Impossible\n");
                return 0;
            }
            if(words[i][index] != '\0'){
                adjList[words[i][index]].push_back(words[j][index]);
            }
        }
    }

    for(char c = 'a'; c <= 'z'; c++){
        if(!visited[c] && topSort(c)){
            printf("Impossible");
            return 0;
        }
    }

    for(auto it = s.rbegin(); it != s.rend(); it++){
        printf("%c", *it);
    }

    return 0;
}