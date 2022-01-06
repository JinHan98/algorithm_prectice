#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 다이스트라 알고리즘 다시공부해

//[[1, 2, 4], [1, 3, 1], [3, 4, 1], [4, 2, 1], [2, 5, 1], ]
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int this_num=0; //1 마을은 0
    int min_dis=500001;
    int next_check;
    vector<bool> select(N,false);
    vector<int> dis(N,500001);
    dis[0]=0;
    while(1){
        for(int j=0;j<road.size();j++){
            if(select[road[j][0]-1]==true||select[road[j][1]-1]==true)
                continue;
            else{
                if(this_num+1==road[j][0]){
                    if(dis[road[j][1]-1]>dis[road[j][0]-1]+road[j][2])
                        dis[road[j][1]-1]=dis[road[j][0]-1]+road[j][2];
                    if(dis[road[j][1]-1]<min_dis){//1과의 거리가 가장 가까운것
                        min_dis=dis[road[j][1]-1];
                        next_check=road[j][1]-1;
                    }
                }
                else if(this_num+1==road[j][1]){
                    if(dis[road[j][0]-1]>dis[road[j][1]-1]+road[j][2])
                        dis[road[j][0]-1]=dis[road[j][1]-1]+road[j][2];
                    if(dis[road[j][0]-1]<min_dis){//1과의 거리가 가장 가까운것
                        min_dis=dis[road[j][0]-1];
                        next_check=road[j][0]-1;
                    }
                }
            }
        }
        select[this_num]=true;
        this_num=next_check;
        min_dis=500001;
                
        for(int i=0;i<N;i++){
            if(select[i]==false){
                if(this_num==next_check)
                    this_num=i;
                else
                    break;
            }
            else if(i==N-1&&select[i]==true){
                for(int j=0;j<N;j++){
                    if(dis[j]<=K)
                        answer++;
                }
                return answer;
            }
        }
    }
    return answer;
}
//[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]]
int main(){
    vector<vector<int> > a(6);
    a[0].push_back(1);
    a[0].push_back(2);
    a[0].push_back(1);
    a[1].push_back(2);
    a[1].push_back(3);
    a[1].push_back(3);
    a[2].push_back(5);
    a[2].push_back(2);
    a[2].push_back(2);
    a[3].push_back(1);
    a[3].push_back(4);
    a[3].push_back(2);
    a[4].push_back(5);
    a[4].push_back(3);
    a[4].push_back(1);
    a[5].push_back(5);
    a[5].push_back(4);
    a[5].push_back(2);
    int b=solution(5,a,4);
    cout<<b;
}