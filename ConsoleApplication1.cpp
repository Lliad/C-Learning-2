// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "head.h"

void pointer();
void refAndPointer();
void constPtrAndRef();
void test();

int addBook(Sales_Data data1, Sales_Data data2);
int addBook2(Sales_Data& data1, Sales_Data& data2);

int main()
{
    /*
    struct Sales_Data{
        std::string bookNo;
        double price = 0.0;
        unsigned int soldNum = 0;
        double reveneu = 0.0;
    };
    */
    Sales_Data data1, data2, data3, data4;

    data1.bookNo = "0-123KA";
    data1.price = 24.0;
    data1.soldNum = 5;
    data1.reveneu = data1.price * data1.soldNum;

    data2.bookNo = "0-123KA";
    data2.price = 24.0;
    data2.soldNum = 4;
    data2.reveneu = data2.price * data2.soldNum;

    data3.bookNo = "0-123ZU";
    data3.price = 19.0;
    data3.soldNum = 5;
    data3.reveneu = data3.price * data3.soldNum;

    data4.bookNo = "0-123KA";
    data4.price = 27.0;
    data4.soldNum = 5;
    data4.reveneu = data4.price * data4.soldNum;

    addBook(data1, data2);
    addBook(data1, data3);
    addBook(data1, data4);

    std::cout << data1.soldNum << " " << data1.reveneu << std::endl;
    std::cout << data2.soldNum << " " << data2.reveneu << std::endl;

    Sales_Data* ptrData1 = &data1;
    Sales_Data* ptrdata2 = &data2;

    addBook2(*ptrData1,*ptrdata2);

    std::cout << data1.soldNum << " " << data1.reveneu << std::endl;
    std::cout << data2.soldNum << " " << data2.reveneu << std::endl;

#if 0
    pointer();
    refAndPointer();
    constPtrAndRef();
    test();
#endif
    return 0;
}

void pointer()
{
    int val1 = 0, val2 = 42;
    int* ptr = nullptr;

    ptr = &val1;//change addr
    std::cout << ptr << " " << *ptr << std::endl;

    *ptr = 42;//change val
    std::cout << ptr << " " << *ptr << std::endl;

    ptr = &val2;//change addr
    std::cout << ptr << " " << *ptr << std::endl;
}

void refAndPointer()
{
    int val1 = 0, val2 = 42;

    int* ptr = nullptr;
    int*& ref = ptr;

    ref = &val1;
    std::cout << ptr << " " << *ptr << std::endl;

    *ref = 42;
    std::cout << ptr << " " << *ptr << std::endl;

    ref = &val2;
    std::cout << ptr << " " << *ptr << std::endl;
}

void constPtrAndRef()
{
    int val1 = 0;
    double val2 = 3.14;

    int* const cptr1 = &val1;
    std::cout << cptr1 << " " << *cptr1 << std::endl;

    ++val1;
    std::cout << cptr1 << " " << *cptr1 << std::endl;

    const int* cptr2 = &val1;
    std::cout << cptr2 << " " << *cptr2 << std::endl;

/*  error
    *cptr2=10;
    std::cout << cptr2 << " " << *cptr2 << std::endl;
*/
    const double& cref = val2;
    std::cout << cref << std::endl;

    ++val2;
    std::cout << cref << std::endl;


}

void test()
{
#if 0
    int i = 0;

    const int ci = i, & cr = ci;

    auto& n = i;
    auto* p = &ci;
    std::cout << n << std::endl;
    std::cout << p << " " << *p << std::endl;
#endif

    int a = 2, b = 4;
    
    decltype(a) c = a;//c=2
    decltype((b)) d = a;
    ++c;
    ++d;

    std::cout << a << std::endl;//3
    std::cout << b << std::endl;//4
    std::cout << c << std::endl;//3
    std::cout << d << std::endl;//3
}

int addBook(Sales_Data data1, Sales_Data data2)
{
    if (data1.bookNo != data2.bookNo)
    {
        std::cout << "Different book." << std::endl;
        return -1;
    }

    if (data1.price != data2.price)
    {
        std::cout << "System error, check database." << std::endl;
        return -1;
    }

    data1.soldNum += data2.soldNum;
    data1.reveneu += data2.reveneu;

    std::cout << "Book: " << data1.bookNo << "  sold " << data1.soldNum
        << ", total price: " << data1.reveneu << std::endl;

    data2.soldNum = 0;
    data2.reveneu = 0;

    return 0;
}

int addBook2(Sales_Data& data1, Sales_Data& data2)
{
    if (data1.bookNo != data2.bookNo)
    {
        std::cout << "Different book." << std::endl;
        return -1;
    }

    if (data1.price != data2.price)
    {
        std::cout << "System error, check database." << std::endl;
        return -1;
    }

    data1.soldNum += data2.soldNum;
    data1.reveneu += data2.reveneu;

    std::cout << "Book: " << data1.bookNo << "  sold " << data1.soldNum
        << ", total price: " << data1.reveneu << std::endl;

    data2.soldNum = 0;
    data2.reveneu = 0;

    return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
