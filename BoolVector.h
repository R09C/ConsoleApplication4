#ifndef BOOLVECTOR_H
#define BOOLVECTOR_H
#include <iostream>
typedef unsigned char UC;
using namespace std;

class BoolVector
{
public:
    UC* bv;
    int n, m;    	//n -длина булева вектора,
    //m - количество элементов в массиве bv
    //связь n и m: m=n/8 если n%8=0;
    //         	       m=n/8+1, если n%8!=0
    void setUpM();
    void Input(char* s);		//формирование элемента массива bv
    void Output(int, int);                   		 //вывод элемента массива bv
    void Input();

    public:

        //конструкторы, деструктор, перегрузка оператора присвоения
        BoolVector();
        BoolVector(int n1);          			//n1 - длина булева вектора
        BoolVector(char* s);
        BoolVector(char* s, int n);			//strlen(s)!=n
        BoolVector(const BoolVector&);
        BoolVector operator= (const BoolVector&);
        /*
        ~BoolVector() { delete[]bv; bv = nullptr;
        }
        */

        //ввод, вывод, вес, определение k-й компоненты
        void Scan();
        void Print();
        int Weight();
        bool operator[] (int);

        //сравнение
        bool operator== (const BoolVector&);
        bool operator!= (const BoolVector&);
        bool operator< (BoolVector &);   	//x<y если x[i]<=y[i]
        bool operator> (BoolVector &);		 //x>y если x[i]>=y[i]

        //побитовые операции
        BoolVector operator & (const BoolVector &);		//создается новый вектор
        BoolVector& operator &=(const BoolVector &);		//изменяется *this
        BoolVector operator |(const BoolVector &);			//создается новый вектор
        BoolVector& operator |=(const BoolVector&);		//изменяется *this
        BoolVector operator ^(const BoolVector&);			//создается новый вектор
        BoolVector& operator ^=(const BoolVector&);		//изменяется *this
        BoolVector operator ~();						//изменяется *thi
        BoolVector operator <<(const int);					//создается новый вектор
        BoolVector& operator <<=(const int);				//изменяется *this
        BoolVector operator >>(const int);					//создается новый вектор
        BoolVector& operator >>=(const int);				//изменяется *this


        //Изменение одной компоненты вектора
        BoolVector SetUp1(int pos);        	//установить в 1 компоненту pos
        BoolVector SetUp0(int pos);        	//сбросить в 0 компоненту pos
        BoolVector Invert(int pos);           	//инвертировать компоненту pos

        //Изменение нескольких компонент вектора
        BoolVector SetUp1(int kol, int pos);
        //установить kol компонент начиная с позиции pos, изменяется *this
        BoolVector SetUp0(int kol, int pos);
        //сбросить  kol компонент начиная с позиции pos, изменяется *this
        BoolVector Invert(int kol, int pos);
        //инвертировать kol компонент начиная с позиции pos, изменяется *this
        BoolVector& Invert();

        friend ostream& operator<< (ostream& r, BoolVector& V);
        friend istream& operator>> (istream& r, BoolVector& V);

};

#endif