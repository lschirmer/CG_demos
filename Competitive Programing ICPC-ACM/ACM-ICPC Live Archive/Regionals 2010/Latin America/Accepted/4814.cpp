//Problem 4814 ACM-ICPC Live Archive - Jollo
//Leonardo Quatrin Campagnolo
//Solved using Ad Hoc

#include <cstdio>

int calculateValor(int min,int a,int b,int c,int x,int y)
{
 	 if(min == a || min == b || min == c || min == x || min == y)
 	 {
	  		  min = calculateValor(min+1,a,b,c,x,y);
	 }
	 return min;
}

int max(int a,int b)
{
 	 if(a < b)
 	 {
	  		return b;
    }
    return a;
}

int main()
{
    int a;
    int b;
    int c;

	 int x;
	 int y;

    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

	 while(a != 0 && b != 0 && c != 0 && x != 0 && y != 0)
	 {
	  			int min = 1;
	  			bool canwin = true;
	  			if((!(a < x && b < y) && canwin)){
            		 if(a < x || b < y)
	    	         {
						  		min = max(min,c+1);
		  		       }else{
			 		 	 		canwin = false;
						 }
	         }
	  			if((!(b < x && a < y)) && canwin){
						 if(b < x || a < y)
            		 {
						  		min = max(min,c+1);
		  		       }else{
			 		 	 		canwin = false;
						 }
	         }
	  			if((!(b < x && c < y)) && canwin){
            		 if(b < x || c < y)
            		 {
						  		min = max(min,a+1);
		  		       }else{
			 		 	 		canwin = false;
						 }
	         }
	  			if((!(a < x && c < y)) && canwin){
            		 if(a < x || c < y)
            		 {
						  		min = max(min,b+1);
		  		       }else{
			 		 	 		canwin = false;
						 }
	         }
	  			if((!(c < x && b < y)) && canwin){
            		 if(c < x || b < y)
            		 {
						  		min = max(min,a+1);
		  		       }else{
			 		 	 		canwin = false;
						 }
	         }
			   if((!(c < x && a < y)) && canwin){
            		 if(c < x || a < y)
            		 {
						  		min = max(min,b+1);
		  		       }else{
			 		 	 		canwin = false;
						 }
	         }

	         if(canwin){
		      min = calculateValor(min,a,b,c,x,y);
		      if(min >= 1 && min <= 52)
		      {
 		      printf("%d\n",min);
			   }else{
	  			printf("-1\n");
			   }
				}else{
				printf("-1\n");
				}
	 			scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    }
    return 0;
}
