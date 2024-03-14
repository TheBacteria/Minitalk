#include "stdio.h"

void decimalToBinary(int num) {
    int i = 7;
	int mask;

    while (i >= 0)
	{
    	mask = (1 << i);
        if (num & mask)
           printf("1\n"); 
        else 
           printf("0\n");
		i--;
    }
}

int main() {
   int num = 5;
   decimalToBinary(num);
   return 0;
}
//  00000000
//  00000101