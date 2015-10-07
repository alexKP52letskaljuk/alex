#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int h, m, code, price, a;
    cout<<"Vedit kilkist hodun ta xvulun: ";
    cin>>h>>m;
    price=(60*h)+m
    cout<<"Vedite nomer goroda: ";
    cin>>code;
    if(code>=10&&code<=999)


    switch(code){
case 44:
    cout<<"Kyiv";
    cout<<"Price = 0.77 hrn/xv"
    a=price*0.77
    cout<<"Zena zvonka : "<<a;
    break;
case 62:
    cout<<"Donetsk";
    cout<<"Price = 0.8 hrn/xv"
    a=price*0.8
    cout<<"Zena zvonka : "<<a;
    break;
case 32:
    cout<<"Lviv";
    cout<<"Price = 0.95 hrn/xv"
    a=price*0.95
    cout<<"Zena zvonka : "<<a;
    break;
case 692:
    cout<<"Sevastopol";
    cout<<"Price = 1.5 hrn/xv"
    a=price*1.5
    cout<<"Zena zvonka : "<<a;
    break;
case 697:
    cout<<"Simferopol";
    cout<<"Price = 1.5 hrn/xv"
    a=price*1.5
    cout<<"Zena zvonka : "<<a;
    break;

default:
    cout<<"error";
    }
    else
        cout<<"error";
    return 0;

}
