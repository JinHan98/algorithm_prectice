#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur_weight=0;
    int move;
    int index;
    vector<int> truck_point(truck_weights.size(),0);
    for(int i=0;i<truck_point.size();i++){
        answer++;
        if(truck_weights[i]+cur_weight>weight){//기다려야하는 경우
            for(int j=0;j<i;j++){
                if(truck_point[j]<bridge_length+1){
                    if(truck_point[j]==bridge_length){//어차피 갈수 있는경우
                        
                    }
                    move=bridge_length-truck_point[j];
                    answer+=move-1;
                    index=j;
                    break;
                }
            }
            for(int j=index;j<i;j++)
                truck_point[j]+=move;
            cur_weight-=truck_weights[i-1];
            i--;
        }
        else{
            for(int j=0;j<i+1;j++)
                truck_point[j]++;
            cur_weight+=truck_weights[i];
        }
    }
    answer+=(bridge_length+1-truck_point[truck_point.size()-1]);
    return answer;
}

int main(){
    vector<int> k;
    k.push_back(7);
    k.push_back(4);
    k.push_back(5);
    k.push_back(6);
    int an=solution(2,10,k);
    cout<<an<<endl;
}
