//
//  https://codeiq.jp/challenge/2934
//
/////////////////////////
#include <iostream>

using namespace std;

int func(int p){
	p *= 2;
	
	int res = 0;
	for(int a=0; a*(a+1) <= p; a++){
		if(p % (a + 1) == 0){
			int b = p / (a + 1) - a;
			if(b != 0 && b % 2 == 0)
				res++;
		}
	}
	
	return res;
}

int main(){
	int n;
	cin >> n;

	int res = 0;
	for(int p=1; p<=n; p++){
		if(n % p == 0){
			int q = n / p;
			res += func(p) * func(q);
		}
	}

	cout << res << endl;
		
	return 0;
}
