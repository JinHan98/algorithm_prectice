#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> temp;
    answer.push_back(1);
    answer.push_back(0);
    temp.push(prices.back());
    temp.push(prices[prices.size()-2]);
    for(int i=prices.size()-3;i>=0;i--){
        stack<int> k=temp;
        int sec=0;
        while(!k.empty()){
            if(prices[i]>k.top()){//가격이 떨어진 경우
                answer.insert(answer.begin(),sec+1);
                temp.push(prices[i]);
                break;
            }
            else{
                k.pop();
                sec++;
            }
        }
        if(k.empty()){
            answer.insert(answer.begin(),sec);
            temp.push(prices[i]);
        }
    }
    return answer;
}
int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(2);
    a.push_back(3);
    solution(a);
}