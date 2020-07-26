#include <iostream>

#include <string>

// 判断中文
/*
    汉字的第一字节：是从0xB0   开始编码   
    汉字的第二字节：是从0xA1   开始编码   
*/

using namespace std;

wchar_t* MBCS2Unicode(wchar_t * buff, const char * str){

    wchar_t * wp = buff;

    char * p = (char *)str;

    while (*p)

    {

        if (*p & 0x80)

        {

            *wp = *(wchar_t *)p;

            p++;

        }

        else {

            *wp = (wchar_t)*p;

        }

        wp++;

        p++;

    }

    *wp = 0x0000;

    return buff;
}

char * Unicode2MBCS(char * buff, const wchar_t * str)

{

    wchar_t * wp = (wchar_t *)str;

    char * p = buff, *tmp;

    while (*wp) {

        tmp = (char *)wp;

        if (*wp & 0xFF00) {

            *p = *tmp;

            p++; tmp++;

            *p = *tmp;

            p++;

        }

        else {

            *p = *tmp;

            p++;

        }

        wp++;

    }

    *p = 0x00;

    return buff;
}

wstring str2wstr(string str){

    size_t len = str.size();

    wchar_t * b = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));

    MBCS2Unicode(b, str.c_str());

    wstring r(b);

    free(b);

    return r;

}

int wputs(const wchar_t * wstr);

int wputs(wstring wstr){

    wputs(wstr.c_str());

    return 0;
}


int wputs(const wchar_t * wstr){

    int len = wcslen(wstr);

    char * buff = (char *)malloc((len * 2 + 1) * sizeof(char));

    Unicode2MBCS(buff, wstr);

    printf("%s", buff);

    free(buff);

    return 0;
}

string wstr2str(wstring wstr){

    size_t len = wstr.size();

    char * b = (char *)malloc((2 * len + 1) * sizeof(char));

    Unicode2MBCS(b, wstr.c_str());

    string r(b);

    free(b);

    return r;
}

int main(){
    

    //输入层：接收char*输入，并将其转换为wchar*
    string input = "今天你在武汉！！";

    string temp = "在";

    // 逻辑层在whcar*或wstring的基础上进行字符串操作，
    // 此时操作最小单位为中文字符，不会再有乱码。

    wstring buff = str2wstr(input);

    wstring temp_buff = str2wstr(temp);

    cout << "input的中文个数:"<<wcslen(buff.c_str()) << "   temp的中文个数:" << wcslen(temp_buff.c_str()) << endl;

    cout << "判断input第三个是否是'在':" << (buff[3] == temp_buff[0]) << endl;;



    //输出层将wchar*的结果再次转换为char*，返回给外部

    wputs(buff);



    return 0;

}