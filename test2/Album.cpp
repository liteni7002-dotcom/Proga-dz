#include "Album.h"

using namespace std;

int Album::AlbumCount = 0;

int Album::GetAlbumCount() {
    return AlbumCount;
}

Album::Album() {
    Title = new string("Без названия");
    Artist = new string("Неизвестен");
    ReleaseYear = new int(2000);
    AlbumCount++;
}

Album::Album(string title, string artist, int year) {
    Title = new string(title);
    Artist = new string(artist);
    ReleaseYear = new int(year);
    AlbumCount++;
}

Album::Album(const Album& other) {
    Title = new string(*other.Title);
    Artist = new string(*other.Artist);
    ReleaseYear = new int(*other.ReleaseYear);
    AlbumCount++;
}

Album::~Album() {
    delete Title;
    delete Artist;
    delete ReleaseYear;
    AlbumCount--;
}

void Album::SetTitle(string title) { *Title = title; }
void Album::SetArtist(string artist) { *Artist = artist; }
void Album::SetReleaseYear(int year) { *ReleaseYear = year; }

string Album::GetTitle() const { return *this->Title; }
string Album::GetArtist() const { return *this->Artist; }
int Album::GetReleaseYear() const { return *this->ReleaseYear; }


ClassicAlbum::ClassicAlbum() : Album() {
    Orchestra = new string("Симфонический оркестр");
}

ClassicAlbum::ClassicAlbum(string title, string artist, int year, string orchestra)
    : Album(title, artist, year) {
    Orchestra = new string(orchestra);
}

ClassicAlbum::ClassicAlbum(const ClassicAlbum& other) : Album(other) {
    Orchestra = new string(*other.Orchestra);
}

ClassicAlbum::~ClassicAlbum() {
    delete Orchestra;
}

void ClassicAlbum::SetOrchestra(string orchestra) { *Orchestra = orchestra; }
string ClassicAlbum::GetOrchestra() const { return *this->Orchestra; }

void ClassicAlbum::show() const {
    cout << "Классический альбом. Название: " << GetTitle()
        << " Композитор: " << GetArtist()
        << " Год: " << GetReleaseYear()
        << " Оркестр: " << GetOrchestra() << endl;
}

void ClassicAlbum::playSample() const {
    cout << "Звучит торжественная увертюра из альбома '" << GetTitle()
        << "' в исполнении оркестра '" << GetOrchestra() << "'." << endl;
}

PopAlbum::PopAlbum() : Album() {
    ChartPosition = new int(10);
}

PopAlbum::PopAlbum(string title, string artist, int year, int chartPos)
    : Album(title, artist, year) {
    ChartPosition = new int(chartPos);
}

PopAlbum::PopAlbum(const PopAlbum& other) : Album(other) {
    ChartPosition = new int(*other.ChartPosition);
}

PopAlbum::~PopAlbum() {
    delete ChartPosition;
}

void PopAlbum::SetChartPosition(int chartPos) { *ChartPosition = chartPos; }
int PopAlbum::GetChartPosition() const { return *this->ChartPosition; }

void PopAlbum::show() const {
    cout << "Поп-альбом. Название: " << GetTitle()
        << " Исполнитель: " << GetArtist()
        << " Год: " << GetReleaseYear()
        << " Место в чарте: #" << GetChartPosition() << endl;
}

void PopAlbum::playSample() const {
    cout << "Играет танцевальный хит из альбома '" << GetTitle()
        << "' от " << GetArtist() << " (Топ-" << GetChartPosition() << " чартов)!" << endl;
}
