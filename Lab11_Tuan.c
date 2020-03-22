#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
//Извините,потому что мой Dev-C++ не поддерживает написание русского языка 
struct AEROFLOT                                 //3 объекта в структуре
{
    char kuda[30];                              // Пункт назначения
    int num;                                    // Номер самолета
    char type[15];                              // Tип самолета
};
typedef struct AEROFLOT FLY;

void input(FLY a[],int n);                                  
void output(FLY a[],int n);
int main(int argc, char *argv[]) {
    int i,n;
    FLY fly[n];
    do{                                           //Если число меньше 0, оно будет введено снова
        printf("Enter the number of flights: "); 
	scanf("%d", &n);
    }while(n <= 0);
    fflush(stdin);
    input(fly,n);
    printf("\n-------------Flight information-------------- \n");
    output(fly,n);
    printf("\n");
	
    //Выполнить функцию поиска рейса
    char tmp[15];                                        
    printf("\n+Enter the type of aircraft to search: ");    // Введите тип самолета для поиска
    fflush(stdin);
    gets(tmp);     
 
    printf("\n%-15s %-10s ","Destination","Aircraft number");  ////Экспортируйте соответствующий рейс на экран
    printf("\n");
	int count = 0;
        for (i = 1; i <= n; i++)
	{
            if (strcmp(fly[i].type , tmp) == 0 )                    //Сравните данные в выводе с введенной строкой
	    {
                printf("\n%-15s %-15d \n",fly[i].kuda,fly[i].num);
                count++;
            }
        }
        if (count == 0) 
        {
        printf("\nThere is no such flight !!!");                   //Там нет такого полета      
        }
	return 0;
}
void input(FLY a[],int n)                //Функция полетной информации
{
	int i,j;
	for(i = 1; i <= n; i++)
	{
	printf("\n+Flight number %d \n",i);           //Номер рейса
	printf("\nEnter destination: ");              //Введите пункт назначения
	fflush(stdin); 
	gets(a[i].kuda);
	printf("\nEnter aircraft type: ");            //Введите тип самолета
	fflush(stdin); 
	gets(a[i].type);
	fflush(stdin);
	printf("\nEnter the aircraft number: ");     //Введите номер самолета
        scanf("%d",&a[i].num);
        }
}

void output(FLY a[],int n)                          //Экспорт информации о рейсе
{ 
	int i,j;
	FLY temp;
	for(i = 0 ; i < n ; i++)
        for( j = i+1 ; j <= n ; j++)
            if(strcmp(a[i].kuda ,a[j].kuda)>0)          //Организовать полеты в алфавитном порядке
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

