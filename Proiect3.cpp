#include <iostream>
#include <vector>
using namespace std;

const int NR_LUNI=3;
class Farmacie_online;

class Base
{
protected:
    int id;
public:
    Base() {};
    ~Base() {};
    virtual void afisare() = 0;
};

class Farmacie : public Base
{
protected:
    float profit[13];
    int angajati;
    string denumire;
public:
    Farmacie()
    {
        angajati=0;
        fill(profit,profit+NR_LUNI,0);
    };
    ~Farmacie() {};
    Farmacie operator= (Farmacie &);
    friend istream & operator >> (istream &, Farmacie &);
    friend ostream & operator << (ostream &, Farmacie &);
    void afisare();
};

class Farmacie_online : public Farmacie
{
protected:
    string adresa_web;
    int vizitatori;
    float discount;
public:
    Farmacie_online() {};
    ~Farmacie_online() {};
    Farmacie_online operator= (Farmacie_online &);
    friend istream & operator >> (istream &, Farmacie_online &);
    friend ostream & operator << (ostream &, Farmacie_online &);
    void afisare();
    int getViz()
    {
        return vizitatori;
    }
};

template <typename T>class GestionareFarmacii
{
private:
    int index;
    vector <T*> v;
public:
    GestionareFarmacii()
    {
        index=0;
    };
    ~GestionareFarmacii() {};
    GestionareFarmacii operator += (T &);
    void afisareLant();
};

template<>class GestionareFarmacii<unsigned>
{
    int viz_total;
public:
    GestionareFarmacii()
    {
        viz_total=0;
    }
    void addOnline (Farmacie_online &ob)
    {
        viz_total+=ob.getViz();
    }
    void afisViz()
    {
        cout<<"Numarul total de vizitatori este: "<<viz_total;
    }
};

template <typename T>
GestionareFarmacii<T> GestionareFarmacii<T>:: operator+=(T &ob)
{
    index++;
    v.push_back(&ob);
    return *this;
}

template <typename T>
void GestionareFarmacii<T>:: afisareLant()///afisare
{
    for (int i=0; i<index; i++)
    {
        cout<<"Farmacia "<<i<<'\n';
        v[i]->afisare();
        cout<<'\n';
    }
}

/*void GestionareFarmacii<unsigned>::sumViz(GestionareFarmacii &ob)
{
    for (int i=0;i<ob.index;i++)
    {
        viz_total+=ob.v[i]->getViz();
    }
}*/
///Cum transmit ca parametru clasa template de baza ca sa accesez lantul de farmacii?

void Farmacie::afisare()
{
    try   ///Exceptie
    {
        if (angajati<=0)
            throw angajati;
        cout<<*this;
    }
    catch (int x)
    {
        cout<<"Eroare - Farmacia are "<<x<<" angajati";
    }
}
void Farmacie_online::afisare()
{
    cout<<*this<<'\n';
}
istream & operator >> (istream & in,  Farmacie & F)
{

    cout<<"CiafisareLante - Denumirea, Nr Angajati, ID, Profitul/Luna: ";
    in>>F.denumire>>F.angajati>>F.id;
    for (int i=1; i<=NR_LUNI; i++)
        in>>F.profit[i];

    return in;
}
istream & operator >> (istream & in, Farmacie_online & Fo)
{
    cout<<"CiafisareLante - Adresa Web, Denumire, Nr Vizitatori, Angajati, Discount, ID, Profitul/Luna: ";
    in>>Fo.adresa_web>>Fo.denumire>>Fo.vizitatori>>Fo.angajati>>Fo.discount>>Fo.id;
    for (int i=1; i<=NR_LUNI; i++)
        in>>Fo.profit[i];
    return in;
}
ostream & operator << (ostream & out, Farmacie & F)
{
    out<<"Denumire: "<<F.denumire<<'\n';
    out<<"Angajati: "<<F.angajati<<'\n';
    out<<"ID: "<<F.id<<'\n';;
    for (int i=1; i<=NR_LUNI; i++)
        out<<F.profit[i]<<" profit pe luna "<<i<<'\n';
    return out;
}
ostream & operator << (ostream & out, Farmacie_online & Fo)
{
    Farmacie * pF;
    pF=dynamic_cast<Farmacie*>(&Fo);   ///Dyamic Cast
    cout<<*pF;
    out<<"Adresa Web: "<<Fo.adresa_web<<'\n';
    out<<"Vizitatori: "<<Fo.vizitatori<<'\n';
    out<<"Discount: "<<Fo.discount<<'\n';
    return out;
}

Farmacie Farmacie:: operator=(Farmacie &F)
{
    this->angajati=F.angajati;
    this->denumire=F.denumire;
    this->id=F.id;
    for (int i=1; i<=NR_LUNI; i++)
        this->profit[i]=F.profit[i];
    return *this;
}
Farmacie_online Farmacie_online:: operator=(Farmacie_online &Fo)
{
    Farmacie * pF, * pThis; ///Dynamic Cast
    pF=dynamic_cast<Farmacie*>(&Fo);
    pThis=dynamic_cast<Farmacie*>(this);
    (*pThis)=(*pF);
    this->discount=Fo.discount;
    this->vizitatori=Fo.vizitatori;
    this->adresa_web=Fo.adresa_web;
    return *this;
}
int main()
{
    Farmacie x,z;
    Farmacie_online y,w;
    cin>>x;
    z=x;
    z.afisare(); ///Farmacie

    /*cin>>y;
    w=y;
    w.afisare();*/ ///Farmacie online

    /*  GestionareFarmacii <Farmacie> Tf;
      cin>>x;
      cin>>y;
      Tf+=x;
      Tf+=y;
      Tf.afisareLant();*/   ///Template

    /*Farmacie_online a,b; 
    cin>>a>>b;
    GestionareFarmacii<unsigned> TSp;
    TSp.addOnline(a);
    TSp.addOnline(b);
    TSp.afisViz();*/       ///Specializare
}

