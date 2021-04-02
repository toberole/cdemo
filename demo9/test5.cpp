#include <sstream>
#include <iostream>
#include <regex>
#include <regex>

int url2domain(const std::string &url, std::string &domain, unsigned &port)
{

    int ret = -1;

    //使用迭代器拆分字符串 http://www.cppprog.com/2009/0112/48.html
    std::regex reg_domain_port("/"); //按/符拆分字符串
    std::cregex_token_iterator itrBegin(url.c_str(), url.c_str() + url.size(), reg_domain_port, -1);
    std::cregex_token_iterator itrEnd;
    int i = 0;

    std::string domain_port;
    for (std::cregex_token_iterator itr = itrBegin; itr != itrEnd; ++itr)
    {
        i++;
        if (i == 3)
        {
            domain_port = *itr;
        }
    }

    if (domain_port.size() == 0)
    {
        domain_port = url;
    }

    //考虑带端口的情况
    std::regex reg_port(":");
    std::cregex_token_iterator itrBegin2(domain_port.c_str(), domain_port.c_str() + domain_port.size(), reg_port, -1);
    std::cregex_token_iterator itrEnd2;
    int j = 0;
    for (std::cregex_token_iterator itr = itrBegin2; itr != itrEnd2; ++itr)
    {
        j++;
        if (j == 1)
        {
            domain = *itr;
        }
        if (j == 2)
        {
            port = std::stold(*itr);
            //itoa(port,*itr,5);;
        }
    }

    if (domain.size() == 0)
    {
        domain = domain_port;
    }
    return ret;
}

std::string urls[] = {
    "hrbcyyzy-video.guisen.com.cn",
    "hrbcyyzy-video.guisen.com.cn:80",
    "http:://hrbcyyzy-video.guisen.com.cn",
    "http:://hrbcyyzy-video.guisen.com.cn:80",
    "http:://hrbcyyzy-video.guisen.com.cn/222",
    "http:://hrbcyyzy-video.guisen.com.cn:80/222"};

int main()
{
    int ret = -1;

    std::string domain;
    unsigned int port = 0;

    for (int i = 0; i < 6; i++)
    {
        url2domain(urls[i], domain, port);
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    std::stringstream s;
   

    return 0;
}
