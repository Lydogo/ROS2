#include "iostream"
using namespace std;
#include <memory>

int main()
{
    auto p1 = std::make_shared<std::string>("This is a string");
    
    cout<<"p1的引用计数："<<p1.use_count()<<"，指向内存地址"<<p1.get()<<endl;

    auto p2 = p1;
    cout<<"p1的引用计数："<<p1.use_count()<<"，指向内存地址"<<p1.get()<<endl;
    cout<<"p2的引用计数："<<p2.use_count()<<"，指向内存地址"<<p2.get()<<endl;

    p1.reset();//释放引用，不指向内存
    cout<<"p1的引用计数："<<p1.use_count()<<"，指向内存地址"<<p1.get()<<endl;
    cout<<"p2的引用计数："<<p2.use_count()<<"，指向内存地址"<<p2.get()<<endl;

    cout<<"p2的指向内存数据："<<p2->c_str()<<endl; //调用成员方法

    return 0;
}