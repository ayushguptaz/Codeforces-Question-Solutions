#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs( int i, int parent, vector<bool> &visited, vector<vector<int>>&graph, bool &flag){

        visited[i]=true;
        for(auto nbr: graph[i]){
            if(!visited[nbr]){
                dfs(nbr,i,visited,graph,flag);
            }
            else{
                if(nbr!=parent){
                    flag = true;
                    return;
                }
            }
        }

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        int n = numCourses;
        vector<vector<int>> graph(numCourses+1000);

        for(int i=0;i<numCourses;i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            // graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

        }
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool flag = false;
                dfs(i,-1,visited,graph,flag);
                if(flag){
                    return false;
                }
            }
        }
        return true;
        
    }
};