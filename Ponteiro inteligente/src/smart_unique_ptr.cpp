#include <iostream>
#include <memory>

using namespace std;

class Carro
{
private:
    int vel = 0;
public:
    int getVel(){
        return vel;
    }
    void setVel(int v){
        this->vel = vel;
    }
};

int main()
{
    unique_ptr<int> pnum(new int);
    *pnum = 10;
    cout << *pnum << " - " << &pnum << endl;

    unique_ptr<string> pStr (new string("Curso C++"));
    cout << *pStr << " - size " << pStr->size() << endl;

    unique_ptr<Carro> carro (new Carro());
    cout << "velocidade: " << carro->getVel() << endl;
}