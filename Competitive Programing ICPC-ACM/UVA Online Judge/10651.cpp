/*Pebble solitaire: ----o---o-o fazer movimentos do tipo:
oo- -> --o
-oo -> o--
o-o -> o-o (esse fica na mesma)*/
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int min(int a, int b)
{
   return (a < b ? a : b);
}

int recursive (string s)
{
   string t;
   int fin = 0;
   for(int i = 0; i < 12 ; i++)
   {
      if(s[i] == 'o')
         fin++;
   }
   for(int i = 0; i < 12 ; i++)
   {
      if(s[i] == 'o'){
         if(i-1 >= 0 && s[i-1] == 'o')
         {
            if(i-2 >= 0 && s[i-2] == '-')
            {
               t = s;
               t[i] = '-';
               t[i-1] = '-';
               t[i-2] = 'o';
               fin = min(fin, recursive(t));
            }
         }
         if(i+1 < 12 && s[i+1] == 'o')
         {
            if(i+2 < 12 && s[i+2] == '-')
            {
               t = s;
               t[i] = '-';
               t[i+1] = '-';
               t[i+2] = 'o';
               fin = min(fin, recursive(t));
            }
         }
      }
   }
   return fin;
}

int main ()
{
   int testCase;
   scanf ("%d", &testCase);

   while ( testCase-- ) {
      string input;
      cin >> input;
	  printf ("%d\n", recursive (input));
   }
   return 0;
}

