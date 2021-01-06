#include <iostream>
#include <vector>

using namespace std;

int dstx, dsty;
	long long int ladder;
	long long int corridor;
	long long int stair;
	
	
static vector< vector<long long int> >  classroom_value;
static vector< vector<int> >  classroom;

void searchforvalue(int x_max, int y_max, int stpx, int stpy, int px, int py,int previous){
	int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
	if(stpx >= x_max || stpx < 0)
	return;
	else if(stpy >= y_max  || stpy < 0)
	return;
	else if((classroom)[stpy][stpx] == 0)
	return;
	
	long long int sum = 0;
	long long int cost = 0;
	sum = (classroom_value)[stpy+py][stpx+px];
	//cout << sum << endl;
//cout << stpx << "  " << stpy << endl;
	switch((classroom)[stpy][stpx])
	{
		case 1:
			if(previous == 1)
			cost = corridor;
			if(previous == 2)
			cost = corridor;
			break;
		case 2:
			if(previous == 1)
			cost = corridor;
			else if (previous == 2){
			
			if(py == 1 || py == -1)
			{
			cost = ladder;				
			}
			else
			cost = corridor;
		}
			break;
			
	}
	
		if(stpx == 0 || stpx == x_max-1)
	{
		if(py == 1 || py == -1)
		cost = stair;
	}
	
	sum +=cost;
	if(	(classroom_value)[stpy][stpx] != 0 && sum < (classroom_value)[stpy][stpx])
	(classroom_value)[stpy][stpx] = sum;
	else if ((classroom_value)[stpy][stpx] == 0){
		(classroom_value)[stpy][stpx] = sum;	
	}
	
	if(stpy == dsty && stpx == dstx)
	return;
	
		for(int i = 0 ; i < y_max ; i++)
	{
		for(int j = 0; j< x_max ; j++)
		cout << (classroom_value)[i][j] << " ";
		
			cout << endl ;
	}
			cout << "-----------------------" << endl;
			
	for(int i = 0; i < 4; i++)
	{
		if(py != dy[i] || px != dx[i]){
			if(stpy+dy[i] >= 0 && stpy+dy[i] < y_max && stpx+dx[i] < x_max && stpx+dx[i]>= 0){
				if( (classroom)[stpy+dy[i]][stpx+dx[i]] != 0){

					int k = (classroom)[stpy][stpx];
			
					if(i == 1 || i ==3){
						if((classroom)[stpy+dy[i]][stpx+dx[i]] == 2 && k == 2)
					searchforvalue(x_max, y_max, stpx+dx[i], stpy+dy[i], -dx[i], -dy[i], k);
						else if(stpx == 0 || stpx == x_max-1){
						searchforvalue(x_max, y_max, stpx+dx[i], stpy+dy[i], -dx[i], -dy[i], k);
						}
					}
					
			else{
			searchforvalue(x_max, y_max, stpx+dx[i], stpy+dy[i], -dx[i], -dy[i], k);
			}
		}
}
}
}
	return;
}
int main()
{
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
	int size_x;
	int size_y;

	int x, y;
	cin >> size_y >> size_x;
	size_x = size_x + 2;

classroom.resize(size_y, vector<int>(size_x, 0));

classroom_value.resize(size_y, vector<long long int>(size_x, 0));
	for(int i = 0; i < size_y; i++)
	{
		for(int j = 0; j < size_x; j++)
		{
			cin >> classroom[i][j];
			classroom_value[i][j] = 0;
		}
	}
 
	cin >> y >> x;
	cin >> dsty >> dstx;
	cin >> corridor >> stair >> ladder ;
	y = size_y - y;
	dsty = size_y - dsty;
	
	searchforvalue(size_x, size_y, x, y, 0, 0, 0);
	
	cout << classroom_value[dsty][dstx] << endl;
	/*
	for(int i = 0 ; i < size_y ; i++)
	{
		for(int j = 0; j< size_x ; j++)
		cout << classroom_value[i][j] << " ";
		
		cout << endl;
	}
	*/
	classroom.clear();
	classroom_value.clear();
}
