#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int temp=0;
    if(s<n)
        return {-1};
    while(s<2*n){//연속하는 숫자가 오지 못할때
        answer.push_back(1);
        s--;
        n--;
        temp++;
    }
    for(int i=0;i<n;i++){
        if(i<s%n)
            answer.push_back(s/n+1);
        else{
            answer.insert(answer.begin()+temp,s/n);
        }
    }
    return answer;
}

int main(){
    solution(6,10);
}