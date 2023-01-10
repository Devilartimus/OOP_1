#ifndef CLASS_H
#define CLASS_H
#include <iostream>

namespace Vec
{
    class vectora
    {
        private:    //для инициализации параметров вектора
            double m_x, m_y, m_z;
            static int m_idVector;
            int m_id;

        public:
            //Конструктор для инициализации 1) нуль-вектора по умолчанию или 2) вектора с пользовательскими значениями
            vectora (double x, double y, double z);
            vectora ();

            //дeструктор
            ~vectora();

            //геттеры координат
            double getX() const;
            double getY() const;
            double getZ() const;

            //сеттеры координат
            const vectora& setX(double x = 0);
            const vectora& setY(double y = 0);
            const vectora& setZ(double z = 0);

            //вычисление модуля вектора
            double module() const;
            //копирование вектора
            const vectora& copyVector(const vectora& fromVec);
            //Перегрузка оператора* для умножения вектора на скаляр
            friend vectora operator*(const vectora& A, const double k);
            //Нормирование вектора
            const vectora& normVec();

            //оператор сложения вектора
            friend vectora operator+(const vectora& A, const vectora& B);
            //оператор вычитания вектора
            friend vectora operator-(const vectora& A, const vectora& B);
            //оператор умножения вектора
            friend vectora operator*(const vectora& A, const vectora& B);

            //скалярное произведение векторов
            friend double scalProd(const vectora& A, const vectora& B);
            //косинус угла м-ду векторами
            friend double cos(const vectora& A, const vectora& B);
            //синус угла м-ду векторами
            friend double sin(const vectora& A, const vectora& B);
            //значение угла м-ду векторами
            friend double angle(const vectora& A, const vectora& B);

            //Вывод в консоль вектора
            friend std::ostream& operator<<(std::ostream& out, const vectora& vec);
            //Ввод данных через консоль в инициализированный вектор
            friend std::istream& operator>>(std::istream& in, vectora& vec);
    };
}


#endif // CLASS_H
