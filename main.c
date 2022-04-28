#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdint.h>




const char* month[]={"January","February","March","April","May","June","July","August","September","October","October","November","December"};
void display_calender(int year_of_users, int month_of_users);
int get_1st_weekdays(int day, int month, int year);
void gotoxy(int x,int y);
void setup_color(int value_color);
bool leapyear_check(int year_of_users);
void draw(void);

int main()
{


    draw();
    display_calender(2022,4);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    setup_color(5);
    
    return 0;

}
/*
void check_calender(int year_of_users, int month_of_users)
{
    int days_each_months[]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    
    
    


}
*/
void display_calender(int year_of_users,int month_of_users)
{
    setup_color(5);
    gotoxy(55,6);
    printf("%s-%d",month[month_of_users-1],year_of_users);leapyear_check(year_of_users) ? printf("Leap"):printf("No leap");
    setup_color(1);
    gotoxy(25,7);
    printf("Sun        Mon        Tues        Wed        Thurs        Fri        Sat\n"); //space between is 4
    
  // leapyear_check(2022) ? printf("Leap"):printf("No leap");
   
   gotoxy(25,8);
   int starting_days= get_1st_weekdays(1,month_of_users,year_of_users);
   uint8_t i;
   int day;
   for(i=0;i<=starting_days-2;i++)
   {
    printf("           ");
   }
  
   //
   
   
   for(day=1;day<=30;day++)
   {
       printf("%8d",day);
       
       
       if(++i>6)
       {
           
           printf("\n");
           i=0;
       }
   }
    
}



void gotoxy(int x,int y)

{
	// x is a column(max =100) , y is row
    COORD coordinates;
    coordinates.X =x;
    coordinates.Y =y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
void setup_color(int value_color)
{
     WORD Color;
                         
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                        
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                   
          Color = (csbi.wAttributes & 0xF0) + (value_color & 0x0F);
          SetConsoleTextAttribute(hStdOut, Color);
     }
    
}
bool leapyear_check(int year_of_users)
{
	return ((year_of_users%4==0)&&(year_of_users%100 !=0)||(year_of_users)%400==0);

}
void draw(void)
{
    setup_color(10);
    uint16_t i;
    for(i=22;i<102;i++)
    {
        gotoxy(i,4);printf("%c",196);
        gotoxy(i,17);printf("%c",196);
    }
    for(i=5;i<17;i++)
    {
    	gotoxy(21,i);printf("%c",179);
    	gotoxy(102,i);printf("%c",179);
    	
    }
    gotoxy(21,4);printf("%c",218);
    gotoxy(102,4);printf("%c",191);
    gotoxy(21,17);printf("%c",192);
    gotoxy(102,17);printf("%c",217);
}
int get_1st_weekdays(int day, int month, int year)
{
     
    static int t[] = { 0, 3, 2, 5, 0, 3,5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;

}
	




	

