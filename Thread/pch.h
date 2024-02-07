// pch.h: 미리 컴파일된 헤더 파일입니다.
// 아래 나열된 파일은 한 번만 컴파일되었으며, 향후 빌드에 대한 빌드 성능을 향상합니다.
// 코드 컴파일 및 여러 코드 검색 기능을 포함하여 IntelliSense 성능에도 영향을 미칩니다.
// 그러나 여기에 나열된 파일은 빌드 간 업데이트되는 경우 모두 다시 컴파일됩니다.
// 여기에 자주 업데이트할 파일을 추가하지 마세요. 그러면 성능이 저하됩니다.

#ifndef PCH_H
#define PCH_H

// 여기에 미리 컴파일하려는 헤더 추가

#endif //PCH_H
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

#include<thread>
#include <cstdio>
#include <mutex>
#include <future>
#include <chrono>
#include <exception>
#include <semaphore>


//int func1(const string& s) {
//    cout << "fun1 호출 :" << s << endl;
//    return 0;
//}
//
//struct Func {
//    void operator() (string s) { cout << "func2 호출 :" << s << endl; }
//};
//
//class A {
//public:
//    int n;
//    A(int num) : n(num) {};
//    int funcA() { cout << "A : " << n << endl; return n; }
//    void funcB() { cout << "funcB 호출" << endl; }
//};
//void funcC(const A& a, A& b) { b.n = a.n; cout << "레퍼런스 접근 A : " << b.n << endl; }
//
//void sub(int n, int m) {
//    cout << "n-m = " << n - m << endl;
//}

    //function<int(const string&)> f1 = func1;
    //f1("함수를 객체처럼 사용");

    //function<void(string)> f2 = Func();
    //f2("연산자 오버로딩");

    //function<void()> f3 = []() {cout << "람다식 func3 호출"; };
    //f3();
    //cout << endl;
    //// =================================================
    //
    //A ca(3); // A의 객체 a 생성
    //function<int(A&)> fA = &A::funcA;
    //fA(ca);
    //// =================================================

    //vector<int> a(1);
    //vector<int> b(2);
    //vector<int> c(3);
    //vector<int> d(4);

    //vector<vector<int>> container;
    //container.push_back(b);
    //container.push_back(d);
    //container.push_back(a);
    //container.push_back(c);

    //vector<int> size_vec(4);

    ////function<size_t(const vector<int>&)> func_size = &vector<int>::size;

    //transform(container.begin(), container.end(), size_vec.begin(),
    //    mem_fn(&vector<int>::size));
    //for (auto itr = size_vec.begin(); itr != size_vec.end(); ++itr) {
    //    cout << "벡터 크기 :: " << *itr << endl;
    //}
    //// =================================================

    //auto sub_from_3 = bind(sub, placeholders::_2 , placeholders::_1);
    //sub_from_3(4,2); // 2 - 4

    //A refA(5);
    //A refB(7);
    //auto ref_with_A = bind(funcC, (refA), placeholders::_1);
    //ref_with_A(refB);