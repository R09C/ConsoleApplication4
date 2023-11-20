#ifndef BOOLVECTOR_H
#define BOOLVECTOR_H
#include <iostream>
typedef unsigned char UC;
using namespace std;

class BoolVector
{
public:
    UC* bv;
    int n, m;    	//n -����� ������ �������,
    //m - ���������� ��������� � ������� bv
    //����� n � m: m=n/8 ���� n%8=0;
    //         	       m=n/8+1, ���� n%8!=0
    void setUpM();
    void Input(char* s);		//������������ �������� ������� bv
    void Output(int, int);                   		 //����� �������� ������� bv
    void Input();

    public:

        //������������, ����������, ���������� ��������� ����������
        BoolVector();
        BoolVector(int n1);          			//n1 - ����� ������ �������
        BoolVector(char* s);
        BoolVector(char* s, int n);			//strlen(s)!=n
        BoolVector(const BoolVector&);
        BoolVector operator= (const BoolVector&);
        /*
        ~BoolVector() { delete[]bv; bv = nullptr;
        }
        */

        //����, �����, ���, ����������� k-� ����������
        void Scan();
        void Print();
        int Weight();
        bool operator[] (int);

        //���������
        bool operator== (const BoolVector&);
        bool operator!= (const BoolVector&);
        bool operator< (BoolVector &);   	//x<y ���� x[i]<=y[i]
        bool operator> (BoolVector &);		 //x>y ���� x[i]>=y[i]

        //��������� ��������
        BoolVector operator & (const BoolVector &);		//��������� ����� ������
        BoolVector& operator &=(const BoolVector &);		//���������� *this
        BoolVector operator |(const BoolVector &);			//��������� ����� ������
        BoolVector& operator |=(const BoolVector&);		//���������� *this
        BoolVector operator ^(const BoolVector&);			//��������� ����� ������
        BoolVector& operator ^=(const BoolVector&);		//���������� *this
        BoolVector operator ~();						//���������� *thi
        BoolVector operator <<(const int);					//��������� ����� ������
        BoolVector& operator <<=(const int);				//���������� *this
        BoolVector operator >>(const int);					//��������� ����� ������
        BoolVector& operator >>=(const int);				//���������� *this


        //��������� ����� ���������� �������
        BoolVector SetUp1(int pos);        	//���������� � 1 ���������� pos
        BoolVector SetUp0(int pos);        	//�������� � 0 ���������� pos
        BoolVector Invert(int pos);           	//������������� ���������� pos

        //��������� ���������� ��������� �������
        BoolVector SetUp1(int kol, int pos);
        //���������� kol ��������� ������� � ������� pos, ���������� *this
        BoolVector SetUp0(int kol, int pos);
        //��������  kol ��������� ������� � ������� pos, ���������� *this
        BoolVector Invert(int kol, int pos);
        //������������� kol ��������� ������� � ������� pos, ���������� *this
        BoolVector& Invert();

        friend ostream& operator<< (ostream& r, BoolVector& V);
        friend istream& operator>> (istream& r, BoolVector& V);

};

#endif