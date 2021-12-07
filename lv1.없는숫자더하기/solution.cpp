#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> num;
    for(int i=0;i<10;i++)
        num.push_back(i);
    sort(numbers.begin(),numbers.end());
    for(int i=0;i<numbers.size();i++){
        num.erase(remove(num.begin(),num.end(),numbers[i]));
    }
    for(int i=0;i<num.size();i++)
        answer=answer+num[i];

    return answer;
}