#include <iostream>

using namespace std;

struct numComplexo{
    int inteiro, complexo;
};

struct numComplexo complexo(int, int);
struct numComplexo soma(struct numComplexo, struct numComplexo);
struct numComplexo sub(struct numComplexo, struct numComplexo);
struct numComplexo mult(struct numComplexo, struct numComplexo);
struct numComplexo divi(struct numComplexo, struct numComplexo);
//struct numComplexo conjugado(struct numComplexo);

int main(){

    int a, b, c, d;
    struct numComplexo n1, n2, resp;
    char op;

    while (cin >> a >> b >> op >> c >> d);
        n1= complexo(a, b);
        n2= complexo(c, d);

        if(op=='+'){
            resp= soma(n1, n2);
        }
        if(op=='-'){
            resp= sub(n1, n2);
        }
        if(op=='*'){
            resp= mult(n1, n2);
        }
        if(op=='/'){
            resp= divi(n1, n2);
        }

        if(resp.complexo>=0){
            cout << resp.inteiro << " +" << resp.complexo << "i\n";
        }
        else{
            cout << resp.inteiro << " " << resp.complexo << "i\n";
        }

    return 0;
}

struct numComplexo complexo(int ptInt, int ptComp){
    struct numComplexo numComp;
    numComp.inteiro= ptInt;
    numComp.complexo= ptComp;

    return numComp;
}
struct numComplexo soma(struct numComplexo n1, struct numComplexo n2){
    struct numComplexo soma;
    soma.inteiro= n1.inteiro+n2.inteiro;
    soma.complexo= n1.complexo+n2.complexo;

    return soma;
}
struct numComplexo sub(struct numComplexo n1, struct numComplexo n2){
    struct numComplexo sub;
    sub.inteiro= n1.inteiro-n2.inteiro;
    sub.complexo= n1.complexo-n2.complexo;

    return sub;
}
struct numComplexo mult(struct numComplexo n1, struct numComplexo n2){
    struct numComplexo mult;
    mult.inteiro= (n1.inteiro*n2.inteiro) - (n1.complexo*n2.complexo);
    mult.complexo= (n1.inteiro*n2.complexo) + (n1.complexo*n2.inteiro);

    return mult;
}
struct numComplexo divi(struct numComplexo n1, struct numComplexo n2){
    struct numComplexo divisao, conjug;
    //conjug= conjugado(n2);
    divisao.inteiro= ((n1.inteiro*n2.inteiro) + (n1.complexo*n2.complexo))/(n2.inteiro*n2.inteiro + n2.complexo*n2.complexo);
    divisao.complexo= ((n2.inteiro*n1.complexo)-(n1.inteiro*n2.complexo))/(n2.inteiro*n2.inteiro + n2.complexo*n2.complexo);
    return divisao;
}
/*struct numComplexo conjugado(struct numComplexo n1){
    struct conjug;
    conjug.complexo= -(n1.complexo);

    return conjug;
}*/
