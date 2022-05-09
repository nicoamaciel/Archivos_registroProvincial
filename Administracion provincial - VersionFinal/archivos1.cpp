/***
La administración provincial necesita realizar un análisis sobre los empleados de los distintos tipos de empresas.
Tiene, entre otros, el siguiente archivo en su sistema
Empresas.dat
Número de empresa (Número entero. No se repite en el archivo. Es único para cada empresa)
Nombre (char[30])
Cantidad de empleados
Categoría (1 a 80)
Número de municipio al que pertenece (1 a 135)
Estado (bool)

A partir de la información contenida en el archivo, hacer un programa para resolver los siguientes puntos

1- Calcular e informar la cantidad de empresas de cada municipio.
2- Informar los nombres de las empresas con más de 200 empleados.
3- Calcular e informar la categoría de empresa con más empleados
Diseñar la clase necesaria, y hacer un menú con opciones para la ejecución de cada punto.
Cada punto debe resolverse por separado en una función.
***/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class empleados{
private:
    int _numeroEmpresa;
    char _nombre[30];
    int _cantEmpleados;
    int _categoria;
    int _numeroMunicipio;
    bool _estado;
public:
    empleados(int numeroEmpresa=0){
        _numeroEmpresa=numeroEmpresa;
    }


    ///gets
        int getnumeroEmpresa(){
        return _numeroEmpresa;
        }
        const char *getnombre(){
        return _nombre;
        }

        int getcantEmpleados(){
        return _cantEmpleados;
        }

        int getcategoria(){
        return _categoria;
        }

        int getnumMunicipio(){
        return _numeroMunicipio;
        }

        bool getestado(){
        return _estado;
        }

    ///sets
        void setnumeroEmpresa( int numEmpre){
            _numeroEmpresa=numEmpre;
        }
        void setnombre( const char *nomb){
            strcpy(_nombre,nomb);
        }

        void setcantEmpleados( int cantEmpleados){
            _cantEmpleados=cantEmpleados;
        }

        void setcategoria( int catego){
            _categoria=catego;
        }

        void setnumMunicipio( int numMunicipio){
            _numeroMunicipio=numMunicipio;
        }

        void setestado(bool estado){
            _estado=estado;
        }

        void cargar();
        void mostrar();

        ~empleados(){};


}; //FinDeClase

    void empleados::cargar(){
    int n;
    bool estado;
    char nom[30];

    cout << "Cargar numero de empresa: ";
    cin >> n;
    setnumeroEmpresa(n);
    cout << "Cargar nombre de empresa: ";
    cin >> nom;
    setnombre(nom);
    cout << "Cargar cantidad de empleados: ";
    cin >> n;
    setcantEmpleados(n);
    cout << "Cargar categoria: ";
    cin >> n;
    setcategoria(n);
    cout << "Cargar numero de municipio: ";
    cin >> n;
    setnumMunicipio(n);
    cout << "Cargar estado: ";
    cin >> estado;
    setestado(estado);

    }


    void empleados::mostrar(){

    cout << endl << "------------" << endl;
    cout << "Numero de empresa: " << getnumeroEmpresa() << endl;
    cout << "Nombre de empresa: "<< getnombre() << endl;
    cout << "Cantidad de empleados: "<< getcantEmpleados() << endl;
    cout << "Categoria: "<< getcategoria() << endl;
    cout << "Numero de municipio: "<< getnumMunicipio() << endl;
    cout << "Estado: "<< getestado() << endl;

    }

    ///PROTOTIPO
    int grabarArchivo(empleados aux);
    void leerRegistro();
    int buscarEmpresa(int emp);
    void mayorDoscientos (int doscientos);
    void puntoB ();
    void puntoC ();


