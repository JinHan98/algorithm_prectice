#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;
    int er=0;
    for(int i=0;i<places.size();i++){
        for(int j=0;j<places[i].size();j++){
            for(int k=0;k<places[i][j].size();k++){
                if(places[i][j][k]=='P'){
                    if(j<4&&k<4){
                        if(places[i][j+1][k+1]=='P'){
                            if(places[i][j][k+1]=='O'||places[i][j+1][k]=='O'){
                                er=1;
                                break;
                            }
                        }
                    }
                    if(j<4){
                        if(places[i][j+1][k]=='P'){
                            er=1;
                            break;
                        }
                    }
                    if(k<4){
                        if(places[i][j][k+1]=='P'){
                            er=1;
                            break;
                        }
                    }
                    if(j<4&&k>0){
                        if(places[i][j+1][k-1]=='P'){
                            if(places[i][j+1][k]=='O'||places[i][j][k-1]=='O'){
                                er=1;
                                break;
                            }
                        }
                    }
                    if(k<3){
                        if(places[i][j][k+2]=='P'){
                            if(places[i][j][k+1]=='O'){
                                er=1;
                                break;
                            }
                        }
                    }
                    if(j<3){
                        if(places[i][j+2][k]=='P'){
                            if(places[i][j+1][k]=='O'){
                                er=1;
                                break;
                            }
                        }
                    }
                }
            }
            if(er==1)
                break;
        }
        if(er==1)
            answer.push_back(0);
        else{
            answer.push_back(1);
        }
        er=0;
    }
    return answer;
}
int main(){
    vector <vector<string> > a(5);
    a[0].push_back("POOOP");
    a[0].push_back("OXXOX");
    a[0].push_back("PPXPX");
    a[0].push_back("OOXOX");
    a[0].push_back("POXXP");
    solution(a);
}