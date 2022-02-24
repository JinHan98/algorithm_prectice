#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int max_index=0;
    for(int i=0;i<k;i++)
    answer=answer<stones[i] ? stones[i] :answer;
    for(int i=0;i<stones.size()-k+1;i++){
        
    }
       
    return answer;
}

int main(){
    vector<int> a={2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    solution(a,3);
}