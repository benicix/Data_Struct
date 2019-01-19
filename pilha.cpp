#include<iostream>
using namespace std;
struct stack{
    int dado;
    struct stack *cima;
};
stack *adicionaTopo(int dado, stack* topo);

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
stack *adicionaTopo(int valor, stack* topo){
    if(topo==NULL){
        topo=new stack();
        topo->dado=valor;
        topo->cima=NULL;
        return topo;
    }else {
        stack *temp=topo;
        while(topo->cima!=NULL){
            topo=topo->cima;
        }
        topo->cima=new stack();
        topo->cima->dado=valor;
        topo->cima->cima=NULL;
        return topo;
    }
}