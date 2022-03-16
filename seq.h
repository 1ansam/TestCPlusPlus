//
// Created by yxf on 2022/3/15.
//

#ifndef TESTCPLUSPLUS_SEQ_H
#define TESTCPLUSPLUS_SEQ_H


#include <iostream>

class seq {
    const int MAXSIZE = 100;
    typedef int Elemtype;
    typedef bool Status;
public :
    typedef struct SeqList {
        Elemtype *data;
        int length;
        int maxsize;
    } SeqList;


    SeqList ListInitial(SeqList &L) {
        L.data = new Elemtype[MAXSIZE];
        L.length = 0;
        L.maxsize = MAXSIZE;
    }

    void ListDestory(SeqList &L) {
    }

    void PrintList(SeqList L){
        std::cout<<"顺序表中元素的值为："<<std::endl;
        for (int i = 0; i < L.length; ++i) {
            std::cout<<L.data[i]<< std::endl;
        }
    }

    Status ListInsert(SeqList &L, int position, Elemtype data) {
        //不能插在第0个不存在[-1]下标 或者 不能比最后一个元素的后一个元素所处的位置还大。
        if (position < 1 || position > L.length + 1) {
            return false;
        }

        if (L.length > MAXSIZE) {
            return false; //存储空间满
        }
        int i = L.length;
        for (; i >= position; i--) {
            L.data[i] = L.data[i - 1];
        }
        L.data[i] = data;
        L.length ++;
        return true;

    }

    Status ListDelete(SeqList &L, int position, Elemtype &data){
        if(position < 1 || position > L.length){
            return false;
        }
        data = L.data[position -1];
        for (int i = position; i < L.length ; ++i) {
            L.data[i-1] = L.data[i]; // 下标 = 位序-1
        }
        L.length--;
        return true;
    }
};

#endif //TESTCPLUSPLUS_SEQ_H
