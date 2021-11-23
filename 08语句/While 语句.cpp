#include<string.h>
#include<stdio.h>
#include <iostream>
using namespace std;
char* trim(char* szSource)
{
	char* pszEos = 0;
	  //strlen 返回字符数量 
	pszEos = szSource + strlen(szSource) - 1;
	cout << "  "<< (pszEos >= szSource)<<"  " << (*pszEos == '-') << endl;

	while ( (pszEos>=szSource) && (*pszEos == '-'))
		*pszEos-- = '\0';

		

	return szSource;
}

int main071()
{
	char szbuf[] = "1234578__";

	printf_s("\nBefore trim: %s  \n", szbuf);

	printf_s("\nAfter trim: %s\n", trim(szbuf));

	return	0;
}


int main12()
{

	int a = 10;

	while (a < 20) {


		a++;
			cout << " a现在是多少" << a << endl;

			if (a == 19) {

				break;
			}

	}

	return 0;
}


