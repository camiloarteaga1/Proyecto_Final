#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    setWindowTitle("Datos del usuario");
}

User::~User()
{
    delete ui;
}

void User::on_pushButton_clicked() //Receives user data
{
    QString name, contra;
    string data;
    bool comprob = false;

    name = ui->User_2->text();
    contra = ui->Password->text();
    data = name.toLocal8Bit().constData(); //QString to String
    data += ";";
    data += contra.toLocal8Bit().constData(); //String with all the user data

    if (option == 1){
        escribir(dirUser, data);
    }
    if (option == 2){
        comprob = valuser(name.toLocal8Bit().constData(), contra.toLocal8Bit().constData());
    }
}

//Valida que el usuario ya esté registrado
bool User::valuser(string nameusu, string claveusu)
{
    int cont = 0;
    string ps = "", lvl = "", name = "";
    bool aux = false;

    ifstream input(dirUser); //Abre el archivo de usuarios y lo lee linea a linea

    for (string line; getline (input, line); )
    {
        aux = false;
        ps = "";
        lvl = "";
        name = "";

        string ayuda = line; //Info decodificada

        for (unsigned int i = 0; i < ayuda.find(";"); ++i){ //Hasta que encuentre la primera ","
            name += ayuda.at(i); //String con el ID del usuario
        }

        for (unsigned int i = 0; i < name.length(); ++i){
            if (name.at(i) != nameusu.at(i)) //Compares the username of the file and the username that the user wrote
                break;

            else if (i == name.length())
                aux = true;
        }

        for (unsigned int i = ayuda.find(";") + 1; i < ayuda.find(","); ++i){
            ps += ayuda.at(i);
        }

        for (unsigned int i = 0; i < ps.length(); ++i){ //Password
            if (ps.at(i) != claveusu.at(i)) //Compares the passwords
                break;

            else if (i == 3)
                aux = true;
        }

        for (unsigned int i = ayuda.find(",") + 1; i < ayuda.length(); ++i){
            lvl += ayuda.at(i); //Checkpoint
        }

        if (aux == true){ //True si la clave esta en el archivo
            cont = 1;
            return aux;
        }

        else{
            aux = false;
        }
    }
    input.close(); //Cierra el archivo

    if (cont == 0){
        cout << "\nEl usuario no esta la base, intenta nuevamente.\n" << endl;
        return aux;
    }
    return aux;
}

//Writes into a file line by line
void User::escribir(string dir, string txt)
{
    ofstream archivo;
    archivo.open(dir, ios::app);
    if (archivo.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    archivo << txt << "\n";
    archivo.close();
}
