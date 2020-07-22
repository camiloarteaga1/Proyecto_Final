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

bool User::on_pushButton_clicked() //Receives user data
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
        escribir(dirUser, data); //Writes the user data in the file
        comprob = true;
        return comprob;
    }
    if (option == 2){
        comprob = valuser(name.toLocal8Bit().constData(), contra.toLocal8Bit().constData());//Verifies if the user is in the file
        return comprob;
    }
    return comprob;
}

//Validates that the user is already registered
bool User::valuser(string nameusu, string claveusu)
{
    int cont = 0;
    string ps = "", lvl = "", name = "";
    bool aux = false;

    ifstream input(dirUser); //Opens the file and reads it line by line

    for (string line; getline (input, line); )
    {
        aux = false;
        ps = "";
        lvl = "";
        name = "";

        string ayuda = line; //Info

        for (unsigned int i = 0; i < ayuda.find(";"); ++i){ //Until the ";"
            name += ayuda.at(i); //String with the username
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

        if (aux == true){ //True if the password is in the file
            cont = 1;
            return aux;
        }

        else{
            aux = false;
        }
    }
    input.close(); //Closes the file

    if (cont == 0){
        qDebug() << "\nEl usuario no esta la base, intenta nuevamente.";
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
        qDebug()<< "No se pudo abrir el archivo";
        exit(1);
    }

    archivo << txt << "\n";
    archivo.close();
}
