#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bri_truck;
    int wei_sum=0;
    for(int i=0;i<bridge_length;i++)
        bri_truck.push(0);
    while(!truck_weights.empty()){
        answer++;
        if(bri_truck.front()!=0)
            wei_sum-=bri_truck.front();
        if(wei_sum+truck_weights[0]>weight){//기다려야하는 경우
            bri_truck.push(0);
        }
       else{ //갈 수 있는경우
            bri_truck.push(truck_weights[0]);
            wei_sum+=truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }

        bri_truck.pop();
    }
    answer+=bridge_length;
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
