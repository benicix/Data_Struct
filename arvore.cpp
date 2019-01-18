#include<iostream>
using namespace std;
struct raiz{
    int dado;
    struct raiz *pe;
    struct raiz *pd;
};
raiz *AdicionaFolha(int dado, raiz *no);
void RemoverFolhas(raiz* inicio);
int main(int argc, char const *argv[])
{
    cout<<"teste"<<endl;
    return 0;
}
raiz *AdicionaFolha(int dado, raiz *no){
    if(no==NULL){
        no =new raiz();
        no->dado=dado;
        no->pe=NULL;
        no->pd=NULL;
    }else{
        if(no->dado>dado){
            if(no->pe==NULL){
                no->pe=new raiz();
                no->pe->pe=NULL;
                no->pe->pd=NULL;
                no->pe->dado=dado;
            }else{
                AdicionaFolha(dado, no->pe);
            }
        }else{
            if(no->pd==NULL){
                no->pd=new raiz();
                no->pd->pe=NULL;
                no->pd->pd=NULL;
                no->pd->dado=dado;
            }else{
                AdicionaFolha(dado,no->pd);
            }
        }
    }

}
//Remove todas as folhas da árvore recursivamente
void RemoverFolhas(raiz* inicio){
    raiz* temp=inicio;
    if(inicio==NULL){
        cout<<"nada para apagar"<<endl;
    }else{
        RemoverFolhas(inicio->pe);
        RemoverFolhas(inicio->pd);
        delete inicio;
    }
    inicio=NULL;
}