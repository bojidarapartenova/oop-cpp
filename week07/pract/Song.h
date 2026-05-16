class Song
{
private:
    char *title;
    char *artist;
    int duration;

    void free();
    void copyFrom(const Song &other);
    void moveFrom(Song &&other) noexcept;

public:
    Song();
    Song(const char *title, const char *artist, int duration);
    Song(const Song &other);
    Song(Song &&other) noexcept;
    Song &operator=(const Song &other);
    Song &operator=(Song &&other) noexcept;
    ~Song();

    const char *getTitle() const;
    const char *getArtist() const;
    int getDuration() const;

    void setTitle(const char *title_);
    void setArtist(const char *artist_);
    void setDuration(int duration_);
};