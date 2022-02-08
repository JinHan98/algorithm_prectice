#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> val;
    val.push_back(numbers[0]);
    val.push_back(-numbers[0]);
    for(int i=1;i<numbers.size();i++){
        for(int j=0;j<val.size();j+=2){
            val.insert(val.begin()+j+1,val[j]-numbers[i]);
            val[j]=val[j]+numbers[i];
            if(i==numbers.size()-1){
                if(val[j]==target)
                    answer++;
                else if(val[j+1]==target)
                    answer++;
            }
        }
    }
    return answer;
}

int main(){
    vector<int> a;
    int b=3;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    solution(a,b);
}