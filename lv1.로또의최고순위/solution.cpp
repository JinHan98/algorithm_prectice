#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int low=7;
    int high=7;
    int temp=0;
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
    for(int i=0;i<6;i++){
        if(lottos[i]==0){
            high--;
        }
        else{
            if(lottos[i]==win_nums[temp])
                low--,high--,temp++;
            else{
                for(int j=temp;j<6;j++){
                    if(lottos[i]==win_nums[j]){
                        low--,high--;
                    }
                    else if(lottos[i]>win_nums[j]){
                        continue;
                    }
                    else{
                        temp=j;
                        break;
                    }
                }
            }
        }
    }
    if(high==7)
        high--;
    if(low==7)
        low--;
    answer.push_back(high);
    answer.push_back(low);
    return answer;
}

int main(){
    vector<int>a;
    vector<int>b;
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    b.push_back(31);
    b.push_back(10);
    b.push_back(45);
    b.push_back(1);
    b.push_back(6);
    b.push_back(19);
    vector<int>c=solution(a,b);
    cout<<c[0]<<" "<<c[1]<<endl;
    return 0;
}