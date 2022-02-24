#include <string>
#include <vector>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;
    int x_max=x;
    int y_max=y;
    int x_min=x;
    int y_min=y;
    for(int i=0;i<queries.size();i++){
        switch (queries[i][0])
        {
        case 0:
            if(queries[i][1]<=y_min){
                y-=queries[i][1];
                y_min-=queries[i][1];
                y_max-=queries[i][1];
                y_min=y_min > 0 ? y_min : 0;
            }
            else{
                y_min=0;
                y_max+=(queries[i][1]-y_min);
                y_max=y_max < m ? y_max : m-1;
            }
            break;
        case 1:
            if(queries[i][1]+y_max<m){
                y+=queries[i][1];
                y_min+=queries[i][1];
                y_max+=queries[i][1];
                y_max=y_max < m ? y_max : m-1;
            }
            else{
                y_max=m-1;
                y_min-=(queries[i][1]-(m-1-y_max));
                y_min=y_min > 0 ? y_min : 0;
            }
            break;
        case 2:
            if(queries[i][1]<=x_min){
                x-=queries[i][1];
                x_min-=queries[i][1];
                x_max-=queries[i][1];
            }
            else{
                x_min=0;
                x_max+=(queries[i][1]-x_min);
                x_max=x_max < n ? x_max : n-1;
            }
            break;
        default:
            if(queries[i][1]+x_max<n){
                x+=queries[i][1];
                x_min+=queries[i][1];
                x_max+=queries[i][1];
            }
            else{
                x_max=n-1;
                x_min-=(queries[i][1]-(n-1-x));
                x_max=x_max < n ? x_max : n-1;
            }
            break;
        }
    }
    answer=(x_max-x_min+1)*(y_max-y_min+1);
    return answer;
}
int main(){
    vector<vector<int> > a={{3,1},{2,2},{1,1},{2,3},{0,1},{2,1}};
    solution(4,3,0,0,a);

}