#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = people.size();
    sort(people.begin(),people.end());
    int max=people.size()-1;
    for(int i=0;i<max;i++){
        if(people[i]+people[max]<=limit){
            answer--;
        }
        else{
            i--;
        }
        max--;
    }
    return answer;
}