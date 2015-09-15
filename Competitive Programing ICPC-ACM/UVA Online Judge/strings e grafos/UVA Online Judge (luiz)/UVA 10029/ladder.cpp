



//UVA 10029 - edit step ladders
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=970

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> lista;


int busca_binaria(string s,int fim){
	 
	int left = 0;
        int right = fim - 1;
        while (left <= right) {
            int mid = ((left + right) / 2);
			int tmp = s.compare(lista[mid]);
            if (tmp == 0)
                return mid;
            else if (tmp < 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;

}

string chg(string a, char c, int idx) {
        return a.substr(0, idx) + c + a.substr(idx + 1);
}

string del(string a, int idx) {
        return a.substr(0, idx) + a.substr(idx + 1);
}

string add(string a, char c, int idx) {
	return a.substr(0, idx) + c + a.substr(idx);
}

string trans(string a, char c, int idx, int flag){

	 switch (flag) {
        case 0:
            return add(a, c, idx);
        case 1:
            return del(a, idx);
        default:
            return chg(a, c, idx);
     }

}

int main(){
    
string bla;
 int n;

 
 while((cin >> bla )>0){
    lista.push_back(bla);
 }   
 n = (int)lista.size();
  int cost[n+1];
  cost[0] = 1;
  string a;
  string bla2;
  int max = 0;

  for(int i=1;i < n;i++){
	  cost[i] = 1;
	  bla2 = lista[i];
	  int len = bla2.length();
	  for (int flag = 0; flag < 3; flag++) {
                for (int j = 0; j < len; j++) {
                    for (int k = 0; k < 26; k++) {
					  a = trans(bla2,(char)('a' + k),j, flag);
					  if (bla2.compare(a) < 0) {
                            break;
                      }
					  int mid = busca_binaria(a, i);
					  if(mid >=0 && cost[i] < cost[mid]+1){
                             cost[i] = cost[mid]+1;      
                       }
					}
				}
	  }

	  for (int k = 0; k < 26; k++) {
                a = trans(bla2, (char) ('a' + k), len, 0);
				if (bla2.compare(a) < 0) {
                    break;
                }
				int mid = busca_binaria(a, i);
                if (mid >= 0 && cost[i] < cost[mid] + 1){
                    cost[i] = cost[mid] + 1;
				}
	  }
      
	  if (cost[i] > max){
           max = cost[i];
	  }
  }
		
  cout << max << endl;
  return 0;
  }
