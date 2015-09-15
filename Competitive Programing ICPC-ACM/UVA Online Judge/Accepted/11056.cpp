// uva 11056.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

struct pilot{

	string name;
	int min,seg,mil;
};

bool testa(string a,string b){

	
	transform(a.begin(),a.end(),a.begin(),::tolower);
	transform(b.begin(),b.end(),b.begin(),::tolower);

	return a<b;
}

bool verifica(const pilot &a, const pilot &b) {
  if (a.min == b.min) {
    if (a.seg == b.seg) {
      if (a.mil == b.mil)
		  return testa (a.name,b.name);
      else
        return a.mil < b.mil;
    }

    return a.seg < b.seg;
  }

  return a.min < b.min;
}


int main()
{
	int n;
	int tm,ts,tmil;
	char c;
	string name;
	pilot corredor;
	vector <pilot> pilotos;

	while( cin >> n){

		 cin.ignore(100, '\n');
         pilotos.clear();


		 for(int i=0;i<n;i++){
			
			 name = "";
			 while (cin >> c) {
                if (c == ':'){
                    break;
				}
                name += c;
             }

			corredor.name = name;

			cin >> tm >> name;
			corredor.min = tm;
			cin >> ts >> name;
			corredor.seg = ts;
			cin >> tmil >> name;
			corredor.mil = tmil;

			cin.ignore(100, '\n');

			pilotos.push_back(corredor);
		 }

		getline(cin, name);

		sort(pilotos.begin(),pilotos.end(),verifica);
	
		for (int i = 0;i < pilotos.size(); i++) {
           
			if (i % 2 == 0) {
                cout << "Row " << i/2 + 1 << endl;
            }

          cout << pilotos[i].name << endl;
       }

    cout << endl;
  }
	return 0;
}

