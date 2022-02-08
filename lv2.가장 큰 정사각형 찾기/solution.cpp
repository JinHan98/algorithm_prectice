#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int temp=1;
    int fail=0;
    for(int i=0;i<board.size()-1;i++){
        for(int j=0;j<board[0].size()-1;j++){
            if(board[i][j]==1){
                for(int k=i+1;k<board.size();k++){
                    if(board[k][j]==1)
                        temp++;
                    else
                        break;
                }
                if(!temp>sqrt(answer))
                    continue;
                for(int a=0;a<temp;a++){
                    for(int b=1;b<temp;b++){
                        if(i+a<board.size()&&j+b<board[0].size()){
                            if(board[i+a][j+b]==0)
                                fail=1;
                        }
                        else{
                            fail=1;
                            break;
                        }
                    }
                    if(fail==1)
                        break;
                }
                if(fail==0){
                    if(answer<temp*temp)
                        answer=temp*temp;
                }
                fail=0;
                temp=1;
            }
        }
    }
    return answer;
}
int main(){
    vector<vector<int> >k(4);
}