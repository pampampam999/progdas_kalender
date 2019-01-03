#include <stdio.h>
#include <stdlib.h>

void main(){
	int tahun;
	scanf_s("%d", &tahun);

	if (tahun % 100 == 0)
	{
		if ( tahun % 400 == 0)
		{
			printf("Kabisat");
		}
	}
	else if (tahun % 4==0)
	{
		printf("Kabisat");
	}
	
	system("pause");
}