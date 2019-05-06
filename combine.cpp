#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ofstream out("example1.txt");
    string a[]={"example.txt","example.txt"};
    for(int i=0;i<2;i++){
            ifstream in(a[i].c_str());
            string str;
            while(getline(in,str))
            {
                out<<str;
            }
            out<<"\n";
            in.close();
    }
    out.close();
}
