#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void dfs(int depth,vector<int> temp,int num);
int m,n;
bool pass[11]={0,};
vector<int> vec;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >>n>>m;
  vec.resize(n);
  for (int i=0;i<n;i++){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());
  vector<int> tempans;
  dfs(0,tempans,0);
}

void dfs(int depth,vector<int> temp,int num){
  if(depth==m){
    for(auto aa:temp) cout<<aa<<" ";
    cout<<endl;
  }
  else{
    for(int i=num;i<n;i++){
      if(pass[i]==0){
        pass[i]=1;
        temp.push_back(vec[i]);
        num=i;
        dfs(depth+1,temp,num);
        temp.pop_back();
        pass[i]=0;
      }
    }
  }
}
