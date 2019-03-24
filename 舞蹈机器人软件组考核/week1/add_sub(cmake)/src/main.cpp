#include <iostream>
#include "../include/add.h"
#include "../include/sub.h"
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<"a+b="<<add(a,b)<<endl;
	cout<<"a-b="<<sub(a,b)<<endl;
	return 0;
}
