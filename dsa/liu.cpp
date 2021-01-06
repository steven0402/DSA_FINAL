#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;
int board[500][500],runthrough[500][500],price[500][500];
vector<int> heap[3];
void downheap(){
    int index=1;
    int thesize=heap[0].size();
    while(1){
        if(index*2>=thesize){
            break;
        }
        else if(index*2+1<thesize){
            if(heap[2][index*2]<=heap[2][index*2+1]&&heap[2][index*2]<=heap[2][index]){
                int temp[3];
                temp[0]=heap[0][index];
                temp[1]=heap[1][index];
                temp[2]=heap[2][index];
                heap[0][index]=heap[0][index*2];
                heap[1][index]=heap[1][index*2];
                heap[2][index]=heap[2][index*2];
                heap[0][index*2]=temp[0];
                heap[1][index*2]=temp[1];
                heap[2][index*2]=temp[2];
                index=index*2;
            }
            else if(heap[2][index*2+1]<=heap[2][index*2]&&heap[2][index*2+1]<=heap[2][index]){
                int temp[3];
                temp[0]=heap[0][index];
                temp[1]=heap[1][index];
                temp[2]=heap[2][index];
                heap[0][index]=heap[0][index*2+1];
                heap[1][index]=heap[1][index*2+1];
                heap[2][index]=heap[2][index*2+1];
                heap[0][index*2+1]=temp[0];
                heap[1][index*2+1]=temp[1];
                heap[2][index*2+1]=temp[2];
                index=index*2+1;
            }
            else{
                break;
            }
        }
        else if(index*2<thesize){
            if(heap[2][index*2]<=heap[2][index]){
                int temp[3];
                temp[0]=heap[0][index];
                temp[1]=heap[1][index];
                temp[2]=heap[2][index];
                heap[0][index]=heap[0][index*2];
                heap[1][index]=heap[1][index*2];
                heap[2][index]=heap[2][index*2];
                heap[0][index*2]=temp[0];
                heap[1][index*2]=temp[1];
                heap[2][index*2]=temp[2];
                index=index*2;
            }
            else{
                break;
            }
        }
    }
}
void upheap(){
    int index=heap[0].size()-1;
    while(1){
        if(index/2>0){
            if(heap[2][index]<heap[2][index/2]){
                int temp[3];
                temp[0]=heap[0][index];
                temp[1]=heap[1][index];
                temp[2]=heap[2][index];
                heap[0][index]=heap[0][index/2];
                heap[1][index]=heap[1][index/2];
                heap[2][index]=heap[2][index/2];
                heap[0][index/2]=temp[0];
                heap[1][index/2]=temp[1];
                heap[2][index/2]=temp[2];
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
}
int main()
{
    heap[0].push_back(-1);
    heap[1].push_back(-1);
    heap[2].push_back(-1);
    int N,M;
    int runthroughstatus=0;
    scanf("%d%d",&N,&M);
    for(int i=N;i>=1;i--){
        for(int j=0;j<=M+1;j++){
            scanf("%d",&board[i][j]);
            price[i][j]=1e9;
            if(board[i][j]==0){
                runthrough[i][j]=1;
                runthroughstatus++;
            }
        }
    }
    int x,y,p,q,r,s,t;
    scanf("%d%d%d%d%d%d%d",&x,&y,&p,&q,&r,&s,&t);
    price[x][y]=0;
    heap[0].push_back(x);
    heap[1].push_back(y);
    heap[2].push_back(0);
    while(1){
        if(runthroughstatus==N*(M+2)){
            break;
        }
        else{
            int floor_location,room_location;
            while(1){
                floor_location=heap[0][1];
                room_location=heap[1][1];
                int thesize=heap[0].size();
                if(thesize>1){
                   heap[0][1]=heap[0][thesize-1];
                   heap[1][1]=heap[1][thesize-1];
                   heap[2][1]=heap[2][thesize-1];
                   heap[0].pop_back();
                   heap[1].pop_back();
                   heap[2].pop_back();
                   downheap();
                }
                if(runthrough[floor_location][room_location]==0){
                    runthroughstatus++;
                    runthrough[floor_location][room_location]=1;
                    break;
                }
            }
            if(room_location-1>=0){
                if(price[floor_location][room_location-1]>price[floor_location][room_location]+r){
                    price[floor_location][room_location-1]=price[floor_location][room_location]+r;
                    heap[0].push_back(floor_location);
                    heap[1].push_back(room_location-1);
                    heap[2].push_back(price[floor_location][room_location]+r);
                    upheap();
                }
            }
            if(room_location+1<=M+1){
                if(price[floor_location][room_location+1]>price[floor_location][room_location]+r){
                    price[floor_location][room_location+1]=price[floor_location][room_location]+r;
                    heap[0].push_back(floor_location);
                    heap[1].push_back(room_location+1);
                    heap[2].push_back(price[floor_location][room_location]+r);
                    upheap();
                }
            }
            if(board[floor_location][room_location]==2){
                if(floor_location-1>=1&&board[floor_location-1][room_location]==2){
                    if(price[floor_location-1][room_location]>price[floor_location][room_location]+t){
                        price[floor_location-1][room_location]=price[floor_location][room_location]+t;
                        heap[0].push_back(floor_location-1);
                        heap[1].push_back(room_location);
                        heap[2].push_back(price[floor_location][room_location]+t);
                        upheap();
                    }
                }
                if(floor_location+1<=N&&board[floor_location+1][room_location]==2){
                    if(price[floor_location+1][room_location]>price[floor_location][room_location]+t){
                        price[floor_location+1][room_location]=price[floor_location][room_location]+t;
                        heap[0].push_back(floor_location+1);
                        heap[1].push_back(room_location);
                        heap[2].push_back(price[floor_location][room_location]+t);
                        upheap();
                    }
                }
            }
            if(room_location==0||room_location==M+1){
                if(floor_location-1>=1){
                    if(price[floor_location-1][room_location]>price[floor_location][room_location]+s){
                        price[floor_location-1][room_location]=price[floor_location][room_location]+s;
                        heap[0].push_back(floor_location-1);
                        heap[1].push_back(room_location);
                        heap[2].push_back(price[floor_location][room_location]+s);
                        upheap();
                    }
                }
                if(floor_location+1<=N){
                    if(price[floor_location+1][room_location]>price[floor_location][room_location]+s){
                        price[floor_location+1][room_location]=price[floor_location][room_location]+s;
                        heap[0].push_back(floor_location+1);
                        heap[1].push_back(room_location);
                        heap[2].push_back(price[floor_location][room_location]+s);
                        upheap();
                    }
                }
            }
            if(floor_location==p&&room_location==q){
                break;
            }
        }
    }
    printf("%d",price[p][q]);

    return 0;
}

