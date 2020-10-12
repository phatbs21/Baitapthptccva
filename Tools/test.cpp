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
        if (s != "." && s != ".." && s != "temp")
        {
            a.push_back(s);
        }
    }
    closedir(dir);
}

int main()
{

    vector<string> b;
    list_dir(".");
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].find(".") == std::string::npos)
        {
            b.push_back(a[i]);
        }
        // list file ban dau
    }
    for (int i = 0; i < b.size(); i++)
    {
        // doi ten thu muc test
        std::string str = b[i];
        char *c = const_cast<char *>(str.c_str());
        std::string s = std::to_string(i + 1);
        char const *pchar = s.c_str();
        if (rename(c, pchar) != 0)
        {
            perror("Error renaming file");
            cout << "\n";
        }
        b[i] = to_string(i + 1);
    }
    for (int i = 0; i < b.size(); i++)
    {
        // dem file ra ngoai
        string str = ".\\" + b[i];
        char *c = const_cast<char *>(str.c_str());
        list_dir(c);
        cout << "Folder rename:" << b[i] << "\n";
        for (int j = 0; j < a.size(); j++)
        {
            int n = a[j].length();
            string duoi;
            if (a[j][n - 1] == 'P' || a[j][n - 1] == 'p' && a[j][n - 4] == '.') // .inp
                duoi = ".in";
            else if (a[j][n - 1] == 'T' || a[j][n - 1] == 't' && a[j][n - 4] == '.') //.out
                duoi = ".out";
            else
                duoi = "Other";
            if (duoi != "Other")
            {
                string str2 = str + "\\" + a[j];
                char *q = const_cast<char *>(str2.c_str());
                string str3 = b[i] + duoi;
                char *w = const_cast<char *>(str3.c_str());
                if (rename(q, w) != 0)
                {
                    perror("Error renaming file");
                    cout << "\n";
                }
                else
                    cout << "File changed successfully"
                         << "\n";
            }
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        // doi ten thu muc test
        std::string str = b[i];
        char *c = const_cast<char *>(str.c_str());
        std::string s = std::to_string(i + 1);
        if (i < 9)
            s = "Test0" + s;
        else
            s = "Test" + s;
        char const *pchar = s.c_str();
        if (rename(c, pchar) != 0)
        {
            perror("Error renaming file");
            cout << "\n";
        }
        b[i] = to_string(i + 1);
    }

    /*
    //Xoa folder sau khi chay
    for (int i = 0; i < b.size(); i++)
    {
        string str = "./" + b[i];
        char *c = const_cast<char *>(str.c_str());
        rmdir(c);
    }*/
}