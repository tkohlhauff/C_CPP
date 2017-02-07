#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char more = 'y';
	float fah, cel;
	int choice;

	while( more == 'y' || more == 'Y') {
        printf("\n\n\t\tRelationship between Fahrenheit and Celsius\n\n");
        printf("\t\t\t    1 \)    F  - >  C\n");
        printf("\t\t\t    2 \)    C  - >  F\n\n");
        printf("\t\t\tChoice <1/2> ? ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n\t\t\tInput F: ");
            scanf("%f", &fah);

            cel = 5.0/9.0 * (fah - 32.0);

            printf("\n\n\t\t\t%5.2fF = %5.2fC", fah, cel);
        }
        if (choice == 2) {
            printf("\n\t\t\tInput C: ");
            scanf("%f", &cel);

            fah = cel * 9.0/5.0 + 32.0;

            printf("\n\n\t\t\t%5.2fC = %5.2fF", cel, fah);
        }
        if (choice > 2 || choice < 1) {

            printf("\n\t\t\tPlease Enter either 1 OR 2 !!!");
        }
        printf("\n\n\t\t\tDo more (Y/N) ? ");
        scanf ("%s", &more);

	          }
    return 0;
}
