#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, k, f, m;
char famous[1005][10];
unordered_map<string, int> mapping;
int index = 1;
vector<int> graph[10005];
queue<int> spis;
bool marked[10005];
vector<string> people;

void bfs(){
    while(!spis.empty()){
        int top = spis.front();
        spis.pop();
        cout << "top=" << top << endl;
        for(int i = 0; i < graph[top].size(); i++){
            if(!marked[graph[top][i]]){
                int amountMarked = 0;
                for(int j = 0; j < graph[top].size(); j++){
                    if(marked[j]){
                        amountMarked++;
                    }
                }
                if(amountMarked >= k){
                    marked[graph[top][i]] = true;
                    spis.push(graph[top][i]);
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &k, &f, &m);
    for(int i = 0; i < f; i++){
        scanf("%s", &famous[i][0]);
        string fPerson = famous[i];
        if(!mapping[fPerson]){
            mapping[fPerson] = index++;
            people.push_back(fPerson);

        }
        marked[mapping[fPerson]] = true;
        spis.push(mapping[fPerson]);
    }

    char tempFirst[10], tempSecond[10];
    for(int i = 0; i < m; i++){
        scanf("%s%s", &tempFirst[0], &tempSecond[0]);
        string first = tempFirst;
        string second = tempSecond;

        if(!mapping[first]){
            mapping[first] = index++;
            people.push_back(first);

        }
        if(!mapping[second]){
            mapping[second] = index++;
            people.push_back(second);

        }

        graph[mapping[first]].push_back(mapping[second]);
        graph[mapping[second]].push_back(mapping[first]);
    }

    bfs();
    
    for(int i = 0; i < n; i++){
        if(marked[i]){
            cout << people[i] << " ";
        }
    }
}