#include <iostream>

using namespace std;

struct data{
    int dia, mes, ano;
};

bool confereDiaMes(int, int, int);
bool confereBissexto(int);

int main(){

    int n;
    bool val;
    struct data d1;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> d1.dia >> d1.mes >> d1.ano;
        val= confereDiaMes(d1.dia, d1.mes, d1.ano);

        if(confereDiaMes(d1.dia, d1.mes, d1.ano)){
            cout << "DATA VALIDA\n";
        }
        else{
            cout << "DATA INVALIDA\n";
        }
    }

    return 0;
}

bool confereBissexto(int ano){
    if(ano%400==0){
        return true;
    }
    else if(ano%4==0 && ano%100!=0){
        return true;
    }
    else{
        return false;
    }
}

bool confereDiaMes(int d, int m, int a){

    bool val= true;

    if(d>31 || d<0 || m<0 || m>12){
        val= false;
        //cout << "1";
    }
    else if(d==31){
        if(m==4 || m==6 || m==9 || m==11 || m==2){
            val= false;
        }
    }
    else if(m==2 && d>28){
        if(!confereBissexto(a)){
            val= false;
        }
    }
    return val;
}
