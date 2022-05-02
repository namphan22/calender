#include<conio.h>
#include<iostream>
#include<process.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

int main()
{
    char get_key;
    int ascii_value;
    while (1)
    {
        get_key =getch();
        ascii_value = get_key;
        switch (ascii_value)
        {
        case KEY_UP:

            cout << endl << "Up" << endl;
            cout<< ascii_value <<endl;
            break;
        case KEY_DOWN :
            cout << endl << "Down" << endl;
            cout<< ascii_value <<endl;
            break;
        case KEY_LEFT :
            cout << endl << "Left" << endl;
            cout<< ascii_value <<endl;
            break;
        case KEY_RIGHT:
            cout << endl << "Right" << endl;
            cout<< ascii_value <<endl;

       
        default:
            break;
        }
        
        if(ascii_value ==27) 
        {
            cout<<"ESC key pressed"<<endl;
            break;
        }
        
       
    }
    return 0;
    
}