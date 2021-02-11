//clang++-7 -pthread -std=c++17 -o main 파일이름.cpp
//./main
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n;
int temp[100001];

void Input()
{
    for (int i = 0; i < n; i++) cin >> temp[i];
}
 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  Input();
   //기억하자... par 로 pair 를 만들어 priority_queue 를 만들어준다.
  priority_queue <int,vector<int>,greater<int>> minimum_Heap;
  priority_queue<int> maximum_Heap;
  for(int i=0;i<n;i++){
    if(minimum_Heap.size()<maximum_Heap.size()) minimum_Heap.push(temp[i]);
    else maximum_Heap.push(temp[i]);
    //초기 조건 중 하나인 maximum 과 minimum 이 앞자리가 바뀌게 되면 pop을 이용하여 바꾸어준다.
    if(!maximum_Heap.empty()&&!minimum_Heap.empty()){
      if(maximum_Heap.top()>minimum_Heap.top()){
        int temp1=maximum_Heap.top();
        int temp2=minimum_Heap.top();
        maximum_Heap.pop();
        minimum_Heap.pop();
        maximum_Heap.push(temp2);
        minimum_Heap.push(temp1);
      }
    }
    cout << maximum_Heap.top()<<"\n";
  }
}