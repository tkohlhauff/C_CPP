#include <stdio.h>
#include <stdlib.h>


int leap(int x)
{
    if(x%4==0 && x%100!=0 || x%400==0){
		printf("\nhere");
        return 1;
	}
    else
        return 0;
}

int getDate(int *m, int *d,int *y)
{
	int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int temp=0;
	int x=0;
	if (leap(*y)){
		days[1]=29;
	}
	while(*d>temp){
		temp=days[x]+temp;
		x++;
	}
	if(temp-*d>0){
		temp=temp-*d;
		*d=days[x]-temp;
		printf("\n%d",*d);
	}
	else{
		*d=days[x];
	}
	*m=x;
}

int calDays(int m, int d, int y)
{
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i;
	int tot=0;

	if (leap(y)){
		days[1]=29;
	}
	if (d>days[m-1]){
		printf("\nPlease enter a correct date");
		return 0;
	}
	for(i=0;i<m-1;i++)
		tot=tot+days[i];
	return tot;
}

int main()
{
	
	char more='y';
	int mm,dd,yy, choice;
	while(more=='y' || more =='Y'){
		printf("This program will find days passed or date in the year");
		printf("\n1) Input date (mm/dd/yyyy) to find days passed");
		printf("\n2) Input passed days to find date in the year");
		printf("\nYour choice (1/2): ");
		scanf("%d",&choice);
		if(choice==1){
			printf("\nPlease input date (mm-dd-yy): ");
			scanf("%d-%d-%d",&mm,&dd,&yy);
			printf("\nThere are %d days passed in the year %d",calDays(mm,dd,yy),yy);
		}
		if(choice==2){
			printf("\nInput days: ");
			scanf("%d",&dd);
			printf("\nYear: ");
			scanf("%d",&yy);
			getDate(&mm,&dd,&yy);
			printf("\nThe date is %d-%d-%d",mm,dd,yy);
		}
		printf("\nWould you like to do more?(Y/N): ");
		scanf("%s",&more);
	}
}
