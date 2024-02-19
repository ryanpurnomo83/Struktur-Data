#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char c){
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
            return true;
        }else{
            return false;
        }
    }

    int precedence(char c){
        if(c == '^'){
            return 3;
        }else if(c == '*' || c == '/'){
            return 2;
        }else if(c == '+' || c == '-'){
            return 1;
        }else{
            return -1;
        }
    }

string InfixToPostfix(stack<char>s, string infix){
        string postfix;

        for(int i = 0; i < infix.length(); i++){
            if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')){
                postfix+=infix[i];
            }else if(infix[i] == '('){
                s.push(infix[i]);
            }else if(infix[i] == ')'){
                while((s.top()!='(') && (!s.empty())){
                        char temp = s.top();
                        postfix+=temp;
                        s.pop();
                }
                if(s.top()=='('){
                    s.pop();
                   }
            }else if(isOperator(infix[i])){
                if(s.empty()){
                    s.push(infix[i]);
                }else{
                    if(precedence(infix[i]) > precedence(s.top())){
                        s.push(infix[i]);
                    }
                    else if((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^')){
                        s.push(infix[i]);
                    }else{
                        while((!s.empty()) && (precedence(infix[i]) <= precedence(s.top()))){
                            postfix+=s.top();
                            s.pop();
                        }
                        s.push(infix[i]);
                    }
                }
            }
        }
        while(!s.empty()){
            postfix+=s.top();
            s.pop();
        }
        return postfix;
    }

string InfixToPrefix(stack<char>s, string infix){
        string prefix;
        reverse(infix.begin(), infix.end());

        for(int i =  0; i <  infix.length(); i++){
            if(infix[i] ==  '('){
                infix[i] == ')';
           }else if(infix[i] == ')'){
                infix[i] = '(';
           }
        }

        for(int i = 0; i < infix.length(); i++){
            if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')){

            }else if(infix[i] == '('){
                s.push(infix[i]);
            }else if(infix[i] == ')'){
                while((s.top()!='(') && (!s.empty())){
                        prefix+=s.top();
                        s.pop();
                }
                if(s.top()=='('){
                    s.pop();
                   }
            }else if(isOperator(infix[i])){
                if(s.empty()){
                    s.push(infix[i]);
                }else{
                    if(precedence(infix[i]) > precedence(s.top())){
                        s.push(infix[i]);
                    }
                    else if((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^')){
                        while((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^')){
                            prefix+=s.top();
                            s.pop();
                        }
                        s.push(infix[i]);
                    }else if (precedence(infix[i]) == precedence(s.top())){
                        s.push(infix[i]);
                    }else{
                        while((!s.empty()) && (precedence(infix[i]) <  precedence(s.top()))){
                            prefix += s.top();
                            s.pop();
                        }
                        s.push(infix[i]);
                    }
                }
            }
        }
        while(!s.empty()){
            prefix+=s.top();
            s.pop();
        }

        reverse(prefix.begin(), prefix.end());
        return prefix;
    }






int main()
{
    string infix_exp, postfix_exp, infix, prefix_exp;
    int pilihan;

    stack <char> stack;

    do{
    system("cls");

    cout << "\nProgram STACK (Infix, Postfix, Prefix) : " << endl;
    cout << "\n1. Infix to Postfix\n2. Infix To Prefix\n3. Keluar" << endl;
    cout << "\nSilahkan Masukkan pilihan anda : ";cin >> pilihan;

    switch(pilihan){
    case 1:
        cout << "\nMasukkan kombinasi Ekspresi Infix [A - Z, (, ), ^, *, /, +, - ] : ";
        cin >> infix_exp;
        cout <<"\n Ekspresi awal infix : " << infix_exp << endl;
        postfix_exp = InfixToPostfix(stack, infix_exp);

        cout << endl << "Hasil ekspresi INFIX TO POSTFIX : ";
        cout << endl << "\n INFIX : " << infix_exp << " ke PREFIX : " << postfix_exp << endl;

        cout << "\nSilahkan tekan Enter untuk kembali ke menu awal";
        system("pause");
        break;

        case 2:
        cout << "\nMasukkan kombinasi Ekspresi Infix [A - Z, (, ), ^, *, /, +, - ] : ";
        cin >> infix_exp;
        cout <<"\n Ekspresi awal infix : " << infix_exp << endl;
        prefix_exp = InfixToPrefix(stack, infix_exp);

        cout << endl << "Hasil ekspresi INFIX TO PREFIX : ";
        cout << endl << "\n INFIX : " << infix_exp << " ke PREFIX : " << prefix_exp << endl;

        cout << "\nSilahkan tekan Enter untuk kembali ke menu awal";
        system("pause");
        break;

        case 3:
            cout << "\nTerima kasih sudah mencoba program ini";break;

        default:
            cout << "\nPilihan yang anda pilih tidak ada " << endl;
            cout << "\nSilahkan tekan Enter untuk kembali ke menu awal " << endl;
            system("pause");
        }
    }while(pilihan != 3);

    return 0;
}





