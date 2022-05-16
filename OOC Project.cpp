#include<iostream>
#include<string>
using namespace std;

//class definition
class Services;
class RegisteredCustomer;
class UnregisteredUser;
class Transactions;
class Feedback;
class Problems;
class System;
class Accounts;
class Manager;
class Accountant;
class Technician;
class CustomerServiceRepresentative;
class AdministrativeDepartment;


//Binod
class System 
{
protected:
int Type;
string Name;
string Email;
string DOB;
ServiceID * SID;

public:
System();
System(int Type);
void ManageUserDetails();
void ManageEmployeeDetails();
void ManageServer()
{
    SID = new Services();
}
~System();
};


class RegisteredCustomer : public System
{
private:
int CustomerID;
int Age;
string Address;
string TelNo;
TransactionID * TID;
FeedbackID * FID;
Problems * prb;
Balance * blc;

public:
RegisteredCustomer();
RegisteredCustomer(int CustomerID, int Age, string Name, string Email, string DOB, string Address, string TelNo);
void Login();
void ReportProblems();
void RequestServices();
void MakeTransactions()
{
    TID = new Transactions(); 
}
void ProvideFeedback()
{
    FID = new Feedback();
}
void UpdateProfileInformation();
void UpdateAccountBalance()
{
    blc = new Balance();
}
~RegisteredCustomer();
};


//Hemsith
class UnregisteredUser : public System
{
private:
int UserID;

public:
UnregisteredUser();
UnregisteredUser(int UserID, string Name, string Email, string DOB);
void Register();
void ProvideUserDetails();
void ValidateUserDetails();
void DisplayUserDetails();
~UnregisteredUser();
};


class Transactions
{
private:
int TransactionID;
double Amount;
string Transaction_Type;

public:
Transactions();
Transactions(int TransactionID, double Amount, string Transaction_Type);
void StoreTransactionDetails();
void UpdateTransactionDetails();
void DisplayTransactionDetails();
~Transactions();
};


class Manager
{
private:
int ManagerID;
string Name;
string Email;


public:
Manager();
Manager(int ManagerID, string Name, string Email);
void StoreManagerDetails();
void DisplayManagerDetails();
void ManageAccounts();
void ProvideSupervision();
~Manager();
};


//Rivi
class Services
{
private:
int ServiceID;
string Service_Type;
string Service_Description;

public:
Services();
Services(int ServiceID, string Service_Type, string Service_Description);
void StoreServiceDetails();
void DisplayServiceDetails();
~Services();
};


class Accountant
{
private:
int AccountantID;
string Name;
string Email;

public:
Accountant();
Accountant(int AccountantID, string Name, string Email);
void StoreAccountantDetails();
void DisplayAccountantDetails();
void ManageAccounts();
void CheckAccounts();
~Accountant();
};


class AdministrativeDepartment
{
private:
int DepartmentID;
string Hotline;
string Email;

public:
AdministrativeDepartment();
AdministrativeDepartment(int DepartmentID, string Hotline, string Email);
void IntroduceLoanSchemes();
void IntroduceAccountTypes(int Account_Type, Accounts*A);
void IntroducePromotions();
~AdministrativeDepartment();
};


//Viraj
class Feedback
{
private:
int FeedbackID;
int Rating;
string Description;

public:
Feedback();
Feedback(int FeedbackID, int Rating, string Description, CustomerServiceRepresentative * csr);
void DisplayFeedback();
~Feedback();
};


class Technician
{
private:
int TechnicianID;
string Name;
string Email;
CustomerServiceRepresentative * csr[3];

public:
Technician();
Technician(int TechnicianID, string Name, string Email);
void StoreTechnicianDetails();
void DisplayTechnicianDetails();
void InspectDetails();
void FixCustomerIssues(int ProblemID, string Description, Problems*P);
void addCSR(CustomerServiceRepresentative * csr1, CustomerServiceRepresentative*csr2, CustomerServiceRepresentative*csr3)
{
    csr[0]=csr1;
    csr[1]=csr2;
    csr[2]=csr3;

}
~Technician();
};


//Maneesha
class Problems
{
private:
int ProblemID;
string Description;

public:
Problems();
Problems(int ProblemID, string Description);
void StoreProblemDetails();
void DisplayProblemDetails();
~Problems();
};


