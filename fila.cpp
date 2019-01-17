#include<iostream>
using namespace std;
//assinatura das funções
struct celula{
    int dado;
    struct celula *proximo;
};

celula* AdicionaCelula(int dado, celula* inicio);
void destroilista(celula* inicio);


int main(int argc, char const *argv[])
{
    celula *iniciar;
    int valor;
    char verifi;
    
    do{
        cout<<"digite o valor: ";
        cin>>valor;
        iniciar = AdicionaCelula(valor, iniciar); 
        cout<<"deseja adiconar mais?(s/n)"<<endl;
        cin>>verifi;
    }while(verifi=='s');
    cout<<"deseja apagar toda a lista?(s/n)"<<endl;
    if(scanf("%c",&verifi)=='s'){
        destroilista(iniciar);
    }

      
    return 0;
}
celula* AdicionaCelula(int dado, celula* inicio){
    if(inicio==NULL){
        inicio=new celula();
        inicio->dado=dado;
        inicio->proximo=NULL;
        return inicio;
    }
    else{
        celula *temp = inicio;
        while(temp->proximo!=NULL){
            temp = temp->proximo;
        }
        temp->proximo=new celula();
        temp->proximo->dado=dado;
        temp->proximo->proximo=NULL;
        return temp;

    }
}
void destroilista(celula *inicio){
    celula *temp, *anterior;
    if(inicio==NULL){
        cout<<"nenhum campo encontrado"<<endl;
    }
    else if(inicio->proximo==NULL){
        delete inicio;
    }
    else{
        temp=inicio;
        while(temp->proximo!=NULL){
            anterior=temp;
            temp=temp->proximo;
            cout<<"nó removido: %t"<<anterior->dado<<"endereço: "<<anterior<<endl;
            delete anterior;
        }
        cout<<"nó removido: %t"<<anterior->dado<<"endereço: "<<anterior<<endl;
        delete temp;
    }
}
