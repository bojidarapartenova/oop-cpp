#include "Playlist.h"
#include <iostream>

void Playlist::free()
{
    delete[] songs;
    songs = nullptr;
}

void Playlist::copyFrom(const Playlist &other)
{
    songs = new Song[other.count + 1];
    for (size_t i = 0; i < other.count + 1; i++)
    {
        songs[i] = other.songs[i];
    }
}

void Playlist::moveFrom(Playlist &&other) noexcept
{
    songs = other.songs;
    count = other.count;
    capacity = other.capacity;

    other.songs = nullptr;
    other.count = 0;
    other.capacity = 0;
}

Playlist::Playlist() : songs(nullptr), count(0), capacity(0) {}

Playlist::Playlist(size_t cap) : songs(new Song[cap]), count(0), capacity(cap) {}

Playlist::Playlist(const Playlist &other)
{
    copyFrom(other);
}

Playlist::Playlist(Playlist &&other)
{
    moveFrom(std::move(other));
}

Playlist &Playlist::operator=(const Playlist &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Playlist &Playlist::operator=(Playlist &&other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Playlist::~Playlist()
{
    free();
}

void Playlist::addSong(const Song &s)
{
    if (count == capacity)
    {
        size_t newCapacity = (capacity == 0) ? 2 : capacity * 2;
        Song *newSongs = new Song[newCapacity];
        for (size_t i = 0; i < count; i++)
        {
            newSongs[i] = songs[i];
        }
        delete[] songs;
        songs = newSongs;
        capacity = newCapacity;
    }
    songs[count] = s;
    count++;
}

void Playlist::addSong(Song &&s) noexcept
{
    if (count == capacity)
    {
        size_t newCapacity = (capacity == 0) ? 2 : capacity * 2;
        Song *newSongs = new Song[newCapacity];
        for (size_t i = 0; i < count; i++)
        {
            newSongs[i] = songs[i];
        }
        delete[] songs;
        songs = newSongs;
        capacity = newCapacity;
    }
    songs[count] = std::move(s);
    count++;
}

void Playlist::removeSong(size_t idx)
{
    for (size_t i = idx; i < count - 1; i++)
    {
        songs[i] = songs[i + 1];
    }
    count--;
}

Song &Playlist::operator[](size_t idx)
{
    return songs[idx];
}

const Song &Playlist::operator[](size_t idx) const
{
    return songs[idx];
}

size_t Playlist::getCount() const
{
    return count;
}

int Playlist::totalDuration() const
{
    int result = 0;
    for (size_t i = 0; i < count; i++)
    {
        result += songs[i].getDuration();
    }
    return result;
}
