#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int temp=0;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++){
        if(phone_book[i].size()>phone_book[i+1].size()){
            continue;
        }
        else{
            if(phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size())){
                return false;
            }
        }
    }
    return answer;
}
//["934793", "34", "44", "9347"] false
int main(){
    vector<string> k;
    k.push_back("12");
    k.push_back("13");
    //k.push_back("012");
    //k.push_back("012345");
    bool i=solution(k);
    cout<<i<<endl;
}