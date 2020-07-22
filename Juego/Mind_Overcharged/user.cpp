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
    vector <int> datos;
    QString name, contra;
    string data;
    datos.reserve(3);

    name = ui->User_2->text();
    contra = ui->Password->text();
    data = name.toLocal8Bit().constData(); //QString to String
    data += ";";
    data += contra.toLocal8Bit().constData(); //String with all the user data
    data += ",0:3";
    ui->pushButton->setEnabled(false);

    if (option == 1){
        escribir(dirUser, data); //Writes the user data in the file
        datos.push_back(1);
        datos.push_back(0);
        datos.push_back(3);
        vidas = datos[1];
        level = datos[2];
    }
    if (option == 2){
        datos = valuser(name.toLocal8Bit().constData(), contra.toLocal8Bit().constData()); //Verifies if the user is in the file
        vidas = datos[1];
        level = datos[2];
    }
    this->hide();
}

//Validates that the user is already registered
vector <int> User::valuser(string nameusu, string claveusu)
{
    vector <int> datan; //QList with some user data
    datan.reserve(3);
    int cont = 0;
    string ps = "", lvl = "", name = "", health = "";
    int aux = 0;

    ifstream input(dirUser); //Opens the file and reads it line by line

    for (string line; getline (input, line); )
    {
        aux = 0;
        ps = "";
        lvl = "";
        name = "";
        health = "";

        string ayuda = line; //Info

        for (unsigned int i = 0; i < ayuda.find(";"); ++i){ //Until the ";"
            name += ayuda.at(i); //String with the username
        }

        for (unsigned int i = 0; i < name.length(); ++i){
            if (name.at(i) != nameusu.at(i)) //Compares the username of the file and the username that the user wrote
                break;

            else if (i+1 == name.length()){
                aux = 1;
                datan.push_back(aux);
            }
        }

        for (unsigned int i = ayuda.find(";") + 1; i < ayuda.find(","); ++i){
            ps += ayuda.at(i);
        }

        for (unsigned int i = 0; i < ps.length(); ++i){ //Password
            if (ps.at(i) != claveusu.at(i)) //Compares the passwords
                break;

            else if (i+1 == ps.length()){
                aux = 1;
                datan[0] = aux;
            }
        }

        for (unsigned int i = ayuda.find(",") + 1; i < ayuda.find(":"); ++i){
            lvl += ayuda.at(i); //Checkpoint
            datan.push_back(stoi(lvl));
        }

        for (unsigned int i = ayuda.find(":") + 1; i < ayuda.length(); ++i){
            health += ayuda.at(i); //Character lifes
            datan.push_back(stoi(health));
        }


        if (aux == 1){ //True if the password is in the file
            cont = 1;
            return datan;
        }

        else{
            aux = 0;
        }
    }
    input.close(); //Closes the file

    if (cont == 0){
        qDebug() << "\nEl usuario no esta en la base, intenta nuevamente.";
        return datan;
    }
//    datos[0] = aux;
//    datos[1] = stoi(lvl);
//    datos[2] = stoi(health);
    return datan;
}

//Overwrites the user data
void User::overload(string life, string level, string user)
{
    bool aux = false;

    ifstream invent;

    invent.open(dirUser, ios::in);

    if(!invent.is_open()){ //Verifica si el archivo abrio exitosamente
        std::cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    for (string line; getline (invent, line); ){

        string password = "", idc = "", linea;


        for (unsigned int i = 0; i < line.find(";"); ++i){ //until the ";"
            idc += line.at(i); //String with username
        }

        for (unsigned int i = 0; i < idc.length(); ++i){
            if (idc.at(i) != user.at(i)) //Compares username of the player with the username of the archieve
                break;

            else if (idc == user)
                aux = true;
        }

        if (aux == true){ //True if that's the user's data
            aux = false;

            for (unsigned int i = line.find(",") + 1; i < line.find(";"); ++i){ //From the ";" until the ","
                password += line.at(i); //String with the password
            }

            linea = idc + ';' + password + ',' + life + ":" + level; //The string with the user data

            escribir(dirtemp, linea); //Updates the data
        }

        else{
            escribir(dirtemp, line); //Updates the data
        }
    }
    invent.close(); //Close the file

    borrar(dirUser); //Erase the archieve
    rename(dirtemp, dirUser); //Rename the archieve
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

//Rename a file
template<typename T>
void rename(T dirtemp, T dircamb)
{
    int newname;
    newname = rename(dirtemp.c_str(), dircamb.c_str()); //Renombra el archivo temp por el de user

    if (newname != 0)
        perror("Error al renombrar archivo.");
}

//Erase a file
template <typename T>
void borrar(T dir)
{
    if(remove(dir.c_str()) != 0) //Elimina un archivo
       perror("Error al borrar archivo!.");
    system("cls");
}
