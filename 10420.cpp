/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10420 - "List of Conquests"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

struct type
{
    string name;
    int cnt;
}countries[20001];

int ind;

int compare(type a,type b)
{
    return a.name < b.name;
}

int main(void)
{
    char str[1000],name[1000];
    int n,i;
    string temp;

    cin >> n;
    getchar();

    while(n)
    {
        gets(str);
        int len=strlen(str);

        for(i=0; i<len && str[i]!=' '; i++)
        {
            name[i] = str[i];
        }
        name[i] = '\0';

        temp = name;

        for(i=0; i<ind; i++)
        {
            if(temp == countries[i].name)
            break;
        }

        if(i==ind)
        {
            countries[i].name = temp;
            ind++;
        }
        else
        {
            countries[i].cnt++;
        }

        n--;
    }

    sort(countries,countries+ind,compare);

    for(i=0; i<ind; i++)
    cout << countries[i].name << " " << countries[i].cnt + 1 << endl;

	return 0;
}
