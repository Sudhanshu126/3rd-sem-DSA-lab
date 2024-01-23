#include <iostream>
#include <string>

using namespace std;

bool ReplaceString(string str, string pat, string rep, string &ans)
{
    bool found = false;
    int i,m,c,j,k;
    i=m=c=j=0;
    ans.resize(str.size());
    while(str[c] != '\0')
    {
        if(str[m] == pat[i])
        {
            i++;
            m++;
            if(pat[i] == '\0')
            {
                ans.resize(ans.size() + rep.size() - pat.size());
                found = true;
                for(k=0; rep[k]!='\0'; k++, j++)
                {
                    ans[j] = rep[k];
                }
                i=0;
                c=m;
            }
        }
        else
        {
            ans[j] = str[c];
            j++;
            c++;
            m=c;
            i=0;
        }
    }
    ans[j] = '\0';
    ans.resize(j);
    return found;
}

int main()
{
    string str, pat, rep, ans;

    cout<<"Enter a string: ";
    getline(cin, str);
    cout<<"Enter pattern: ";
    getline(cin, pat);
    cout<<"Enter replacement: ";
    getline(cin, rep);
    
    bool found  = ReplaceString(str, pat, rep, ans);

    if(found)
    {
        cout<<"The replaced string is: "<<ans<<endl;
    }
    else
    {
        cout<<"No matching pattern found."<<endl;
    }

    return 0;
}