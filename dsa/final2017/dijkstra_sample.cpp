#include<iostream>
#include<vector>

using namespace std;

struct Location{
  int status;
  long long cost;
};

vector< vector<struct Location> > Building;
int N, M;
int room, stair, ladder;
int current_floor, current_room, rendezvous_floor, rendezvous_room;

void route(int x, int y, int banned_direction){
  //banned_direction top=1, bottom=2, left=3, right=4
  long long top=0, bottom=0, left=0, right=0, temp;
  //stair
  if(y==0 || y==M+1){
    if(x!=0){
      if(Building[x-1][y].status!=0 && banned_direction!=1){
        temp=Building[x][y].cost+stair;
        if(temp<Building[x-1][y].cost){
          Building[x-1][y].cost=temp;
          top=temp;
        }
      }
    }
    if(x!=N-1){
      if(Building[x+1][y].status!=0 && banned_direction!=2){
        temp=Building[x][y].cost+stair;
        if(temp<Building[x+1][y].cost){
          Building[x+1][y].cost=temp;
          bottom=temp;
        }
      }
    }
  }
  //ladder
  if(Building[x][y].status==2){
    if(x!=0){
      if(Building[x-1][y].status==2 && banned_direction!=1){
        temp=Building[x][y].cost+ladder;
        if(temp<Building[x-1][y].cost){
          Building[x-1][y].cost=temp;
          top=temp;
        }
      }
    }
    if(x!=N-1){
      if(Building[x+1][y].status==2 && banned_direction!=2){
        temp=Building[x][y].cost+ladder;
        if(temp<Building[x+1][y].cost){
          Building[x+1][y].cost=temp;
          bottom=temp;
        }
      }
    }
  }
  //other
  if(y!=0){
    if(Building[x][y-1].status!=0 && banned_direction!=3){
      temp=Building[x][y].cost+room;
      if(temp<Building[x][y-1].cost){
        Building[x][y-1].cost=temp;
        left=temp;
      }
    }
  }
  if(y!=M+1){
    if(Building[x][y+1].status!=0 && banned_direction!=4){
      temp=Building[x][y].cost+room;
      if(temp<Building[x][y+1].cost){
        Building[x][y+1].cost=temp;
        right=temp;
      }
    }
  }
  if(top!=0){
    route(x-1, y, 2);
  }
  if(bottom!=0){
    route(x+1, y, 1);
  }
  if(left!=0){
    route(x, y-1, 4);
  }
  if(right!=0){
    route(x, y+1, 3);
  }

  return;
}

int main(int argc, char const *argv[]){
  cin>>N>>M;
  Building.resize(N, vector<struct Location>(M+2));
  for(int i=0; i<N; i++){
    for(int j=0; j<M+2; j++){
      cin>>Building[i][j].status;
      Building[i][j].cost=9223372036854775807;
    }
  }
  cin>>current_floor>>current_room;
  current_floor = N-current_floor;
  Building[current_floor][current_room].cost=0;
  cin>>rendezvous_floor>>rendezvous_room;
  rendezvous_floor = N-rendezvous_floor;
  cin>>room>>stair>>ladder;
  route(current_floor, current_room, 0);

  /*for(int i=0; i<N; i++){
    for(int j=0; j<M+2; j++){
      cout<<Building[i][j].cost<<"\t";
    }
    cout<<endl;
  }*/
  cout<<Building[rendezvous_floor][rendezvous_room].cost<<endl;
  return 0;
}
