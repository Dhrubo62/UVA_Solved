/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10896 - Known Plaintext Attack
*/

//{ ---------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>
//}

//{ ---------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>
# include <map>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

int dif(char a,char b)
{
    int d=a-b;
    if(d<0) d+=26;
    return d;
}

int main()
{
    //freopen("input.txt","r",stdin);

    char line[100],key[20];
    int i,j,t,len_key,len_word,len_line,shift;
    string key_list,word;
    bool in;

    cin>>t;
    getchar();

    while(t--)
    {
        gets(line);
        len_line=strlen(line);

        gets(key);
        len_key=strlen(key);

        key_list="";

        in=false;
        word="";
        for(j=0; j<=len_line; j++)
        {
            if(line[j]>='a' && line[j]<='z')
            {
                in=true;
                word+=line[j];
            }
            else if(in)
            {
                len_word=word.size();

                if(len_word==len_key)
                {
                    for(i=0; i<len_word; i++)
                    {
                        if(!i) shift=dif(word[i],key[i]);
                        else if(dif(word[i],key[i])!=shift) break;
                    }

                    if(i==len_word) key_list+=shift+'a';
                }

                in=false;
                word="";
            }
        }

        sort(key_list.begin(),key_list.end());
        cout<<key_list<<endl;
    }

    return 0;
}
