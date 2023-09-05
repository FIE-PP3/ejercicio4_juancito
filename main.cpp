#include <iostream>
using namespace std;

class persona{
private:
    string nombre;
    int edad;
public:
    persona(string &nom,int e){
        nombre=nom;
        edad=e;
    }
    /*string getNombre(){
        return nombre;
    }*/
};
class celular{
private:
    string marca;
    float bateria;
    bool estado;
    string dueno;
public:
    celular(string &marc,string &due){
        marca=marc;
        bateria=5;
        estado= false;
        dueno=due;
    }
    /*string getMarca(){
        return marca;
    }*/
    float getBateria() const{
        return bateria;
    }
    void setBateria( float aux){
        bateria=aux;
    }
    bool getEstado() const{
        return estado;
    }
    string getDueño(){
        return dueno;
    }
    void encender(){
        estado= true;
    }
    void apagar(){
        cout<<"Saludos"<<endl;
        estado=false;
    }
    void estados(){
        if(estado)
        {
            cout << "Bienvenido a su celular " << marca << " " << dueno << "\nBateria: " << bateria << endl;
        } else{
            cout<<"El celular se encuentra apagado. Para usarlo enciendalo"<<endl;
        }
    }
    virtual void llamar(int seg){
        bateria-=1;
    }
    void mostrarBat(){
        cout<<"Actualmente tiene: "<<bateria<<" de bateria"<<endl;
    }
    void recargar(){
        bateria=5;
    }
    void menu(){
        int resp;
        cout<<"Que desea hacer:\n1-Llamada\n2-Ver bateria\n3-Recargar el celular\n4-Apagar el celular"<<endl;
        cin>>resp;
        while(estado){
            if(resp==1)
            {
                int duracion;
                cout<<"Cuanto va a durar la llamada:";
                cin>>duracion;
                llamar(duracion);
            } else if(resp==2){
                mostrarBat();
            } else if(resp==3){
                recargar();
            } else if (resp==4){
                break;
            } else if(resp<4 && resp>1){
                cout<<"Respuesta no valida"<<endl;
            }
            cout<<"Que desea hacer:\n1-Llamada\n2-Ver bateria\n3-Recargar el celular\n4-Apagar el celular"<<endl;
            cin>>resp;
        }
        apagar();

    }
};
class Samsung:public celular{
public:
    Samsung(string &marca, string &propietario): celular(marca, propietario){}
    void llamar( int seg)override {
        float aux=getBateria();
        aux=aux-0.25;
        setBateria(aux);
    }
};
class Iphone:public celular{
public:
    Iphone(string &marca, string & propietario): celular(marca, propietario){}
    void llamar(int seg)override {
        float aux=getBateria();
        aux=(float)aux-(seg * 0.001);
        setBateria(aux);
    }
};

int main() {
    string nombre1,nombre2,marca1,marca2;
    marca1="Samsung";
    marca2="Iphone";
    nombre1="Catalina";
    nombre2="Juliana";
    persona Catalina(nombre1,21);
    persona Juliana(nombre2,21);
    Samsung S21(marca1,nombre1);
    Iphone Pro13(marca2,nombre2);
    S21.encender();
    S21.estados();
    S21.menu();
    Pro13.estados();
    Pro13.encender();
    Pro13.estados();
    Pro13.menu();

    return 0;
}
