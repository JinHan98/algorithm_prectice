#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> temp;
    for(int i=0;i<nums.size();i++){
        vector<int>::iterator seek=find(temp.begin(),temp.end(),nums[i]);
        if(seek==temp.end()){
            temp.push_back(nums[i]);
        }
    }
    answer=min(nums.size()/2,temp.size());
    return answer;
}



int main(){
    vector<int> a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    int b=solution(a);
    cout<<b<<endl;

}