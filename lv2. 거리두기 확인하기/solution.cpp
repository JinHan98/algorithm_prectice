#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(places[i][j][k]=='p'){
                    if(places[i][j][k+1])
                    ;
                }
            }
        }
    }
    return answer;
}

//다음에