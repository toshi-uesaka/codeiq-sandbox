//
// https://codeiq.jp/challenge/2516
//
////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <map>
#define INF 100000

using namespace std;

int h,w;
int num[64][64];
string field[64];

bool isvalid(int i, int j){
	if(i >= 0 && i < w && j>=0 && j < h && field[j][i] == '.')
		return true;
	return false;
}

int main(){
	cin >> h >> w;
	for(int i=0;i<h;i++){
		cin >> field[i];
		for(int j=0;j<w;j++){
			num[i][j] = INF;
		}
	}
	


	deque<pair<int, int> > deq;
	num[0][0] = 0;
	deq.push_back(pair<int,int>(0,0));
	
	while(!deq.empty()){
		pair<int,int> p = deq.front();
		deq.pop_front();
		int x = p.first;
		int y = p.second;

		int now = num[y][x] + 1;
		//Right
		for(int i = x+1; isvalid(i,y); i++){
			if(num[y][i] > now){
				num[y][i] = now;
				deq.push_back(pair<int,int>(i,y));
			}
		}
		//Left	
		for(int i = x-1; isvalid(i,y); i--){
			if(num[y][i] > now){
				num[y][i] = now;
				deq.push_back(pair<int,int>(i,y));
			}
		}
		//Down
		for(int j = y+1; isvalid(x,j); j++){
			if(num[j][x] > now){
				num[j][x] = now;
				deq.push_back(pair<int,int>(x,j));
			}
		}
		//Up
		for(int j = y-1; isvalid(x,j); j--){
			if(num[j][x] > now){
				num[j][x] = now;
				deq.push_back(pair<int,int>(x,j));
			}
		}
	}
	num[0][0] = 1;
	
	cout << num[h-1][w-1] - 1 << endl;

	for(int j=0;j<h;j++){
		for(int i=0;i<w;i++)
			cout << setw(6) << right <<num[j][i];
		cout << endl;
	}

}
