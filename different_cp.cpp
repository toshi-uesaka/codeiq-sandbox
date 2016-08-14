//
// https://codeiq.jp/challenge/2936
//
////////////////////////////////////
#include <iostream>

using namespace std;

int cp, n;
int res;
int vec[6], bad[400];

void recur(int m, int badsize){
	if(n == m){
		res += 1;
		return;
	}
	
	for(int a=vec[m]+1; a<=cp; a++){
		int idx = badsize;
		bool flag = true;
		for(int i=0; i<badsize; i++){
			if(bad[i] == a){
				flag = false;
				break;
			}
			bad[idx++] = bad[i] + a;
			bad[idx++] = bad[i] - a;
		}
		if(flag){
			vec[m+1] = a;
			recur(m+1, idx);
		}
	}
}

int main(){
	cin >> cp >> n;
	res = 0;
	vec[0] = 0;
	bad[0] = 0;
	recur(0, 1);
	cout << res << endl;
	return 0;
}
