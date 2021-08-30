#include <iostream>
#include<string>

using namespace std;

class Human
{
public:

    
    Human()
    {
        name = "";
        lastname = "";
        surname = "";
        dateBirthday = "";
    }

    string &GetName() { return name; }
    string &GetLastName() { return lastname; }
    string &GetSurName() { return surname; }
    string &GetDateBirthday() { return dateBirthday; }
    
    virtual void Print()
    {
        cout << "Фамилия: " << surname << "\nИмя: " << name << "\nОтчество: " << lastname << "\nДата рождения: "
            << dateBirthday << endl;
    }

protected:
    string name ;
    string lastname;
    string surname ;
    string dateBirthday;
};

class Passport:public Human
{
public:
    
    Passport()
    {
        dateIssue="";
        number = "";
    }
    string &GetDateIssue() { return dateIssue; }
    string &GetNumber() { return number; }

    virtual void Print()override
    {
        cout << "Фамилия: " <<surname << "\nИмя: " << name << "\nОтчество: " << lastname << "\nДата рождения: " 
            << dateBirthday << "\nДата выдачи паспорта: " << dateIssue<<"\nНомер паспорта: " << number << endl;
    }


protected:
    string dateIssue;
    string number;

};

class ForeignPassport:public Passport
{
public:
    ForeignPassport()
    {
        string dateExpiry = "";
    }

    string &GetDateExpiry() { return dateExpiry; }
    

    void Print()override
    {
        cout << "Фамилия: " << surname << "\nИмя: " << name << "\nОтчество: " << lastname << "\nДата рождения: "
            << dateBirthday << "\nДата выдачи паспорта: " << dateIssue << "\nДата окончания паспорта: " << dateExpiry
            << "\nНомер паспорта: " << number << endl;
    }
private:
    string dateExpiry;
    

};

int main()
{
    setlocale(LC_ALL, "ru");
    ForeignPassport fp;
    fp.GetDateExpiry() = "08 May 2026";
    fp.GetName() = "Петр";
    fp.GetLastName() = "Сергеевич";
    fp.GetSurName() = "Иванов";
    fp.GetDateBirthday() = "15 July 1981";
    fp.GetDateIssue() = "08 May 2016";
    fp.GetNumber() = "EF851698";

    fp.Print();
    
}

/*2.Создайте класс Passport (паспорт), который будет
содержать паспортную информацию о гражданине
Украины.
С помощью механизма наследования, ре-
ализуйте класс ForeignPassport (загранпаспорт) про-
изводный от Passport. Напомним, что загранпаспорт
содержит помимо паспортных данных, также данные
о визах, номер загранпаспорта.*/