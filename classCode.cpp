#include "class.h"
#include <iostream>
#include <math.h>

using namespace std;



namespace Vec
{
    int vectora::m_idVector = 1;

    //конструктор
    vectora::vectora(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z}, m_id{m_idVector++}
    { cout<<"Constructor - Vector"<<m_id<<endl; }
    vectora::vectora()
    {   m_x=0;
        m_y=0;
        m_z=0;
        m_id=m_idVector++;
        cout<<"Native Constructor - Vector"<<m_id<<endl;
    }

    //деструктор
    vectora::~vectora()
    { cout<<"Destructor - Vector"<<m_id<<endl; }

    //геттеры
    double vectora::getX() const { return m_x; };
    double vectora::getY() const { return m_y; };
    double vectora::getZ() const { return m_z; };

    //сеттеры
    const vectora& vectora::setX(double x) { m_x = x; return *this; };
    const vectora& vectora::setY(double y) { m_y = y; return *this; };
    const vectora& vectora::setZ(double z) { m_z = z; return *this; };

    //вычисление модуля
    double vectora::module() const { return sqrt(m_x * m_x + m_y * m_y + m_z * m_z); }

    //копирование вектора
    const vectora& vectora::copyVector(const vectora& fromVec)
    {
        m_x = fromVec.m_x;
        m_y = fromVec.m_y;
        m_z = fromVec.m_z;
        return *this;
    }

    //нормирование вектора
    const vectora& vectora::normVec()
    {
        double modVec = module();
        m_x /= modVec;
        m_y /= modVec;
        m_z /= modVec;
        return *this;
    }

    //оператор суммы
    vectora operator+(const vectora& A, const vectora& B) { return vectora(A.m_x+B.m_x, A.m_y+B.m_y, A.m_z+B.m_z); }
    //оператор разности
    vectora operator-(const vectora& A, const vectora& B) { return vectora(A.m_x-B.m_x, A.m_y-B.m_y, A.m_z-B.m_z); }
    //оператор умножения векторов
    vectora operator*(const vectora& A, const vectora& B)
    {
        return vectora(A.m_y*B.m_z - A.m_z*B.m_y,
                       A.m_z*B.m_x - A.m_x*B.m_z,
                       A.m_x*B.m_y - A.m_y*B.m_x);
    }
    //оператор умножения вектора на скаляр
    vectora operator*(const vectora& A, const double k) { return vectora(A.m_x*k, A.m_y*k, A.m_z*k); }

    //вычисления скалярного произведения
    double scalProd(const vectora& A, const vectora& B) { return A.m_x*B.m_x+A.m_y*B.m_y+A.m_z*B.m_z; }
    //вычисление синуса
    double cos(const vectora& A, const vectora& B) { return scalProd(A, B) / (A.module()*B.module()); }
    //вычисление косинуса
    double sin(const vectora& A, const vectora& B) { return (A*B).module() / (A.module()*B.module()); }
    //вычисление угла
    double angle(const vectora& A, const vectora& B) { return atan2((A*B).module(), scalProd(A, B) * 180 / M_PI);}

    //вывод
    ostream& operator<<(ostream& out, const vectora& vec)
    {
        out << "Vector " << vec.m_id << "(" << vec.m_x << ", " << vec.m_y << ", " << vec.m_z << ")";
        return out;
    }
    //ввод
    istream& operator>>(istream& in, vectora& vec)
    {
        cout << "x = ";
        in >> vec.m_x;
        cout << "y = ";
        in >> vec.m_y;
        cout << "z = ";
        in >> vec.m_z;
        cout << endl;
        return in;
    }
}
