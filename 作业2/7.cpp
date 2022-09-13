#include <stdio.h>
#include <math.h> 
#include <string.h>
#include <stdlib.h> 

int main()
{
	for(int i = 0; i < k; i++){
        int t = a[n - 1];
        for(int j = n-1; j > 0; j --){
            a[j] = a[j-1];
        }
        a[0] = t;
    }
	return 0;
}
