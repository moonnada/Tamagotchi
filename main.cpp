#include <iostream>
#include <string>

using namespace std;

class Pet
{
public:
    Pet(string nm, int initialHealth);
    void eat(int amt);
    void play();
    string name() const;
    int health() const;
    bool alive() const;
private:
    string m_name;
    int m_health;
};

// Initialize the state of the pet
Pet::Pet(string nm, int initialHealth)
{
    m_name = nm;
    m_health = initialHealth;
}

void Pet::eat(int amt)
{
    if (amt < 0)
        return;
    m_health+=amt;
    // TODO: Increase the pet's health by the amount
}

void Pet::play()
{
    m_health-=1;// TODO: Decrease pet's health by 1 for the energy consumed
}

string Pet::name() const
{
    // TODO: Return the pet's name.  Delete the following line and
    // replace it with the correct code.
    return m_name;
    
}

int Pet::health() const
{
    // TODO: Return the pet's current health level.  Delete the
    // following line and replace it with the correct code.
    return m_health;
}

bool Pet::alive() const
{
    if (m_health > 0)
        return true;
    else
        return false;// TODO: Return whether pet is alive.  (A pet is alive if
    // its health is greater than zero.)  Delete the following
    // line and replace it with the correct code.
    
}

/////////
// Do not change any code below this point
/////////

void reportStatus(const Pet* p)
{
    cout << p->name() << " has health level " << p->health();
    if ( ! p->alive())
        cout << ", so has died";
    cout << endl;
}

void careFor(Pet* p, int d)
{
    if ( ! p->alive())
    {
        cout << p->name() << " is still dead" << endl;
        return;
    }
    
    // Every third day, you forget to feed your pet
    if (d % 3 == 0)
        cout << "You forgot to feed " << p->name() << endl;
    else
    {
        p->eat(1);  // Feed the pet one unit of food
        cout << "You fed " << p->name() << endl;
    }
    
    p->play();
    reportStatus(p);
}

int main()
{
    Pet* myPets[2];
    myPets[0] = new Pet("Fluffy", 2);
    myPets[1] = new Pet("Frisky", 4);
    for (int day = 1; day <= 9; day++)
    {
        cout << "======= Day " << day << endl;
        for (int k = 0; k < 2; k++)
            careFor(myPets[k], day);
    }
    cout << "=======" << endl;
    for (int k = 0; k < 2; k++)
    {
        if (myPets[k]->alive())
            cout << "Animal Control has come to rescue "
            << myPets[k]->name() << endl;
        delete myPets[k];
    }
}
