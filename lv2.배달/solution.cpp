#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//[[1, 2, 4], [1, 3, 1], [3, 4, 1], [4, 2, 1], [2, 5, 1], ]
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> dis(N,500001);
    vector<vector<int> > input(N,vector<int>(N,0));
    vector<bool> check(N,false);
    int now=0;
    
    for(int i=0;i<road.size();i++){
        if(input[road[i][0]-1][road[i][1]-1]==0){
            input[road[i][0]-1][road[i][1]-1]=road[i][2];
            input[road[i][1]-1][road[i][0]-1]=road[i][2];
        }
        else{
            if(input[road[i][0]-1][road[i][1]-1]>road[i][2]){
                input[road[i][0]-1][road[i][1]-1]=road[i][2];
                input[road[i][1]-1][road[i][0]-1]=road[i][2];
            }
        }
    }
    dis[0]=0;
    while(1){
        bool is_re=false;
        for(int i=0;i<input.size();i++){
            if(input[now][i]!=0){
                if(dis[i]>dis[now]+input[now][i]){
                    dis[i]=dis[now]+input[now][i];
                }
            }
        }
        check[now]=true;
        for(int i=0;i<check.size();i++){
            if(check[i]==false){
                is_re=true;
                break;
            }
        }
        int min=500001;
        for(int i=0;i<dis.size();i++){
            if(check[i]==false){
                if(dis[i]<min){
                    now=i;
                    min=dis[i];
                }
            }
        }
        if(is_re==false)
            break;
    }
    for(int i=0;i<dis.size();i++){
        if(dis[i]<=K)
            answer++;
    }
    return answer;
}
//[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]]
int main(){
    vector<vector<int> > a={{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}};
    int b=solution(6,a,4);
    cout<<b;
}