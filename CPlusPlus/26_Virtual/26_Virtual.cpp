
#include <iostream>
#include <string>



// virtual은 부모에서 정의했지만 자식에서 재정의할 수 있고, 
// [부모로 형변환된] 자식 포인터에서 vitual이 선언된 함수를 실행할 때,
// 자식의 함수가 호출된다.
// 동적 바인딩 : 컴파일 시에 정해지지 않고 런타임 중에 함수의 호출을 결정하는 것
// 정적 바인딩 : 컴파일 시에 함수의 호출이 결정되는 것

class Employee
{
protected:
    std::string Name;
    int Age;

    std::string Position;
    int Rank;

public:
    Employee()
    {

    }

    Employee(std::string _Name, int _Age, std::string _Position, int _Rank)
        : Name(_Name), Age(_Age), Position(_Position), Rank(_Rank)
    {

    }

    Employee(const Employee& employee)
    {
        Name = employee.Name;
        Age = employee.Age;
        Position = employee.Position;
        Rank = employee.Rank;
    }


    virtual void PrintInfo()
    {
        std::cout << Name << " (" << Position << " , " << Age << ") ==> " << CalculatePay() << "만원" << std::endl;
    }

    virtual int CalculatePay()
    {
        return 200 + Rank * 50;
    }

};

class Manager : public Employee
{
    int Year_of_service;

public:
    Manager(std::string _Name, int _Age, std::string _Position, int _Rank, int _Year_of_service)
        : Year_of_service(_Year_of_service),
        Employee(_Name, _Age, _Position, _Rank)
    {

    }

    Manager(const Manager& _Other)
    {
        Employee(_Other.Name, _Other.Age, _Other.Position, _Other.Rank);
        Year_of_service = _Other.Year_of_service;
    }

    Manager() : Employee()
    {

    }


    int CalculatePay() override
    {
        return 200 + Rank * 50 + 5 * Year_of_service;
    }

    void PrintInfo() override
    {
        std::cout << Name << " (" << Position << " , " << Age << ", "
            << Year_of_service << "년차) ==> " << CalculatePay() << "만원"
            << std::endl;
    }
};



class EmployeeList
{
    int Buffer;
    int Size;
    Employee** EmployeeInfo;

public:
    EmployeeList(int _alloc_employee) : Buffer(_alloc_employee)
    {
        EmployeeInfo = new Employee * [_alloc_employee];
        Size = 0;
    }

    void AddEmployee(Employee* _employee)
    {
        EmployeeInfo[Size++] = _employee;
    }

    int CurrentEmployeeSize()
    {
        return Size;
    }

    void PrintEmployeeInfo()
    {
        int TotalPay = 0;
        for (int i = 0; i < Size; i++)
        {
            EmployeeInfo[i]->PrintInfo();
            TotalPay += EmployeeInfo[i]->CalculatePay();
        }

        std::cout << "총 비용 : " << TotalPay << "만원 " << std::endl;
    }

    ~EmployeeList()
    {
        for (int i = 0; i < Size; i++)
        {
            delete EmployeeInfo[i];
        }

        delete[] EmployeeInfo;
    }
};

// 하나의 메소드를 호출했음에도 다른 동작을 하는 것을 다형성이라고 한다.

int main()
{

    EmployeeList EmpList(10);
    EmpList.AddEmployee(new Employee("노홍철", 34, "평사원", 1));
    EmpList.AddEmployee(new Employee("하하", 34, "평사원", 1));

    EmpList.AddEmployee(new Employee("유재석", 41, "부장", 7));
    EmpList.AddEmployee(new Employee("정준하", 43, "과장", 4));
    EmpList.AddEmployee(new Employee("박명수", 43, "차장", 5));
    EmpList.AddEmployee(new Employee("정형돈", 36, "대리", 2));
    EmpList.AddEmployee(new Employee("길", 36, "인턴", -2));
    EmpList.PrintEmployeeInfo();
}