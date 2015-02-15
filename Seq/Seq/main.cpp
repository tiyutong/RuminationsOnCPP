// Seq.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"  
#include "Seq.h"  
#include "Seq_item.h"  
using namespace std;  

int _tmain(int argc, _TCHAR* argv[])
{
	Seq<int>* sp = new Seq<int>;
	*sp = Seq<int>(3, *sp);
	*sp = Seq<int>(4, *sp);
	*sp = Seq<int>(5, *sp);
	*sp = cons(6, *sp);
	sp->insert(7);

	int a = sp->hd();



	    Seq<int> s1,s2;  
    //第一个序列s1  
    for(int i = 0; i != 10;++i)  
        s1.insert(10-i);  
    Seq<int> b1 = s1;  
    int length1 = length(b1);  
    for(int i = 0; i != length1;++i)    {  
        cout << *b1++ << "  ";  
    }  
    cout << endl;  
  
    //第二个序列s2  
    for(int i = 0; i != 10;++i)  
        s2.insert(20-i);  
    Seq<int> b2 = s2;  
    int length2 = length(b2);  
    for(int i = 0; i != length2;++i)    {  
        cout << *b2++ << "  ";  
    }  
    cout << endl;  
      
    //第三个序列s3（由s1、s2连接得来）  
    Seq<int> s3 = s1 + s2;            //连接s1、s2  
    Seq<int> b3 = s3;  
    int length3 = length(b3);  
    for(int i = 0; i != length3;++i)    {  
        cout << *b3++ << "  ";  
    }  
    cout << endl;  

	cout << "length(s3) = " << s3.length() <<endl;
	return 0;
}

