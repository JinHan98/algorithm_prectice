#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=2;i<int(n/2);i++){
        if(n%i==1){
            answer=i;
            return answer;
        }
    }
    answer=n-1;
    return answer;
}