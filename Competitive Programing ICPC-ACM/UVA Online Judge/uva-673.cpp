#include <stack>
#include <cstdio>

int main ()
{
    int n;
    char c;
    scanf("%d\n", &n);
    for(int i = 0 ; i < n ; i++){
        std::stack<char> s;
        while(scanf("%c", &c) > 0 && c != '\n')
        {
            if(c == ']'){
                if(s.size() > 0 && s.top() == '[')
                {
                    s.pop();
                }else
                {
                    s.push(c);
                }

            }else if(c == ')')
            {
                if(s.size() > 0 && s.top() == '(')
                {
                    s.pop();
                }else
                {
                    s.push(c);
                }
            }else{
                s.push(c);
            }
        }
        if(!s.empty())
        {
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
    return 0;
}
