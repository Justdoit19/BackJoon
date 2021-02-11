#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int n;
int arr[26][26];
int visit[26][26];
vector<int> numberOfHouse;
// 너비우선탐색을 통하여 변수 x,y를 받고 mybfs함수를 호출한다.
void mybfs(int x,int y){
  queue<vector<int>> q;
  int ans=0;
  q.push({x,y});
  while(!q.empty()){
    vector<int> here = q.front();
    ans+=1;
    int a=here[0], b=here[1];
    visit[a][b]=1;
    q.pop();
    if(arr[a+1][b]==1&&visit[a+1][b]==0){
      q.push({a+1,b}); // 여기서 추가해준 점은 만약 가는길이 두번 겹친다면 , 계속적으로 queue에 쌓이기 때문에 각 사건마다      
                      //visit처리를 해줌.
      visit[a+1][b]=1;
    }
    if(arr[a][b+1]==1&&visit[a][b+1]==0){
      q.push({a,b+1});
      visit[a][b+1]=1;
    }
    if(arr[a][b-1]==1&&visit[a][b-1]==0){
      q.push({a,b-1});
      visit[a][b-1]=1;
    }
    if(arr[a-1][b]==1&&visit[a-1][b]==0){
      q.push({a-1,b});
      visit[a-1][b]=1;
    }
  }
  numberOfHouse.push_back(ans);
}

int main() {
  cin>> n;
  for (int i=1;i<=n;i++){
    string temp;
    cin >> temp;
    for(int j=0;j<n;j++){
      arr[i][j+1]=temp[j]-'0';
    }
  }
  for (int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(arr[i][j]==1 && visit[i][j]==0) mybfs(i,j);
    }
  }
  sort(numberOfHouse.begin(),numberOfHouse.end());
  cout << numberOfHouse.size() << endl;
  for(int i=0;i<numberOfHouse.size();i++){
    cout << numberOfHouse[i]<<endl;
  }
}