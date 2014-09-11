/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12554 - A Special "[H]appy Birthday" Song!!!
*/

// ----------------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>

// ----------------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>
# include <map>

using namespace std;

//------------------ Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

vector <string> list_of_people;
string word[]={"Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you"},str;
int i,p,w,people_count;

int main()
{
    cin>>p;
    for(i=0; i<p; i++)
    {
        cin>>str;
        list_of_people.push_back(str);
    }

    i=0;
    do
    {
        if(i==p) i=0;
        if(w==16) w=0;

        cout<<list_of_people[i++]<<": "<<word[w++]<<endl;
        people_count++;
    } while(!(people_count>=p && w==16));

    return 0;
}
