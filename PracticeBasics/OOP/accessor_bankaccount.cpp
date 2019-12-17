#include <iostream>
#include <string>

class BankAccount{
    private:
        std::string holderName;
        std::string const accountNumber;
        long long int balance;

    public :
        //Setters
        BankAccount(std::string holderName, std::string accountNumber, long long int balance);
        void HolderName(std::string holderName);
        void AccountNumber(std::string accountNumber) const;
        void Balance(long long int balance);

        //Getters
        std::string HolderName();
        std::string AccountNumber();
        long long int Balance();
};

BankAccount::BankAccount(std::string holderName,std::string accountNumber, long long int balance):accountNumber(accountNumber){
    HolderName(holderName);
    Balance(balance);
}
void BankAccount::HolderName(std::string holderName){
    if(holderName.size() > 0){
        this->holderName = holderName;
    }
}
void BankAccount::AccountNumber(std::string accountNumber) const{
    // accountNumber is init at beginning, we can't set any more
}
void BankAccount::Balance(long long int balance){
    this->balance = balance;
}
std::string BankAccount::HolderName(){
    return this->holderName;
}
std::string BankAccount::AccountNumber(){
    return this->accountNumber;
}
long long int BankAccount::Balance(){
    return this->balance;
}

int main(int argc, char ** argv){
    BankAccount bankaccount("Huy Nguyen","123456789",999999999999999999);
    std::cout << bankaccount.HolderName() << " holds " << bankaccount.Balance() <<" dollars in bank acount "<< bankaccount.AccountNumber() <<std::endl;
    bankaccount.Balance(1);
    std::cout << bankaccount.HolderName() << " holds " << bankaccount.Balance() <<" dollars in bank acount "<< bankaccount.AccountNumber() <<std::endl;
}

