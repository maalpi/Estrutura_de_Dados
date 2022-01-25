#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	int i = 0,a = 2,b = 13;
	while (a<b)
	{
		if(b/a < 2){
			a=a+1;
		}
		else{
			a = a+2;
		}
		a++;
		i++;
	}
	printf("%d",i);
    return 0;
}

