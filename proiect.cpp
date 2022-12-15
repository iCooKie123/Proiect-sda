#include <iostream>
using namespace std;


//structuri de date
struct numar{
    int v; // valoarea din lista
    numar *urm; // legatura catre urmatorul element din lista
};

//functie de adaugare in stiva
numar *adaugare_in_stiva(numar *cap, int a)
{
    numar *c;
    c=new numar;
    c->v=a;
    c->urm=cap;
    cap=c; // noul capat al stivei
    return cap;
}



//functii
void parcurgere_stiva(numar *cap)
{
    numar *c;
    if (cap == NULL)
        cout<<"Stiva este vida!"<<endl;
    else
    {
        c=cap;
        while (c != NULL)
        {

          
            cout<<c->v<<endl;
            c=c->urm;
          
        }
        cout<<endl;
    }

}

void parcurgere_stiva_baze(numar *cap)
{
    numar *c;
    if (cap == NULL)
        cout<<"Stiva este vida!"<<endl;
    else
    {
        c=cap;
        while (c != NULL)
        {
            if(c->v >9){
                char lit ='A'+(c->v-10);
                cout<< lit<<" ";
            }
            else
                cout<<c->v<<" ";
            c=c->urm;
        }
    }

}


int main() {
  
  int op=1;
  do{
    cout<<"1.Descompunerea unui numar in fctori primi folosind o stiva"<<endl;
    cout<<"2.Trecerea din baza 10 in baza b€{2,16}"<<endl;
    cout<<"0. Incheiere program!"<< endl;
    cout<<"Alege optiune: "; cin>>op;

    switch (op)
    {
    case 1:
    {
      int nr; // numarul care va fi descompus
      numar *cap; // capatul stivei
      cap=NULL;
      cout<<"Introduceti numarul: "; cin>>nr;
      while (nr != 1)
      {
          for (int i=2; i<=nr; i++)
          {
              if (nr % i == 0)
              {
                  cap=adaugare_in_stiva(cap, i);
                  nr=nr/i;
                  break;
              }
          }
      }
      cout<<"Descompunerea in factori primi este: "<<endl;
      parcurgere_stiva(cap);
      break;
    }
    case 2:
    {
      int nr, baza;
      int x=1;
      cout<<"Introduceti numarul: "; cin>>nr;
      while (x != 0)
      {
          cout<<"Introduceti baza: "; cin>>baza;
          if (baza >= 2 && baza <= 16)
              x=0;
          else
              cout<<"Baza trebuie sa fie intre 2 si 16!"<<endl;
      }
      numar *cap; // capatul stivei
      cap=NULL;
      while (nr != 0)
      {
          cap=adaugare_in_stiva(cap, nr % baza);
          nr=nr/baza;

      }
      cout<<"Numarul"<<nr<<" in baza "<<baza<<" este: ";
      parcurgere_stiva_baze(cap);
      cout<<endl;
      break;
    }
    
    default:
      break;
    }
  }while (op !=0); // end do programp rincipal

}

