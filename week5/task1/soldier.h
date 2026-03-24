enum class Rank
{
    Private,
    Corporal,
    Sergeant,
    Major
};

class Soldier
{
private:
    int healthPoints = 100;
    Rank rank;
    int love = 0;
    int bulletsLeft = 0;

public:
    Soldier() = default;
    Soldier(int healthPoints_, Rank rank_, int love_, int bulletsLeft_);

    void shootAt(Soldier &soldier);
    void getShot();
    int getHealthPoints();
    void increaseRank(Soldier &soldier);
    void getIncreased();
};