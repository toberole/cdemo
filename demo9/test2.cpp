#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    const char *buf;
    std::string s = std::string(buf, 0);
    s = std::string(buf, 0);
    std::cout << "s: " << s <<",size: "<<s.size()<< std::endl;
    std::string s1 = std::move(s);
    std::cout << "s1: " << s1 << std::endl;
    
    return 0;
}
