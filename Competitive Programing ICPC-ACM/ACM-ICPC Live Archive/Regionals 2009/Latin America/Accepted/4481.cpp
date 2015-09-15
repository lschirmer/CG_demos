#include <cstdio>
#include <cstdlib>

float notes[255];

int main()
{
	notes['W'] = 1.f;
	notes['H'] = 0.5f;
	notes['Q'] = 0.25f;
	notes['E'] = 1.f/8.f;
	notes['S'] = 1.f/16.f;
	notes['T'] = 1.f/32.f;
	notes['X'] = 1.f/64.f;
	char c;
	scanf("%c", &c);
	while(c != '*')
	{
		int total = 0;
		float compass = 0.f;
		while(scanf("%c", &c) > 0 && c != '\n')
		{
			if( c == '/')
			{
				if(compass == 1.f)
				{
					total++;
				}
				compass = 0.f;
			}	
			else{compass += notes[c];}
		}
		printf("%d\n", total);
		scanf("%c", &c);
	}	
	return 0;
}
