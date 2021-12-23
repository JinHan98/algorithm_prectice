#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<string> small_let(files.size());
    vector<int> num;
    int start=0;
    int end=0;
    for(int i=0;i<files.size();i++){
        for(int j=0;j<files[i].size();j++){
            if(files[i][j]>64&&files[i][j]<91){
                small_let[i].push_back(files[i][j]+32);
                continue;
            }
            small_let[i].push_back(files[i][j]+32);
        }
    }
    sort(files.begin(),files.end());
    return answer;
}