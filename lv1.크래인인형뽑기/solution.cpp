#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    vector<int> temp;
    for(int i=0;i<moves.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[j][moves[i]-1]==0){
                continue;
            }
            else{
                temp.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1]=0;
                if(temp.size()>1){
                    if(temp[temp.size()-1]==temp[temp.size()-2]){
                        temp.pop_back();
                        temp.pop_back();
                        answer=answer+2;
                        break;
                    }
                }
                break;
            }
        }   
    }
    return answer;
}

int main(){
    vector< vector <int> > a(5,vector<int>(5,0));
    vector<int> b;
    a[1][2]++;
    a[1][4]=a[1][4]+3;
    a[2][1]=a[2][1]+2;
    a[2][2]=a[2][2]+5;
    a[2][4]++;
    a[3][0]=a[3][0]+4;
    a[3][1]=a[3][1]+2;
    a[3][2]=a[3][2]+4;
    a[3][3]=a[3][3]+4;
    a[3][4]=a[3][4]+2;
    a[4][0]=a[4][0]+3;
    a[4][1]=a[4][1]+5;
    a[4][2]=a[4][2]+1;
    a[4][3]=a[4][3]+3;
    a[4][4]=a[4][4]+1;
    b.push_back(1);
    b.push_back(5);
    b.push_back(3);
    b.push_back(5);
    b.push_back(1);
    b.push_back(2);
    b.push_back(1);
    b.push_back(4);
    int c=solution(a,b);
    cout<<c<<endl;
    return 0;
}