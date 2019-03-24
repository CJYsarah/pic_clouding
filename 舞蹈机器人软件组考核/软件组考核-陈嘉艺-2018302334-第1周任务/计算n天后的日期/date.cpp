#include <iostream>
#include "date.h"
using namespace std;

Date& when(Date& today,int n)
{
    int day=0;
    n+=(today.day-1);
    today.day=1;
    switch(today.month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            day=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            day=30;
        case 2:
            if((today.year%4==0&&today.year%100!=0)||today.year%400==0)
                day=29;
            else
                day=28;
            break;
    }
    if(n-day>=0)//时间跨度超过一个月时
    {
        if(today.month==12)//若为12月            
        {
            today.year+=1;
            today.month=1;
        }    
        else
        {
            today.month+=1;
        }
        return when(today,n-day);//时间跨度减本月日期后进行递归
    }
    else//时间跨度不超过一个月
    {
        today.day+=n;
    }
    return today;
}

int main()
{
    Date today;
    int n;
    cout<<"请输入当前日期（yyyy-mm-dd）："<<endl;
    cin>>today.year>>today.month>>today.day;
    cout<<"请输入时间跨度(n天后）："<<endl;
    cin>>n;
    today=when(today,n);
    cout<<today.year<<"-"<<today.month<<"-"<<today.day<<endl;
    return 0;
}