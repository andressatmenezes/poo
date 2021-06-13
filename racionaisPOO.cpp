#include <iostream>

using namespace std;

class Racional{

    private:
        int numerador, denominador;

    public:
        Racional(int, int);
        void setNumerador(int);
        void setDenominador(int);
        int getNumerador();
        int getDenominador();
        void soma(Racional);
        void subtracao(Racional);
        void produto(Racional);
        void quociente(Racional);
        void negativo();
        void simplifica();
};

Racional::Racional (int numerador, int denominador){
    this->setNumerador(numerador);
    this->setDenominador(denominador);
}
void Racional::setNumerador(int numerador){
    this->numerador= numerador;
}
void Racional::setDenominador(int denominador){
    this->denominador= denominador;
}
int Racional::getNumerador(){
    return this->numerador;
}
int Racional::getDenominador(){
    return this->denominador;
}
void Racional::soma(Racional num2){
    this->numerador= this->numerador*num2.denominador + num2.numerador*this->denominador;
    this->denominador= this->denominador*num2.denominador;
    this->simplifica();
}
void Racional::subtracao(Racional num2){
    num2.negativo();
    this->soma(num2);
}
void Racional::produto(Racional num2){
    int numeradorNovo, denominadorNovo;
    numeradorNovo= this->getNumerador()*num2.getNumerador();
    denominadorNovo= this->getDenominador()*num2.getDenominador();
    this->setNumerador(numeradorNovo);
    this->setDenominador(denominadorNovo);
    this->simplifica();
}
void Racional::quociente(Racional num2){
    int numeradorNovo, denominadorNovo;
    numeradorNovo= this->getNumerador()*num2.getDenominador();
    denominadorNovo= this->getDenominador()*num2.getNumerador();
    if(denominadorNovo<0){
        denominadorNovo= denominadorNovo*(-1);
        numeradorNovo= numeradorNovo*(-1);
    }
    this->setNumerador(numeradorNovo);
    this->setDenominador(denominadorNovo);
    this->simplifica();
}

void Racional::simplifica(){
    int i=1, cont=0, numeradorNovo, denominadorNovo;

    while(i<=this->getNumerador() || i<=this->getDenominador()){
        if(this->getNumerador()%i==0 && this->getDenominador()%i==0){
            cont=i;
        }
        i++;
    }
    numeradorNovo= this->getNumerador()/cont;
    denominadorNovo= this->getDenominador()/cont;
    this->setNumerador(numeradorNovo);
    this->setDenominador(denominadorNovo);
}
void Racional::negativo(){
    this->setNumerador(-(this->getNumerador()));
}


int main(){

    int n1, d1, n2, d2;
    char op;
    Racional *num1, *num2;

    while(cin >> n1 >> d1 >> op >> n2 >> d2){
        num1= new Racional(n1, d1);
        num2= new Racional(n2, d2);

        if(op=='+'){
            num1->soma(*num2);
            //cout << num1->getNumerador() << " " << num1->getDenominador() << "\n";
        }
        if(op=='-'){
            num1->subtracao(*num2);
        }
        if(op=='*'){
            num1->produto(*num2);
        }
        if(op=='/'){
            num1->quociente(*num2);
        }

        cout << num1->getNumerador() << " " << num1->getDenominador() << "\n";
    }

    /*Racional r1(3,2);
    Racional *r2= new Racional(1,2);

    cout << (*r2).getNumerador() << " " << (*r2).getDenominador() << "\n";
    cout << r1.getNumerador() << " " << r1.getDenominador();*/

    return 0;
}
