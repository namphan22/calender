#include<stdio.h>
#include<stdint.h>
int main()
{
     int day;
     int i=6;
     
   for(day=1,;day<=30;day++)
   {
       
     //  printf("%d",day);
       
       printf("%d\t",day);


       
       
       if(++i>7)
       {
        //   gotoxy(30,j);
           
           printf("\n");
           i=0;
           ++j;
       }
       
       
   }
}