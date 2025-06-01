#include "iostream"
using namespace std;
#include <functional> //函数包装头文件

// 自由函数
void save_with_free_fun(const string &file_name)
{
    cout << "调用了自由函数，保存：" << file_name << endl;
}

// 成员函数
class FileSave
{
private:
    /* data */
public:
    FileSave(/* args */)=default;
    ~FileSave()=default;
    void save_with_mumber_fun(const string &file_name)
    {
        cout << "调用了成员函数，保存：" << file_name << endl;
    }
};


int main()
{
    FileSave file_save;

    //lambda函数
    auto save_with_lambda_fun = [](const string &file_name)
    {
        cout << "调用了lambda函数，保存：" << file_name << endl;
    };

    // save_with_free_fun("AAA.txt");
    // file_save.save_with_mumber_fun("BBB.txt");
    // save_with_lambda_fun("CCC.txt");

    function<void(const string&)> save1 = save_with_free_fun;
    function<void(const string&)> save2 = save_with_lambda_fun;
    //成员函数放入函数包装器
    function<void(const string&)> save3 = bind(&FileSave::save_with_mumber_fun,&file_save,placeholders::_1);

    save1("AAA.txt");
    save2("BBB.txt");
    save3("CCC.txt");

    return 0;
}