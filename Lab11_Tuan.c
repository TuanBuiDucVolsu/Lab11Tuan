#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
struct AEROFLOT
{
	char kuda[30];
    int num;
    char type[15];
};
typedef struct AEROFLOT FLY;

void nhap(FLY a[],int n);
void xuat(FLY a[],int n);
int main(int argc, char *argv[]) {
	int i,n;
	FLY fly[n];
	do{
    printf("Enter the number of flights: "); 
	scanf("%d", &n);
    }while(n <= 0);
    fflush(stdin);
    nhap(fly,n);
    printf("\n-------------Flight information-------------- \n");
    xuat(fly,n);
    
    printf("\n");
    char tmp[15];
    printf("\n+Enter the type of aircraft to search: ");
    fflush(stdin);
	gets(tmp);
	printf("\n%-15s %-10s ","Destination","Aircraft number");
	printf("\n");
	int count = 0;
        for (i = 1; i <= n; i++)
		{
            if (strcmp(fly[i].type , tmp) == 0 ) 
			{
                printf("\n%-15s %-15d \n",fly[i].kuda,fly[i].num);
                count++;
            }
        }
        if (count == 0) 
        {
        printf("\nThere is no such flight !!!");
        }
	return 0;
}
void nhap(FLY a[],int n)
{
	int i,j;
	for(i = 1; i <= n; i++)
	{
	printf("\n+Flight number %d \n",i);
	printf("\nEnter destination: "); 
	fflush(stdin); 
	gets(a[i].kuda);
	printf("\nEnter aircraft type: "); 
	fflush(stdin); 
	gets(a[i].type);
	fflush(stdin);
	printf("\nEnter the aircraft number: ");
    scanf("%d",&a[i].num);
    }
}

void xuat(FLY a[],int n){
	int i,j;
	FLY temp;
	for(i = 0 ; i < n ; i++)
        for( j = i+1 ; j <= n ; j++)
            if(strcmp(a[i].kuda ,a[j].kuda)>0)
            {   
			    temp = a[i] ;
                a[i] = a[j] ;
                a[j] = temp;
            }
            
    printf("\n%-15s %-20s %-10s ","Destination","Aircraft number","Type");
    for(i = 1;i <= n;i++)
    {
    	printf("\n%-15s %-20d %-10s ",a[i].kuda,a[i].num,a[i].type);
	}
}

