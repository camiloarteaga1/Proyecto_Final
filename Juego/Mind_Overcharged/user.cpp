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
    name = ui->User_2->text();
    contra = ui->Password->text();
    data = name.toLocal8Bit().constData(); //QString to String
    data += ";";
    data += contra.toLocal8Bit().constData(); //String with all the user data
    /*
    *data = ui->User_2->text().toLocal8Bit().constData(); //QString to String
    *data += ";";
    *data = ui->Password->text().toLocal8Bit().constData(); //QString to String
    */
    if (option == 1){
        string dirdatauser = "../Usuarios";
        escribir(dirUser, data);
        dirdatauser += name.toLocal8Bit().constData();
        escribir(dirdatauser, data);
    }
    if (option == 2){
        //Function val
    }
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
