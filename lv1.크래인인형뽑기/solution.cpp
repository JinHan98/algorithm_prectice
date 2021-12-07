#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    int all=0;
    vector<int> temp;
    while(moves.size()>0){
        for(int i=0;i<board.size();i++){
            if(board[moves[0]-1][i]==0){
                all++;
                continue;
            }
            else{
                temp.push_back(board[moves[0]-1][i]);
                board[moves[0]-1][i]=0;
                moves.erase(moves.begin());
                break;
            }
        }
        if(all==board.size())
            moves.erase(moves.begin());
        if(temp.size()>1){
            if(temp[temp.size()-1]==temp[temp.size()-2]){
                answer++;
                temp.erase(temp.end()-2,temp.end());
            }
        }
    }
    return answer;
}

int main(){
    vector<vector<int> > a(25);
    vector<int> b;
    a[0].push_back(0);
    a[0].push_back(0);
    a[0].push_back(0);
    a[0].push_back(0);
    a[0].push_back(0);
    a[1].push_back(0);
    a[1].push_back(0);
    a[1].push_back(1);
    a[1].push_back(0);
    a[1].push_back(3);
    a[2].push_back(0);
    a[2].push_back(2);
    a[2].push_back(5);
    a[2].push_back(0);
    a[2].push_back(1);
    a[3].push_back(4);
    a[3].push_back(2);
    a[3].push_back(4);
    a[3].push_back(4);
    a[3].push_back(2);
    a[4].push_back(3);
    a[4].push_back(5);
    a[4].push_back(1);
    a[4].push_back(3);
    a[4].push_back(1);
    b.push_back(1);
    b.push_back(5);
    b.push_back(3);
    b.push_back(5);
    b.push_back(1);
    b.push_back(2);
    b.push_back(1);
    b.push_back(4);
    int c=solution(a,b);
    cout<<c;
    return 0;
}