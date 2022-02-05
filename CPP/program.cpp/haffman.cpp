#include<bits/stdc++.h>
void InitHfmTree()
{
    char ch;
    FILE *fp = fopen("D:\Codefield\CPP\program.cpp\hfmTreee","w");
    while(scanf("%c",&ch)!=EOF)
    {
        fprintf(fp,&ch);
    }
    fclose(fp);
}
int main ()
{
    InitHfmTree();
    return 0;
}