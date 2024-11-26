#include <bits/stdc++.h>
using namespace std;


int main(){
    int Q; 
    cin >> Q; 
    map<string,int> mp;
    mp["right"] = 0;
    mp["left"]  = 2;
    mp["up"] = 3;
    mp["down"] = 1;

    vector<vector<int>> cubes(Q+2,vector<int>(4,-1));


   
    for (int i = 0; i < Q; ++i) { 
        int cubeA, cubeB; string direction; cin >> cubeB >> cubeA >> direction;
        int dir = mp[direction];
        if(cubes[cubeA][dir] != -1){
            int b = cubes[cubeA][dir];
            cubes[b][(dir + 2)%4] = -1;
            cubes[cubeA][dir] = -1;
        }
        cubes[cubeA][dir] = cubeB;
        cubes[cubeB][(dir + 2)%4] = cubeA;
         
         }

    
    int count = 0;
    for(int i = 1;i<Q+2;i++){
        for(int j  = 0;j<4;j++){
            if(cubes[i][j] != -1) {
                int curr = cubes[i][j];
                int dir = (j + 1)%4;


                if(cubes[curr][dir] != -1){
                    curr = cubes[curr][dir];
                    dir = (dir + 1)%4;
                    if(cubes[curr][dir] != -1){
                        curr = cubes[curr][dir];
                        dir = (dir + 1)%4; 
                        cubes[curr][dir] = i;
                        cubes[i][(dir+2)%4] = curr;
                    }
                    else{
                        continue;
                    }

                }else{
                    continue;
                }
                

                

                

                
            }
        }
    }

    for(int i = 1;i<Q+2;i++){
        for(int j  = 0;j<4;j++){
            cout<<cubes[i][j]<<" ";
            if(cubes[i][j] != -1) {
                count++;
            }
        }
        cout<<endl;
    }
    



    cout<<count/2;
}