#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n;
unordered_map<string, int> mapping;
vector<int> graph[10005];
bool used[10005];
int index = 1;
int seen[10005];
int parent[100005];

int main(){
    scanf("%d", &n);
    for(int i = 0; i <= 100005; i++){
        parent[i] = i;
    }

    char tempFather[5], tempSon[5];
    for(int i = 0; i < n; i++){
        scanf("%s%s", &tempFather[0], &tempSon[0]);
        string father = tempFather;
        string son = tempSon;

        if(!mapping[father]){
            mapping[father] = index++;
        }
        if(!mapping[son]){
            mapping[son] = index++;
        }

        graph[mapping[father]].push_back(mapping[son]);

        if(parent[mapping[son]] != mapping[father]){
            seen[mapping[son]]++;
            parent[mapping[son]] = mapping[father];
        }

        if(seen[mapping[son]] > 1){
            cout << son;
            return 0;
        }
    }

    

}