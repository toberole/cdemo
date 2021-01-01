#include <string>
#include <iostream>
#include <variant>

void arg_cnt(int cnt, ...)
{
    int value = 0;
    int i = 0;
    int arg_cnt = cnt;
    va_list arg_ptr;
    va_start(arg_ptr, cnt);
    for (i = 0; i < cnt; i++)
    {
        value = va_arg(arg_ptr, int);
        printf("value%d=%d\n", i + 1, value);
    }
    va_end(arg_ptr);
}

void demo2_test_test1()
{
    //define
    std::variant<int, double, std::wstring> var1{1.0};
    std::variant<int, double, std::wstring> var2{L"2"};
    std::variant<int, std::wstring> var3{3};

    std::cout<<"var1.index: "<<var1.index()<<std::endl;
    std::cout<<"var2.index: "<<var2.index()<<std::endl;

    //assign
    var2 = L"abc";
    var1 = L"str1";
    var2.emplace<int>(1);
    std::wcout << L"the var1 = " << std::get<std::wstring>(var1) << std::endl;
    std::wcout << L"the var2 = " << std::get<0>(var2) << std::endl;

    //swap
    std::swap(var1, var2);

    //determine the type of variant
    if (var2.index() == 2)
    {
        //it's wstring type
        std::wcout << L"var2 is wstring type" << std::endl;
    }
    var1 = 100;
    if (std::holds_alternative<int>(var1))
    {
        std::wcout << L"var1 is " << typeid(int).name() << std::endl;
    }

    //get type by index of variant
    std::variant_alternative<2, decltype(var1)>::type val{L"123"};

    // get value
    var1 = 1;
    std::wcout << L"var1 = " << std::get<int>(var1) << std::endl;

    var2 = L"2";
    std::wcout << L"var2 = " << std::get<2>(var2) << std::endl;

    if (auto pV = std::get_if<int>(&var3))
    {
        std::wcout << L"var3 = " << *pV << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::string s = "";
    std::cout << s.size() << std::endl;

    // const char *strpath = "hello";

    // arg_cnt(3,1,2,3);

    demo2_test_test1();

    return 0;
}
