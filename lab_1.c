#include <stdio.h>
#include <stdlib.h>

struct date{
  int mm, dd,yy;
};

int main(){
  char name[20],phone[15],line[81];
  float weight;
  int ft,inch;
  struct date{
      int mm;
      int dd;
      int yy;
  }birth;
  char more='y';
  FILE *inF, *outF, *outP;

  outF = fopen ("d:\\data1.out","w");
  if(outF == NULL){
   printf("\n\t\tCan't create file d:\\data1.out");
   exit (1);
  };
  fprintf(outF, "\n\n\n\tName\t\t  B-Date\t  Weight\tHeight\t    Phone");
  while(more == 'y' || more == 'Y'){
   printf("\n\t\tInput your personal information: ");
   printf("\n\t\t\tName: ");
   gets(name);
   printf("\n\t\t\tBirth (mm/dd/yyyy): ");
   scanf("%d/%d/%d/", &birth.mm,&birth.dd,&birth.yy);
   printf("\n\t\t\tWeight : ");
   scanf("%f", &weight);
   printf("\n\t\t\tHeight (0'00\"): ");
   scanf("%d'%d\"", &ft, &inch);
   printf("\n\t\t\tPhone : ");
   fflush(stdin);
   gets(phone);
   fprintf(outF, "\n   %-13s\t%2d/%2d/%4d\t%7.2f lb.\t %d'%2d\"\t %s",
              name, birth.mm, birth.dd, birth.yy, weight, ft, inch, phone);
   printf("\n\t\t\tDo more (Y/N) ? ");
   scanf ("%s%c", &more);
  };
  fprintf (outF, "\n\n\tThis output is made by Trenton W. Kohlhauff\n\n");

  fclose(outF);

  outF = fopen("d:\\data1.out","r");
  while(fgets(line, 80, outF) !=NULL){
     printf("%s", line);
  };

  fclose(outF);

  return 0;

};
