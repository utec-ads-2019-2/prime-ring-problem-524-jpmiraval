#include <iostream>

using namespace std;

int numerito, Case = 1, linea[500] = {1};

bool Primo(int a){
    if (a>1){
        for (int i = 2; i < a; i++)
            if(a%i==0)
                return false;
    }
    else{
        return false;
    }

    return true;
}

void check(int len, bool pasa[]){
    if (len == numerito) {
        if (!Primo(linea[numerito-1] + 1))
            return;
        cout<<"1";
        for (int i = 1; i < numerito; ++i)
            cout<<" "<<linea[i];
        cout<<'\n';
        return;
    }
    for (int i = 2; i <= numerito; ++i) {
        if (pasa[i])
            continue;
        if (Primo(i + linea[len - 1])) {
            pasa[i] = true;
            linea[len] = i;
            check(len + 1, pasa);
            pasa[i] = false;
        }
    }
}

int main(){
    while (cin>>numerito) {
        if(Case > 1){
            cout<<"\n";
        }
        cout<<"Case " <<Case<<":\n";
        bool pasa[500] = {false};
        check(1, pasa);
        Case++;
    }
}