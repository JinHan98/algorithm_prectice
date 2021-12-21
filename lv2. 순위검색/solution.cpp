#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> lan;
    vector<string> job;
    vector<string> career;
    vector<string> food;
    vector<string> score;
    int switch_=0;
    for(int i=0;i<info.size();i++){
        int pre=0;
        switch_=0;
        for(int j=0;j<info[i].size();j++){
            if(info[i][j]!=' '){
                continue;
            }
            switch (switch_)
            {
            case 0:
                lan.push_back(info[i].substr(pre,j));
            case 1:
                job.push_back(info[i].substr(pre,j));
            case 2:
                career.push_back(info[i].substr(pre,j));
            case 3:
                food.push_back(info[i].substr(pre,j));
            case 4:
                score.push_back(info[i].substr(pre,j));
            default:
                break;
            }
            pre=j+1;
            switch_++;
        }
    }
    for(int i=0;i<query.size();i++){
        string temp;
        
        for(int j=0;j<query[i].size();j++){
            if(query[i][j]!=' ')
                continue;
            
        }

    }

    return answer;
}