#include <stdio.h>
#include <stdlib.h>
int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
//Check leap year for given year
void leap(int x)
{
    if(x%4==0 && x%100!=0 || x%400==0){
        days[1]=29;
	}
    else
        days[1]=28;
}
//calDate takes days passed and finds the date for it in that year
int calDate(int *m, int *d,int *y)
{
	int temp=0;
	int x=0;
	//Check leap year
	leap(*y);
	//Find the month it is in
	while(*d>temp){
		temp=days[x]+temp;
		x++;
	}
	//Subtract total days from amount of months from input days passed
	if(temp-*d>0){
		temp=temp-*d;
		//Then subtact the months days from the remainder
		*d=days[x-1]-temp;
	}
	else{
		//If the given days passed are equal to the sum of the months passed just set the date to the last day in the month
		*d=days[x-1];
	}
	*m=x;
}
//calDays calculates total days passed from given date from user
int calDays(int m, int d, int y)
{
	int i;
	int tot=0;
	//Check leap year
	leap(y);
	//Check for user input error
	if (d>days[m-1]){
		printf("\nPlease enter a correct date");
		return 0;
	}
	//adds each month days to total
	for(i=0;i<m-1;i++)
		tot=tot+days[i];
	//Add the given date to the sum of the months
	tot=tot+d;
	return tot;
}

int main()
{
	
	char more='y';
	int mm,dd,yy, choice;
	//Loop for user to do infinite inputs
	while(more=='y' || more =='Y'){
		printf("This program will find days passed or date in the year");
		printf("\n1) Input date (mm/dd/yyyy) to find days passed");
		printf("\n2) Input passed days to find date in the year");
		//Asks user which problem they would like to solve
		printf("\nYour choice (1/2): ");
		scanf("%d",&choice);
		if(choice==1){
			printf("\nPlease input date (mm-dd-yyyy): ");
			scanf("%d-%d-%d",&mm,&dd,&yy);
			printf("\nThere are %d days passed in the year %d",calDays(mm,dd,yy),yy);
		}
		if(choice==2){
			printf("\nInput days: ");
			scanf("%d",&dd);
			printf("\nYear: ");
			scanf("%d",&yy);
			calDate(&mm,&dd,&yy);
			printf("\nThe date is %d-%d-%d",mm,dd,yy);
		}
		//Asks user if they would to calculate something else
		printf("\nWould you like to do more?(Y/N): ");
		scanf("%s",&more);
	}
}
