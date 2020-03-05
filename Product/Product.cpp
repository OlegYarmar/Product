#include <iostream>
#include <set>

using namespace std;

class Product
{
private:
    int number; //код товара
    int weight; //вес
    int price; //цена
public:
    Product() //конструктор с заданными параметрами
    {
        setn(0);
        setw(100);
        setp(12000);
    }
    Product(Product& p)
    {
        setn(p.getn());
        setw(p.getw());
        setp(p.getp());
    }
    Product(int number, int weight, int price)
    {
        setn(number);
        setw(weight);
        setp(price);
    }
    void print() //метод вывода информации о состоянии объекта
    {
        cout << "Number - " << number << endl;
        cout << "Weight - " << weight << endl; 
        cout << "Price - " << price << endl;
    }
    void setn(int numder) //метод set для поля номер
    {
        if (numder >= 0)
            this->number = numder;
    }
    void setw(int weight) //метод set для поля вес
    {
        if (weight >= 0)
            this->weight = weight;
    }
    void setp(int price) //метод set для поля цена
    {
        if (price >= 0)
            this->price = price;
    }
    //методы get для всех полей 
    int getn()
    {
        return number;
    }
    int getw()
    {
        return weight;
    }
    int getp()
    {
        return price;
    }
};
class Market
{
    int count;
    Product arrayO[1000];
public:
    Market()
    {
        count = 0;
    }
    bool add(Product *pp)
    {
        if (count <= 1000)
        {
            arrayO[count].setn(pp->getn());
            arrayO[count].setw(pp->getw());
            arrayO[count].setp(pp->getp());
            count++;
            return true;
        }
        return false;
    }
    bool del()
    {
        if (count > 0)
        {
            count--;
            return true;
        }
        return false;
    }
    int getc()
    {
        return count;
    }
    void MPrint()
    {
        cout << "Kolvo - " << count << endl;
        for (int i = 0; i < count; i++)
        {
            arrayO[i].print();
        }
    }
};
int main()
{
    Market SS;
    cout << "Vvod 1 - dobavit. Vvod 2 - del. Vvod 3 - print. Vvod 4 - exit" << endl;
    while (true)
    {
        int a;
        int nu;
        int we;
        int pr;
        cin >> a;
        switch (a)
        {
        case(1):
        {cout << "Vvodite number:";
        cin >> nu;
        cout << "Vvodite wes:";
        cin >> we;
        cout << "Vvodite price:";
        cin >> pr;
        Product e(nu, we, pr);
        if (SS.add(&e) == true)
        {
            cout << "Good!" << endl;
        }
        else
            cout << "Bad" << endl;
        break; }
        case(2):
            if (SS.del() == true)
            {
                cout << "Good!Tovar deleted" << endl;
            }
            else
            {
                cout << "Bad" << endl;
            }
            break;
        case(3):
            SS.MPrint();    
            break;
        case(4):
            exit(0);
            break;
        default:
            break;
        }
    }
    /*
    Product p;
    Product p1(1, 80, 9000);
    Product p2(p1);
    Market SS;
    SS.add(&p);
    SS.add(&p1);
    SS.MPrint();
    SS.del();   
    SS.MPrint(); */
}