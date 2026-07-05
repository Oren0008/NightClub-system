#include <iostream>
using namespace std;

int main() {

    int EntryAge = 18;
    int AgeAns;
    char VIPAns;
    int balance = 0;
    int cash = 500;
    int SysAns;
    int ATMans;
    int deposit;
    int ATMmoney;
    int withdraw;
    bool hasVIP = false;

        
        while(true) {
        start_system:

        cout << "-------------- [SYSTEM] --------------\n";
        cout << "1. Enter NightClub\n";
        cout << "2. ATM\n";
        cout << "3. VIP Store\n";
        cout << "4. Exit\n";
        cin >> SysAns;

        switch(SysAns) {
            case 1:
                cout << "******* WELCOME TO NIGHTCLUB *******" << '\n';

                cout << "what is ur age? :   ";
                cin >> AgeAns;
                
                if (AgeAns >= EntryAge) {
                    cout << "do u have VIP card? Y/N " << '\n';
                    cin >> VIPAns;
                } else {
                    cout << "leave, ur not 18!\n";
                    return 0;
                }

                while(true) {
                if ((VIPAns == 'Y' || VIPAns == 'y')) {
                    if (hasVIP == true) {
                    cout << "U CAN ENTER NOW!!" << endl;
                    return 0;
                    } else {
                        cout << "ur lying!!\n";
                        goto start_system;
                    }
                } else if ((VIPAns == 'N' || VIPAns == 'n')) {
                    cout << "go buy VIP card!\n";
                    goto start_system;
                } else {
                    cout << "Invalid Ans Try again!" << '\n';
                    cin >> VIPAns;
                }
                }

                            //ATM
            ATM_system:
            case 2:
                cout << "********** ATM **********\n";
                cout << "1. DEPOSIT\n";
                cout << "2. WITHDRAW\n";
                cout << "3. BALANCE CHECK\n";
                cout << "4. Go back System\n";
                cin >> ATMans;

                if (ATMans == 4) {
                    goto start_system;
                }

                switch(ATMans) {
                    case 1:
                        cout << "how much u wanna deposit\n";
                        cin >> deposit;
                        
                        if (deposit > cash) {
                            cout << "u have not enough balance CHECK UR BALANCE\n";
                            goto ATM_system;
                        } else {
                            cash = cash - deposit;
                            balance = deposit + balance;
                            cout << "deposit Successful! Ur balance: " << balance << '\n';
                            goto ATM_system;
                        }


                        case 2:
                            cout << "how much u wanna withdraw\n";
                            cin >> withdraw;

                            if (withdraw > balance) {
                                cout << "u not enough balance to withdraw CHECK UR BALANCE!\n";
                                goto ATM_system;
                            } else {
                                balance = balance - withdraw;
                                cash = withdraw + cash;
                                cout << "withdraw Successful! Ur cash: " << cash << '\n';
                                goto ATM_system;
                            }

                        case 3: 
                        cout << "Ur balance :  " << balance << '\n';
                        goto ATM_system;
            
                        default:
                        cout << "invalid ans Try again\n";
                        goto ATM_system;
                }
            case 3:
                goto VIP_store;

            case 4:
                cout << "BYE!";
                return 0;
            }
        
    VIP_store:

    char VIPANSW;
    int VIPPRICE = 500;

        cout << "******* WELCOME TO VIP STORE *******" << '\n';    
        cout << "only card payment \n";
        cout << "do u wanna buy VIP CARD? Y/N \n";
        cin >> VIPANSW;
            
            if (VIPANSW == 'Y' || VIPAns == 'y') {
                if (balance >= VIPPRICE) {
                    balance = balance - VIPPRICE;
                    hasVIP = true;
                    cout << "bought success, ur balance:  " << balance << '\n';
                    goto start_system;
                } else {
                    cout << "balance not enough PLS go to ATM deposit \n";\
                    goto start_system;
                }
            } else {
                cout << "bye\n";
                goto start_system;
            }
    
        }
    return 0;
}