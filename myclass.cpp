#include "myclass.h"
#include <windows.h>

MyClass::MyClass(QString s) : name(s)
{

}

void MyClass::doWork()
{
    for(int i = 0; i <= 100; i++)
    {
        emit send(i);
        Sleep(1000);
    }
}
