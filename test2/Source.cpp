#include "Album.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Кол-во объектов до создания: " << Album::GetAlbumCount() << endl;

    cout << "ПОЗДНЕЕ СВЯЗЫВАНИЕ" << endl;
    cout << "Выберите тип альбома для создания:\n1 - Классический альбом\n2 - Поп-альбом\nВаш выбор: ";
    int choice;
    cin >> choice;

    Album* userAlbum = nullptr;

    if (choice == 1) {
        userAlbum = new ClassicAlbum("Времена года", "Антонио Вивальди", 1725, "Берлинский филармонический");
    }
    else {
        userAlbum = new PopAlbum("Honeymoon", "Lana Del Ray", 2015, 1);
    }

    cout << "\nДемонстрация полиморфных методов выбранного объекта:" << endl;
    userAlbum->show();
    userAlbum->playSample();
    cout << "Текущее кол-во объектов: " << Album::GetAlbumCount() << endl << endl;

    cout << "РАННЕЕ СВЯЗЫВАНИЕ" << endl;

    ClassicAlbum* classicObj = new ClassicAlbum;

    classicObj->SetTitle("Лебединое озеро");
    classicObj->SetArtist("П.И. Чайковский");
    classicObj->SetReleaseYear(1877);
    classicObj->SetOrchestra("Большой театр");

    PopAlbum* popObj = new PopAlbum("I Love You", "The Neigbourhood", 2013, 4);
    
    popObj->SetChartPosition(3);

    cout << "\nДемонстрация методов ClassicAlbum:" << endl;
    classicObj->show();
    classicObj->playSample();

    cout << "\nДемонстрация методов PopAlbum:" << endl;
    popObj->show();
    popObj->playSample();

    cout << "\nВсего объектов в программе: " << Album::GetAlbumCount() << endl;

    delete userAlbum;
    delete popObj;
    delete classicObj;

    cout << "Кол-во объектов после удаления: " << Album::GetAlbumCount() << endl;

    return 0;
}
