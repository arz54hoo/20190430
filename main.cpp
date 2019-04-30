
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
 1. 표준 string class

sdfsdf



int main()
{
    string str1 = "I love ";
    string str2 = "c++ string class. ";
    string str3 = str1+str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1+=str2;
    if (str1 == str3)
        cout <<"동일 문자열입니다."<<endl;
    else
        cout <<"서로 다른 문자열이니다."<< endl;

    string str4;

    cout <<"문자열 입력 : ";
    cin >> str4;
    cout << "입력된 문자열 : "<< str4<<endl;

    return 0;
}

*/


class String{

    char * arr;
    int len;

public:
    //기본 생성자
    String();

    // 매개변수가 있는 생성자
    String(const char * ref);

    //복사 생성자
    String(const String &ref);

    //소멸자
    ~String();

    //대입연산자
    String& operator=(const String & ref);

    //+=연산자
    String& operator+=(const String & ref);

    //==연산자
    bool operator==(const String & ref);

    //+연산자
    String operator+(const String & ref);

    //<< 연산자
    friend ostream& operator <<(ostream&os, const String& ref);

    //>>연산자
    friend istream& operator >>(istream& is, String& ref);

    int getLed()
    {
        return len;
    }

};

String::String():arr(NULL),len(0) {}


String::String(const char *ref) {

    len = strlen(ref)+1;
    arr = new  char[len];
    strcpy(arr, ref);

}

String::String(const String &ref) {


    len = ref.len;
    arr = new  char[len];

    strcpy(arr,ref.arr);


}

String::~String() {

    delete [] arr;
}

String& String::operator=(const String &ref) {

    if (arr != NULL)
        delete []arr;

    len = ref.len;
    arr = new  char[len];

    strcpy(arr,ref.arr);

    return *this;
}

String& String::operator+=(const String &ref) {

    *this = *this + ref;

    return *this;
}

bool String::operator==(const String &ref) {

    if (strcmp(arr, ref.arr) == 0)
        return true;
    return false;
}

String String::operator+(const String &ref) {

    len = len + ref.len-1;

    char * temp = new char[len];
    strcpy(temp,arr);
    strcat(temp, ref.arr);
    String TEMP(temp);
    delete []temp;

    return TEMP;
}

ostream& operator<<(ostream &os, const String &ref) {

    os << ref.arr;

    return  os;
}

istream& operator>>(istream &is, String &ref) {

    char temp[50];
    is >> temp;
    ref = String(temp);

    return is;
}

int main()
{

    String str1 = "I love ";
    String str2 = "c++ string class. ";
    cout<<"strlen(I love ) : "<<strlen("I love ")<<endl;

    String str3 = str1+str2;


    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1+=str2;
    if (str1 == str3)
        cout <<"동일 문자열입니다."<<endl;
    else
        cout <<"서로 다른 문자열이니다."<< endl;

    String str4;

    cout <<"문자열 입력 : ";
    cin >> str4;
    cout << "입력된 문자열 : "<< str4<<endl;



    return 0;
}