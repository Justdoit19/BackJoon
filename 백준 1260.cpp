#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int arr[1001][1001];
int n,m,v;
int visited[1001];
void mydfs(int x){
  visited[x]=1;
  cout << x << " ";
  for (int i=1;i<=n;i++){
    if(arr[x][i]==1&&visited[i]==0) mydfs(i);
  }
}

void mybfs(int x){
  queue<int> order;
  order.push(x);
  while(!order.empty()){
    int here=order.front();
    visited[here]=1;
    order.pop();
    cout<<here << " ";
    for(int i=1;i<=n;i++){
      //여기서 arr[x][i] 오류를 범했는데 while 문안에 있으므로 arr[here] 이 되어야 한다.
      if(arr[here][i]==1&&visited[i]==0) {
        order.push(i);
        visited[i]=1;
      }
    }
  }
}

int main() {
  //정점의 갯수, 간선의 개수, 시작점을 받는다.
  cin >> n >> m >> v;
  //간선을 통해 arr 구성
  for(int i=1;i<=m;i++){
    int temp1,temp2;
    cin >> temp1 >> temp2;
    arr[temp1][temp2]=1;
    arr[temp2][temp1]=1;
  }
  mydfs(v);
  cout << endl;
  memset(visited, 0, sizeof(visited));
  mybfs(v);
}