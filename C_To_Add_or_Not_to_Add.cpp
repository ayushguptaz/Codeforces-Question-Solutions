#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;
class temp{
    int x;
    temp *node;
    float y;
};
int main(){
    temp* head = new temp();
    cout<<sizeof(head)<<" "<<sizeof(temp)<<'\n';

}

int recur(vector<int>& h,int pos,int r_x, int r_y,int n)
{ 
    
       //r_x: remaining time in x r_y: remaining time 
    if(pos>=n) return 0;
    if(dp[pos][abs(r_x-r_y)]!=-1) return dp[pos][abs(r_x-r_y)];
    int v1=0,v2=0,v3=0;
    if(r_x>=h[pos])
    {
        v1=1+recur(h,pos+1,r_x-h[pos],r_y,n);
    }
    if(r_y>=h[pos])
    {
        v2=1+recur(h,pos+1,r_x,r_y-h[pos],n);
    }
    v3=recur(h,pos+1,r_x,r_y,n);
    return dp[pos][abs(r_x-r_y)]=max(v1,max(v2,v3));
}

// int main() 
// {
//     vector<int> h={,11,1,1,1,1,10}; // dp[0][2] = 1 dp[][2]
//     int x=12,y=11;
//     int n=h.size();
//     dp.resize(n,vector<int>(x+y+1,-1));
//     cout<<recur(h,0,x,y,n)<<endl;    
// }