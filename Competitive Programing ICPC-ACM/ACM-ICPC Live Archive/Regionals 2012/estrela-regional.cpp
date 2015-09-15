// estrela.cpp : Defines the entry point for the console application.
//



// usa função totiente de euler

#include <iostream>

using namespace std;


int euler(int p, int k) {
	if (p == 1) {
		return 1;
	}
	int answer = 1;
	for (int i = 0; i < k - 1; i++) {
		answer *= p;
	}
	answer *= (p - 1);
	return answer;
}



int main()
{
	
	int N;
	


	while((cin>>N)>0){
		int resp =1;
		
		for(int i =2;i <= N/i; i++){
			
			int k = 0;

			bool divide = false;
			
			while(N%i == 0){
				divide = true;
				k++;
				N = N/i;
			}

			if(divide){
				resp*=euler(i,k);	
			}
		}
		
		if(N>1){
			resp*=euler(N,1);
		}

		cout << resp/2 << endl;

	}

	return 0;
}

