#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n,m;
int arr[101][101];
int visited[101][101];
int visit[101][101];
// 너비우선탐색을 통하여 변수 x,y를 받고 mybfs함수를 호출한다.
void mybfs(int x,int y){
  queue<vector<int>> q;
  q.push({x,y});
  visited[1][1]=1;
  while(!q.empty()){
    vector<int> here = q.front();
    int a=here[0], b=here[1];
    visit[a][b]=1;
    if (here[0]==n&&here[1]==m) {
      cout<<visited[n][m];
      break;
    }
    q.pop();
    if(arr[a+1][b]==1&&visit[a+1][b]==0){
      q.push({a+1,b});
      visited[a+1][b]=visited[a][b]+1;
    }
    if(arr[a][b+1]==1&&visit[a][b+1]==0){
      q.push({a,b+1});
      visited[a][b+1]=visited[a][b]+1;
    }
    if(arr[a][b-1]==1&&visit[a][b-1]==0){
      q.push({a,b-1});
      visited[a][b-1]=visited[a][b]+1;
    }
    if(arr[a-1][b]==1&&visit[a-1][b]==0){
      q.push({a-1,b});
      visited[a-1][b]=visited[a][b]+1;
    }
  }


}

int main() {
  cin>> n >> m;
  for (int i=1;i<=n;i++){
    string temp;
    cin >> temp;
    for(int j=0;j<m;j++){
      arr[i][j+1]=temp[j]-'0';
    }
  }
  mybfs(1,1);
  return 0;
}