#include <iostream>
using namespace std;

class PersonalComputer{
public:
    virtual unsigned int calCost() = 0;
    virtual void description() = 0;
};
class Laptop: public PersonalComputer{
public:
    ~Laptop(){

    }
    unsigned int calCost(){
        return 12000;
    }
    void description(){
        cout <<  "You are buy a Laptop!";
    }
};
class Desktop: public PersonalComputer{
public:
    ~Desktop(){}
    unsigned int calCost(){
        return 35000;
    }
    void description(){
        cout <<  "You are buy a Desktop!";
    }
};
class CdDrive: public PersonalComputer{
private:
    PersonalComputer* pc;
public:
    CdDrive(PersonalComputer *pc){
        this->pc = pc;
    }
    unsigned int calCost(){
        return 100 + pc->calCost();
    }
    void description(){
        pc->description();
        cout << endl << "WITH CD-ROM";
    }
};
class Monitor: public PersonalComputer{
private:
    PersonalComputer* pc;
public:
    Monitor(PersonalComputer *pc){
        this->pc = pc;
    }
    unsigned int calCost(){
        return 9500 + pc->calCost();
    }
    void description(){
        pc->description();
        cout << endl << "WITH LED Monitor";
    }
};
int main()
{
    PersonalComputer* pc = new Desktop();
    pc = new CdDrive(pc);
    pc = new Monitor(pc);
    pc->description();
    cout << endl << "COST: " << pc->calCost() << endl;
}