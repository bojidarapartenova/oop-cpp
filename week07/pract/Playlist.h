#include "Song.h"
#include <cstddef>

class Playlist
{
private:
    Song *songs;
    size_t count;
    size_t capacity;

    void free();
    void copyFrom(const Playlist &other);
    void moveFrom(Playlist &&other) noexcept;

public:
    Playlist();
    Playlist(size_t cap = 8);
    Playlist(const Playlist &other);
    Playlist(Playlist &&other);
    Playlist &operator=(const Playlist &other);
    Playlist &operator=(Playlist &&other);
    ~Playlist();

    void addSong(const Song &s);
    void addSong(Song &&s) noexcept;
    void removeSong(size_t idx);
    Song &operator[](size_t idx);
    const Song &operator[](size_t idx) const;
    size_t getCount() const;
    int totalDuration() const;
    void sortByDuration();
    void print() const;
};