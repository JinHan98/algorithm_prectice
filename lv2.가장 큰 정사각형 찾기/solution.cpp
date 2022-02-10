#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int x=0;
    int y=0;
    int cur=board[x][y];
    while(1){
        int how_many=1;
        int max=board[0].size();
        for(int i=x;i<max;i++){
            for(int j=y+1;j<max;j++){
                if
                if(board[i][j]==cur)
                    how_many++;
                else
                    max=i;
            }
        }
    }
}
int main(){
    vector<vector<int> >k(4);
}