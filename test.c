#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
const char* month[]={"January","February","March","April","May","June","July","August","September","October","October","November","December"};
bool leapyear_check(int year_of_users)
{
	return ((year_of_users%4==0)&&(year_of_users%100 !=0)||(year_of_users)%400==0);

}
	
int get_1st_weekdays(int d, int m,int year)
{
    
    static int t[] = { 0, 3, 2, 5, 0, 3,5, 1, 4, 6, 2, 4 };
    year -= m < 3;
    return ( year + year / 4 - year / 100 + year / 400 + t[m - 1] + d) % 7;
}
int main()
{
    int year =2022;
    printf("%s-%d",month[3],year);leapyear_check(2022) ? printf("Leap"):printf("No leap");
    printf("\nSun\tMon\tTues\tWed\tThurs\tFri\tSat\n"); //space between is 4
    
  // leapyear_check(2022) ? printf("Leap"):printf("No leap");
   

   int starting_days= get_1st_weekdays(1,4,year);
   uint8_t i;
   int day;
   for(i=0;i<=starting_days-1;i++)
   {
       printf("\t");
   }
  
   //
   
   
   for(day=1;day<=30;day++)
   {
       printf("%2d",day);
       
       
       if(++i>6)
       {
           
           printf("\n");
           i=0;
       }
   }
   
   
   
 


}
/*
tháng năm
tháng có bao nhiêu ngày? năm nhuận hay không nhuận
1st weekday?
nhập tháng và năm ví dụ tháng 4 năm 2022
+2022 là năm nhuận hay không nhuận.
+phải xác định tháng 4 có mấy ngày
+30 ngày
+ngày đầu tiên thì phải là thứ mấy?
=> kết quả*?
*/