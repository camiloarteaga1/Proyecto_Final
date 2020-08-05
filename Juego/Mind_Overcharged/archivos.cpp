#include "archivos.h"

Archivos::Archivos()
{

}

//Writes into a file line by line
void Archivos::escribir(string dir, string txt)
{
    ofstream archivo;
    archivo.open(dir, ios::app);
    if (archivo.fail()){
        //qDebug()<< "No se pudo abrir el archivo";
        exit(1);
    }

    archivo << txt << "\n";
    archivo.close();
}

//Rename a file
void Archivos::renome(string dirtemp, string dircamb)
{
    int newname;
    newname = rename(dirtemp.c_str(), dircamb.c_str()); //Renames the temp file with the user's file name

    if (newname != 0)
        perror("Error al renombrar archivo.");
}

//Erase a file
void Archivos::borrar(string dir)
{
    if(remove(dir.c_str()) != 0) //Deletes a file
       perror("Error al borrar archivo!.");
    system("cls");
}
