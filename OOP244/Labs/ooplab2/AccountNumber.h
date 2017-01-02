#define MAX_NAME_LENGTH 40
#define MIN_BRANCHCODE 1
#define MAX_BRANCHCODE 220
#define MIN_BANKCODE 100
#define MAX_BANKCODE 999
#define MIN_ACCNO 10000
#define MAX_ACCNO 99999

using namespace std;

namespace oop244 {
    
    class AccountNumber {
        
        int _branchCode;
        int _bankCode;
        int _accountNumber;
        char _name[MAX_NAME_LENGTH + 1];
        bool _validAccNumber;
        
    public:
        
        void setName(const char name[]);
        void setAccountNumber(int bankCode, int branchCode, int accountNumber);
        void display() const;
        bool isValid() const;
    };
}