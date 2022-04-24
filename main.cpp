#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>




const char* month[]={"January","February","March","April","May","June","July","August","September","October","October","November","December"};
void check_calender(int year_of_users, int month_of_users);
void display_calender();
void gotoxy(int x,int y);
void setup_color(int value_color);
bool leapyear_check(int year_of_users);
int main()
{



    gotoxy(50,0);
    setup_color(12);
    printf("Hello Word");
    leapyear_check(1998) ?printf("Leap Year"):printf("Not a leap year");
    // test 
   


}
void check_calender(int year_of_users, int month_of_users)
{
    int days_each_months[]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    
    


}
void display_calender(int year_of_users,int month_of_users,int days_each_months[])
{

    

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
	




	

