#include <iostream>
#include <vector>
using namespace std;
int nrp,nrc;
class Object
{
public:
    Object() {};
    virtual ~Object() {};
    virtual void display() = 0;
};

class ObArray : public Object
{
    ///Object **p; /// vector de pointeri
    vector <Object*> p;
    int size; /// numar de elemente la un moment dat
    int grows; /// increment de creştere a dimensiunii
    int dimens; /// dimensiune vector

public:
    ObArray(int grows, int dimens,int size=0);///Constructor
    ~ObArray()///Destructor
    {
        cout<<"\nDestructor ObArray\n";
        RemoveAll();
    };
    void RemoveAll();///Elimina toate obiectele din vector
    int getSize(); /// Intoarce numarul de elemente din vector. ok
    int add(Object* x); ///Adauga un element la vector.
    int insertAt(int i, Object *x);///Insereaza un element pe // o pozitie data
    int removeAt(int i); ///Elimina elementul de pe pozitia i
    Object* getAt(int i); ///Intoarce elementul de la pozitia i
    void display();/// Afisare elementelor din tablou. ok

};

class Punct : public Object      ///PUNCT
{
    float x,y;
public:
    friend istream & operator >> (istream &, Punct &);
    friend ostream & operator << (ostream &, Punct &);
    Punct operator = (Punct&);
    void display()
    {
        cout<<"\nPunct display\n";
        for (int i=0; i<nrp; i++)
            cout<<this[i];
    }
    Punct() {};
    Punct(float x,float y)
    {
        this->x=x;
        this->y=y;
    }
    Punct(const Punct &ob)
    {
        this ->x = ob.x;
        this ->y = ob.y;
    }
    ~Punct()
    {
        //cout<<"\nDestructor Punct\n";
        this ->x =0;
        this ->y =0;
    }
};

class Complex : public Object    ///COMPLEX
{
    int re,im;
public:
    friend istream & operator >> (istream &, Complex &);
    friend ostream & operator << (ostream &, Complex &);
    Complex operator = (Complex&);
    void display()
    {
        cout<<"\nComplex display\n ";
        for (int i=0; i<nrc; i++)
            cout<<this[i];
    }
    Complex() {};
    Complex(int r,int i)
    {
        this->re=r;
        this->im=i;
    }
    Complex(const Complex &ob)
    {
        this ->re = ob.re;
        this ->im = ob.im;
    }
    ~Complex()
    {
        this ->re =0;
        this ->im =0;
    }
};

ObArray::ObArray(int grows, int dimens,int size) : size(size),grows(grows), dimens(dimens) ///CONSTR
{
    ///p=new Object*[dimens];
    ///??
}
int ObArray::add(Object* x) ///ADD
{
    p.push_back(x);
    // size++;
}
int ObArray::insertAt(int i, Object* x)
{
    p.insert(p.begin()+i,x);
    //size++;
}
int ObArray::removeAt(int i)
{
    p.erase(p.begin()+i);
    // size--;
}
void ObArray::RemoveAll()
{
    p.erase(p.begin(),p.end());
    // size=0;
}
Object * ObArray::getAt(int i)
{
    return p[i];
}

void ObArray::display()
{
    cout<<"\ndisplay arr\n";
    for (int i=0; i<p.size(); i++)
        p[i]->display();
}

int ObArray::getSize()
{
    ///return size;
    return p.size();
}

istream & operator >> (istream & in,  Complex & c)///Input COMPLEX
{
    cout<<"Citeste Partea Reala: ";
    in>>c.re;
    cout<<"Citeste Partea Imaginara:";
    in>>c.im;
    cout<<'\n';

    return in;
}
ostream & operator << (ostream & out,  Complex & c)///Output COMPLEX
{
    out<<"Partea Reala: "<<c.re<<'\n';
    out<<"Partea imaginara: "<<c.im<<'\n';

    return out;
}
istream & operator >> (istream & in,  Punct & p)///Input PUNCT
{
    cout<<"Citeste coordonatele\n";
    cout<<"x = ";
    in>>p.x;
    cout<<"y = ";
    in>>p.y;

    return in;
}
ostream & operator << (ostream & out,  Punct & p)///Output PUNCT
{
    out<<"Punctul are coord: "<<p.x<<" "<<p.y<<'\n';
    return out;
}
Complex Complex::operator=(Complex&a)
{
    this->re = a.re;
    this->im = a.im;
}
Punct Punct::operator=(Punct&a)
{
    this->x = a.x;
    this->y = a.y;
}

int main()
{
    int i;
    /*Complex b,d;
    cin>>b;
    Complex a(b);
    d=b;
    cout<<a<<b<<d<<'\n';

    Punct p2,p3;
    cin>>p2;
    Punct p1(p2);
    p3=p2;
    cout<<p1<<p2<<p3<<'\n';*/

    Complex c[2]= {{1,2},{3,4}};
    nrc=sizeof(c)/sizeof(c[0]);///global??
    Punct pct[3]= {{4.1,6.3},{6,0},{9.9,1}};
    nrp=sizeof(pct)/sizeof(pct[0]);

    int x=1,y=5,z=0;
    ObArray ob(x,y,z);///???

    ob.add(c);
    ob.add(pct);
    ob.insertAt(1,c);

    cout<<"\nSize= "<<ob.getSize();
    ob.display();

    cout<<"\nGetAt:\n";
    ob.getAt(2)->display();

    ob.removeAt(1);
    cout<<"\nSize= "<<ob.getSize();
    ob.display();

    ob.RemoveAll();
    cout<<"\nSize= "<<ob.getSize();

    return 0;
}
