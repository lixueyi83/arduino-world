/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Aug 2017 05:41:49 PM PDT
 ************************************************************************/
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

char buf[100];

int system_cat()
{
    while(1)
    {
        sleep(1);
        system("echo -------------------");
        system("cat < /dev/ttyACM0");
    }

    return 0;
}


int main()
{
    fstream fs;
    cout << "\n--------------------------\n";
    
    string file = "/dev/ttyACM0";
    
    fs.open(file);
    
    if(!fs)
        cout << "open file failed!\n";
    else
        cout << "open sucess!!!";

    cout << "\n--------------------------\n";

    while(1)
    {
    	/*
    	*	read data from uart-device
    	*/
        if(fs.peek() == EOF)
            cout << "nothing to read.\n";
        else 
        {
            system("echo host receive msg: && cat < /dev/ttyACM0");
            //system("cat < /dev/ttyACM0");
            cout << endl;
            
        }
        
        /*
        *	write data to uart-device
        */
        //system("echo host send msg: 'Hello Arduino' && echo 'Hello Arduino' > /dev/ttyACM0");
        system("echo host send char: 'a' && echo 'a' > /dev/ttyACM0");
        cout << endl;
        
        usleep(100000);
    }
}
