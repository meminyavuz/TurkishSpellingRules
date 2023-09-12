#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char str[] = "gelen veri burada";
	int init_size = strlen(str);
	char delim[] = " ";
 
	char *ptr = strtok(str, delim);
 
	while(ptr != NULL)
	{
		printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
	}
 
	int i;
	for (i = 0; i < init_size; i++)
	{
		printf("%d ", str[i]); 
	}
	printf("\n");
	return 0;
}
