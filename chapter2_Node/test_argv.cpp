#include <iostream>
using namespace std;

int main(int argc, char **argv) //二维数组
{
    cout<<"参数数量="<<argc<<endl;
    cout<<"程序名字="<<argv[0]<<endl;
    string arg1 = argv[1];
    if(arg1 == "--help")
    {
        cout<<"程序帮助"<<endl;
    }

    return 0;
}