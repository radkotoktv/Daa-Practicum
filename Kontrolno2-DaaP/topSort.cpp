#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[5005];
vector<int> topSort;
int inDegrees[5005];

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
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
    vector<int> buff;
    return topSort.size() == numCourses ? topSort : buff;
}

int main(){
    int numCourses = 9;
    vector<vector<int>> prerequisites = {{1,0}, {2,0}, {8,1}, {3,1}, {2,1}, {4,3}, {6,5}, {7,5}};
    vector<int> isGood = findOrder(numCourses, prerequisites);
    
    for(int i = 0; i < isGood.size(); i++){
        std::cout << isGood[i] << " ";
    }
}