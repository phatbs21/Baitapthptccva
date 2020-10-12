#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
vector<string> a;

void list_dir(const char *path)
{
    a.clear();
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL)
    {
        return;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        string s;
        s = entry->d_name;
        a.push_back(s);
    }
    closedir(dir);
}

int main()
{

    vector<string> b, b1;
    list_dir(".");
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].find("input") != std::string::npos)
        {
            b.push_back(a[i]);
            //cout << a[i] << "\n";
        }
        else if (a[i].find("output") != std::string::npos)
        {
            b1.push_back(a[i]);
            //cout << a[i] << "\n";
        }
        // list file ban dau
    }

    for (int i = 0; i < b.size(); i++)
    {
        // doi ten thu muc test
        std::string str = b[i];
        char *c = const_cast<char *>(str.c_str());
        std::string s = to_string(i + 1) + ".in";
        cout << s << "\n";
        char const *pchar = s.c_str();
        if (rename(c, pchar) != 0)
        {
            perror("Error renaming file");
            cout << "\n";
        }
    }
    for (int i = 0; i < b1.size(); i++)
    {
        // doi ten thu muc test
        std::string str = b1[i];
        char *c = const_cast<char *>(str.c_str());
        std::string s = to_string(i + 1) + ".out";
        char const *pchar = s.c_str();
        if (rename(c, pchar) != 0)
        {
            perror("Error renaming file");
            cout << "\n";
        }
    }
}