#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<string,int> >a;
    for(int i=0;i<files.size();i++){
        pair<string,int> temp;
        for(int j=0;j<files[i].size();j++){
            if(files[i][j]>='A'&&files[i][j]<='Z'){
                files[i][j]+=32;
            }
        }
        temp.first=files
    }
    return answer;
}