class Accounts
{
private:
int AccountNO;
double Balance;
string Account_Type;
Manager * mgr;
Accountant * act;

public:
Accounts();
Accounts(int AccountNO, double Balance, string Account_Type);
void StoreAccountDetails();
void DisplayAccountDetails();
void UpdateAccountBalance();
~Accounts();
};


class CustomerServiceRepresentative
{
private:
int CSRID;
string Name;
string Email;

public:
CustomerServiceRepresentative();
CustomerServiceRepresentative(int CSRID, string Name, string Email);
void StoreCSRDetails();
void DisplayCSRDetails();
void ResolveCustomerComplaints();
~CustomerServiceRepresentative();
};



//client program
int main(void)
{
    Services* serv1 = new Services("1001", "pay bills", "paying online bills", "10003");
    RegisteredCustomer* rc1 = new RegisteredCustomer("10003", "43", "Kabral", "Kabral@gmail.com", "1979/01/25", "Kandy","0712563968");
    Manager* M2 = new Manager("1002", "Nuwan", "nuwanbinod@gmail.com");
    Accountant* A1 = new Accountant("1003", "Abilash", "abilash@gmail.com");
    Accounts* Ac2 = new Accounts("88888888", "checkings", "5000");
    CustomerServiceRepresentative* CSR1 = new CustomerServiceRepresentative("CSR1003", "Rivi", "rivik@gmail.com");
    Technician* T1 = new Technician("Tec1003", "anuhas", "anuhas@gmail.com");
    Transactions* TS1 = new Transactions("10004", "2000.00", "Bill payemnt");
    Problems* p1 = new Problems("1003", "while transactioning an error popped up");
    UnregisteredUser* US1 = new UnregisteredUser("103", "Sasika", "sasik@gmail.com", "1996-12-09");
    Feedback* F1 = new Feedback("004", "Comfortable", "This is very useful app and save my time");
    System* S3 = new System("Online customer support system");
    AdministrativeDepartment* AMD2 = new AdministrativeDepartment("1100","0112200300","admindip@gmail.com");


    serv1 -> StoreServiceDetails();
    serv1 -> DisplayServiceDetails();

    TS1 -> StoreTransactionDetails();
    TS1 -> UpdateTransactionDetails();
    TS1 -> DisplayTransactionDetails();

    T1 -> StoreTechnicianDetails();
    T1 -> DisplayTechnicianDetails();
    T1 -> void InspectDetails();
    T1 -> void FixCustomerIssues(ProblemID, Description, Problems*P);
    T1 -> void addCSR(CustomerServiceRepresentative * csr1, CustomerServiceRepresentative*csr2, CustomerServiceRepresentative*csr3);

    AMD2 -> IntroduceLoanSchemes();
    AMD2 ->  IntroduceAccountTypes(Account_Type, Accounts*A);
    AMD2 -> IntroducePromotions();

    CSR1 -> StoreCSRDetails();
    CSR1 -> DisplayCSRDetails();
    CSR1 -> ResolveCustomerComplaints();

    A1 -> StoreAccountantDetails();
    A1 -> DisplayAccountantDetails();
    A1 -> ManageAccounts();
    A1 ->  CheckAccounts();

    M2 -> StoreManagerDetails();
    M2 -> DisplayManagerDetails();
    M2 -> ManageAccounts();
    M2 -> ProvideSupervision();

    P1 -> StoreProblemDetails();
    P1 -> DisplayProblemDetails();

    AC2 -> StoreAccountDetails();
    AC2 -> DisplayAccountDetails();
    AC2 -> UpdateAccountBalance();

    F1 -> DisplayFeedback();

    US1 -> Register();
    US1 -> ProvideUserDetails();
    US1 -> ValidateUserDetails();
    US1 -> DisplayUserDetails();

    S3 -> ManageUserDetails();
    S3 -> ManageEmployeeDetails();
    S3 -> ManageServer();

    RC1 -> Login();
    RC1 -> ReportProblems();
    RC1 -> RequestServices();
    RC1 -> MakeTransactions();


    delete serv1;
    delete rc1;
    delete M2;
    delete A1;
    delete Ac2;
    delete CSR1;
    delete T1;
    delete TS1;
    delete p1;
    delete US1;
    delete F1;
    delete S3;
    delete AMD2;

    return 0;
}