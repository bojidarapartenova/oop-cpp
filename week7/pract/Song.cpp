#include "Song.h"
#include <iostream>

void Song::free()
{
    delete[] title;
    delete[] artist;

    title = nullptr;
    artist = nullptr;
}

void Song::copyFrom(const Song &other)
{
    duration = other.duration;

    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);

    artist = new char[strlen(other.artist) + 1];
    strcpy(artist, other.artist);
}

void Song::moveFrom(Song &&other) noexcept
{
    title = other.title;
    artist = other.artist;
    duration = other.duration;

    other.title = nullptr;
    other.artist = nullptr;
    other.duration = 0;
}

void Song::setTitle(const char *title_)
{
    if (!title_ || title_ == title)
    {
        return;
    }
    delete[] title;

    title = new char[strlen(title_) + 1];
    strcpy(title, title_);
}

void Song::setArtist(const char *artist_)
{
    if (!artist_ || artist_ == artist)
    {
        return;
    }
    delete[] artist;

    artist = new char[strlen(artist_) + 1];
    strcpy(artist, artist_);
}

void Song::setDuration(int duration_)
{
    if (duration_ <= 0)
    {
        return;
    }
    duration = duration_;
}

Song::Song() : title(nullptr), artist(nullptr), duration(0) {}

Song::Song(const char *title, const char *artist, int duration)
{
    setTitle(title);
    setArtist(artist);
    setDuration(duration);
}

Song::Song(const Song &other)
{
    copyFrom(other);
}

Song::Song(Song &&other) noexcept
{
    moveFrom(std::move(other));
}

Song &Song::operator=(const Song &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Song &Song::operator=(Song &&other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Song::~Song()
{
    free();
}
