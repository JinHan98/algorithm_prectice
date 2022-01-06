#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    vector<bool> check(prices.size(),false);
    for(int i=1;i<prices.size();i++){
        for(int j=0;j<i;j++){
            if(check[j]==true)
                continue;
            if(prices[i]<prices[j]){//떨어졌을때
                answer[j]=i-j;
                check[j]=true;
            }
        }
    }
    for(int i=0;i<prices.size();i++)
        if(check[i]==false)
            answer[i]=prices.size()-1-i;
    return answer;
}