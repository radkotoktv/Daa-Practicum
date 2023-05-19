#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[5005];
vector<int> topSort;
int inDegrees[5005];

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    int m = prerequisites.size();
    for (int i = 0; i < m; i++){
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        inDegrees[a]++;
        graph[b].push_back(a);
    }

    for (int i = 0; i < numCourses; i++){
        if (inDegrees[i] == 0){
            topSort.push_back(i);
        }
    }

    for (int boss = 0; boss < topSort.size(); boss++){
        int theBoss = topSort[boss];
        for (int i = 0; i < graph[theBoss].size(); i++){
            inDegrees[graph[theBoss][i]]--;
            if (inDegrees[graph[theBoss][i]] == 0){
                topSort.push_back(graph[theBoss][i]);
            }
        }
    }
    return topSort.size() == numCourses;
}

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}, {0,1}};
    bool isGood = canFinish(numCourses, prerequisites);
    std::cout << std::boolalpha << isGood;
}