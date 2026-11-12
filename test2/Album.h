#pragma once
#include <iostream>
#include <string>

using namespace std;

class Album {
protected:
    string* Title;
    string* Artist;
    int* ReleaseYear;
    static int AlbumCount;

public:
    Album();
    Album(string title, string artist, int year);
    Album(const Album& other);
    virtual ~Album();

    void SetTitle(string title);
    void SetArtist(string artist);
    void SetReleaseYear(int year);

    string GetTitle() const;
    string GetArtist() const;
    int GetReleaseYear() const;
    static int GetAlbumCount();

    virtual void show() const = 0;
    virtual void playSample() const = 0;
};

class ClassicAlbum : public Album {
private:
    std::string* Orchestra;

public:
    ClassicAlbum();
    ClassicAlbum(string title, string artist, int year, string orchestra);
    ClassicAlbum(const ClassicAlbum& other);
    ~ClassicAlbum() override;

    void SetOrchestra(string orchestra);
    string GetOrchestra() const;

    void show() const override;
    void playSample() const override;
};

class PopAlbum : public Album {
private:
    int* ChartPosition;

public:
    PopAlbum();
    PopAlbum(string title, string artist, int year, int chartPos);
    PopAlbum(const PopAlbum& other);
    ~PopAlbum() override;

    void SetChartPosition(int chartPos);
    int GetChartPosition() const;

    void show() const override;
    void playSample() const override;
};