int main () {
    empleados obj;
    int opcion, encontro=0;

    while(true){
        system("cls");
        cout << "-------MENU-----" << endl;
        cout << "1 - Cantidad de empresas de cada municipio: " << endl;
        cout << "2 - Nombres de las empresas con mas de 200 empleados: "<< endl;
        cout << "3 - Categoria de empresa con mas empleados: "<< endl;
        cout << "4 - Cargar registro "<< endl;
        cout << "5 - Leer registro " << endl;
        cout << "----------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
        case 1:
            puntoB();
        break;
        case 2:
            mayorDoscientos (obj.getcantEmpleados());
        break;
        case 3:
            puntoC();
        break;
        case 4:
            obj.cargar();
            encontro = buscarEmpresa(obj.getnumeroEmpresa());

           if(encontro==-2){
                     if (grabarArchivo(obj)==1){
                    cout << "Registro agregado " ;
                    }
                    else{cout << "Registro no agregado";}
                }
                else{
                    cout << "El legajo ya existe: ";
                }
        break;
        case 5:
            leerRegistro();
        break;

        case 0: return 0;
        break;

        }
        cout<<endl;
        system("pause");


    }


return 0;
}
//Fuera del Main
int grabarArchivo(empleados aux){
        FILE *pEmp;
        pEmp=fopen("Empresa.dat","ab");//Escribir append - Apertura de un archivo binario para agregar registros (append). Si no existe lo crea.
        if(pEmp==NULL){
            cout << "ERROR DE ARCHIVOS" << endl;
            system("pause");
            return -1;
        }
        int escribio=fwrite(&aux, sizeof aux, 1, pEmp);
        fclose(pEmp);
        return escribio;

    }

void leerRegistro(){
    FILE *pEmp;
    empleados aux;
    pEmp=fopen("Empresa.dat","rb");//Leer
        if(pEmp==NULL){
            cout << "ERROR DE ARCHIVOS" << endl;
            system("pause");
        }


        while(fread(&aux,sizeof aux, 1, pEmp)==1){//lista todo el archivo sabiendo lo que devuelve fread
        aux.mostrar();

        cout << endl;

        }

         fclose(pEmp);
    }


int buscarEmpresa(int emp){
    FILE *pEmp;
    empleados aux;
    pEmp=fopen("Empresa.dat","rb");//Leer
    if(pEmp==NULL){
        return -1;
        }
        while(fread(&aux,sizeof aux, 1, pEmp)==1){
            if(aux.getnumeroEmpresa()==emp){
                return 1;
                fclose(pEmp);
            }
            return -2;
            fclose(pEmp);

        }
        return -2;
        fclose(pEmp);

    }


void mayorDoscientos (int doscientos){
    int masDoscientos=0;
    FILE *pDos;
    empleados aux;
    pDos=fopen("Empresa.dat","rb");//Leer
    if(pDos==NULL){
        cout << "ERROR DE ARCHIVO";
        }
        cout << "Nombres de las empresas con mas de 200 empleados: ";
        while(fread(&aux,sizeof aux, 1, pDos)==1){
            if(aux.getcantEmpleados()>200){
                cout << endl;
                cout << aux.getnombre();
            }

        }
        fclose(pDos);

}

void puntoB (){
    FILE *pDos;
    empleados aux;
    pDos=fopen("Empresa.dat","rb");//Leer
    if(pDos==NULL){
        cout << "ERROR DE ARCHIVO";
        }
        cout << "Cantidad de empleados por municipio: ";
        while(fread(&aux,sizeof aux, 1, pDos)==1){
            if(aux.getcantEmpleados()>0){
                cout << endl << "Municipio: " << aux.getnumMunicipio() << endl ;

                cout << "Empleados: " << aux.getcantEmpleados() << endl ;

                cout << "-------------------------------";
            }

        }
        fclose(pDos);

}


void puntoC (){
    FILE *pDos;
    int maxEmpleados=0, maxCatego=0;

    empleados aux;
    pDos=fopen("Empresa.dat","rb");//Leer
    if(pDos==NULL){
        cout << "ERROR DE ARCHIVO";
        }
        while(fread(&aux,sizeof aux, 1, pDos)==1){

            if(aux.getcantEmpleados()>maxEmpleados){

                maxEmpleados=aux.getcantEmpleados();
                maxCatego=aux.getcategoria();
            }

        }
        cout << endl << "Calcular e informar la categoria de empresa con mas empleados: "  << endl;
        cout << "Categoria " << maxEmpleados << endl ;
        cout << "Max mpleados: " << maxCatego;
        cout << endl <<  "-------------------------------" << endl;
        fclose(pDos);










}



