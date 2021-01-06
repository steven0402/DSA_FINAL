#include<iostream>
#include<cstdlib>
#include<time.h>
#include<vector>

using namespace std;

#define Max_row 250-3
#define Max_col 250-3

int main(int argc, char const *argv[]) {
  int N, M;
  srand(time(NULL));
  N = (rand() % Max_row) + 3;
  M = (rand() % Max_col) + 3;
  cout<<N<<" "<<M<<endl;

  vector< vector<int> > Building;
  Building.resize(N, vector<int>(M+2, 0));
  for(int i=0; i<N; i++){
    for(int j=0; j<M+2; j++){
      if(Building[i][j]==2){
        if(i<N-1){
          int temp=rand()%2;
          if(temp==1){
            Building[i+1][j]=2;
          }
        }
        continue;
      }
      Building[i][j]=rand()%4;
      if(j==0 || j==M+1){
        if(Building[i][j]==0){
          Building[i][j]=0;
        }
        else{
          Building[i][j]=1;
        }
      }
      else{
        if(Building[i][j]==2){
          if(i==0){
            Building[i+1][j]=2;
          }
          else if(i==N-1){
            Building[i-1][j]=2;
          }
          else{
            int temp=rand()%2;
            if(temp==1){
              Building[i+1][j]=2;
            }
            else{
              Building[i-1][j]=2;
            }
          }
        }
        else if(Building[i][j]!=0){
          Building[i][j]=1;
        }
      }
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<M+2; j++){
      cout<<Building[i][j];
      if(j!=M+1){
        cout<<" ";
      }
    }
    cout<<endl;
  }

  int starting_x=rand()%N +1, starting_y=0;
  while(starting_y==0 || starting_y==M+1){
    starting_y=rand()%M +1;
  }
  cout<<starting_x<<" "<<starting_y<<endl;

  int rescue_x=rand()%N +1, rescue_y=0;
  while(rescue_y==0 || rescue_y==M+1){
    rescue_y=rand()%M +1;
  }
  cout<<rescue_x<<" "<<rescue_y<<endl;
  long long room, stair, ladder;
  room = rand()%10240+1;
  stair = rand()%10240+1;
  ladder = rand()%10240+1;
  cout<<room<<" "<<stair<<" "<<ladder;
  return 0;
}
