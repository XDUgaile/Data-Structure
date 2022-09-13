#include <stdio.h>
#include <math.h> 
#include <string.h>
#include <stdlib.h> 

int main()
{
	int x;
	for(int i = n;i >= 0;i--){
		if(x <= a[i]){
			a[i+1] = a[i];
		}else{
			a[i+1] = x;
		}
	} 
	return 0;
}
