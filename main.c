#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdint.h>




const char* month[]={"January","February","March","April","May","June","July","August","September","October","October","November","December"};
const char* week[]={"Sun","Mon","Tues","Wed","Thurs","Fri","Sat"};
void display_calender(int year_from_users, int month_from_users);
int get_1st_weekdays(int day, int month, int year);
void gotoxy(int x,int y);
void setup_color(int value_color);
bool leapyear_check(int year_of_users);
void draw(void);

int main()
{
    int month_from_users=2;
    int year_from_user=2022;
   
    char get_key;
    int ascci_value;
    draw();
    display_calender(year_from_user,month_from_users);
    
    setup_color(5);
   while(1)
   {
        gotoxy(20,20);printf("Use UP and DOWN arrow in the your keyboard");
        gotoxy(20,22);printf("Press ESC to exit program");
        
      
        gotoxy(20,24);
        get_key =getch();
        ascci_value = get_key;
        switch (ascci_value)
        {
        case 72: // up arrow in  keyboard
           if(month_from_users ==1)
           {
               
               year_from_user--; 
               month_from_users =12;
           }
           else
           {
               month_from_users--;
           }
           display_calender(year_from_user,month_from_users);
            
            break;
        case 80:// down arrow in keyboard
        if(month_from_users ==12)
        {
            year_from_user++;
            month_from_users=1;
        }
        else
        {
            month_from_users++;

        }
        display_calender(year_from_user,month_from_users);
        break;

        
        default:
            break;
        }
        if(ascci_value ==27)
        {
            break;
        }
          

    
    }
    printf("\n\n\n");
    
    return 0;

}
/*
void check_calender(int year_of_users, int month_of_users)
{
    int days_each_months[]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    
    
    


}
*/
void display_calender(int year_from_users,int month_from_users)
{
    int pos;
    uint8_t i;
    setup_color(4);
    gotoxy(30,6);
    printf("%s-%d",month[month_from_users-1],year_from_users);printf(" ");leapyear_check(year_from_users) ? printf("Leap"):printf("No leap");
    setup_color(1);
    gotoxy(25,7);
  
  for(i=0,pos=30;i<7;i++,pos+=10)
  {
      setup_color(5);
      gotoxy(pos,8);printf("%s",week[i]);
  }
  
   int starting_days= get_1st_weekdays(1,month_from_users,year_from_users);
   
   int day;
   for(i=0,pos=30;i<=starting_days;i++,pos+=10)
   {
       setup_color(15);
       gotoxy(pos,9);
   }
    i =--i;
 
  
 
    uint8_t j=9;
   
   
   for(day=1,pos-10;day<=30,pos<=100;day++,pos+=10)
   {
       
     //  printf("%d",day);
       
       printf("%d",day);
       gotoxy(pos,j);


       
       
       if(++i>6)
       {
           ++j;
           gotoxy(pos-70,j);
           pos =30;
           
          // printf("\n");
           i=0;
           
       }
       if(day==30) break;
       
       
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
bool leapyear_check(int year_from_users)
{
	return ((year_from_users%4==0)&&(year_from_users%100 !=0)||(year_from_users)%400==0);

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
	




	

