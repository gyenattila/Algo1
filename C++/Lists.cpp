#include <iostream>

/**
  Egyirányú fejelemes lista struct
*/
struct E1
{
  int key;
  E1* next;

  E1(): next(0) { }
};

// Egyirányú fejelem nélküli lista kiírása
void printList(E1*);

// Egyirányú fejelemes lista kiírása
void printHeadList(E1*);

// Fejelem nélküli listában való keresés
E1* findInS1L(E1*, int);

// Fejelem nélküli listába való beillesztés
void insertIntoS1L(E1* &, int);

// Fejelemes listába való beillesztés
void insertIntoH1L(E1* &, int);

// Fejelem nélküli listából való törlés
void deleteFromS1L(E1* &, int);

// Fejelem nélküli lista megfordítása
void reverseList(E1* &);

// Fejelemes lista szétbontása paritás alapján
E1* seperateH1L(E1*);

// Fejelem nélküli lista generálása a prímszitához
E1* generateList(int);

// Prímszita
E1* primeList(int);

int main()
{
    
  E1* ls = new E1();
  ls->key = 1;
  insertIntoS1L(ls, 2);
  insertIntoS1L(ls, 38);
  insertIntoS1L(ls, 3);
  insertIntoS1L(ls, 15);
  insertIntoS1L(ls, 5);

  E1* hls = new E1();
  insertIntoH1L(hls, 8);
  insertIntoH1L(hls, 7);
  insertIntoH1L(hls, 50);
  insertIntoH1L(hls, 4);
  insertIntoH1L(hls, 55);

  // beillesztés
  std::cout << "Az ls lista:" << std::endl;
  printList(ls);

  // törlés
  int num = 15;
  deleteFromS1L(ls, num);
  std::cout << "Az ls lista (" << num << ") törlés után:" << std::endl;
  printList(ls);

  // megdordítás
  reverseList(ls);
  std::cout << "Az ls lista megfordítása:" << std::endl;
  printList(ls);

  // szétfűzés
  std::cout << "Az eredeti hls lista:" << std::endl;
  printHeadList(hls);

  E1* hls2 = seperateH1L(hls);

  std::cout << "A módosított hls lista:" << std::endl;
  printHeadList(hls);
  std::cout << "A hls2 lista:" << std::endl;
  printHeadList(hls2);

  // prímszita
  num = 10;
  E1* pls = primeList(num);
  std::cout << "A prímszita lista" << '(' << num <<  "):" << std::endl;
  printList(pls); 

  return 0;
}

/**
  Egyirányú fejelem nélküli lista kiírása
*/
void printList(E1* L)
{
  E1* p = L;

  while(p != nullptr)
  {
    std::cout << p->key << ' ';
    p = p->next;
  }
  std::cout << std::endl << std::endl;
}

/**
  Egyirányú fejelemes lista kiírása
*/
void printHeadList(E1* L)
{
  E1* p = L->next;

  while(p != nullptr)
  {
    std::cout << p->key << ' ';
    p = p->next;
  }
  std::cout << std::endl << std::endl;
}

/**
  Fejelem nélküli listában való keresés
*/
E1* findInS1L(E1* L, int dataToFind)
{
  E1* p = L;

  while(p != nullptr && p->key < dataToFind)
    p = p->next;

  return p != nullptr && p->key == dataToFind ? p : nullptr;
}

/**
  Fejelem nélküli listába való beillesztés
*/
void insertIntoS1L(E1* &L, int dataToInsert)
{
  E1* pe = nullptr;
  E1* p = L;

  while(p != nullptr && p->key < dataToInsert)
  {
    pe = p;
    p = p->next;
  }

  if(p == nullptr || p->key != dataToInsert)
  {  
    E1* q = new E1();
    q->key = dataToInsert;
    q->next = p;

    pe == nullptr ? L = q : pe->next = q;
  }
}

/**
  Fejelemes listába való beillesztés
*/
void insertIntoH1L(E1* &L, int dataToInsert)
{
  E1* pe = L;
  E1* p = L->next;

  while(p != nullptr && p->key < dataToInsert)
  {
    pe = p;
    p = p->next;
  }

  if(p == nullptr || p->key != dataToInsert)
  {
    E1* q = new E1();
    q->key = dataToInsert;
    q->next = p;
    pe->next = q;
  }
}

/**
  Fejelem nélküli listából való törlés
*/
void deleteFromS1L(E1* &L, int dataToDelete)
{
  E1* pe = nullptr;
  E1* p = L;

  while(p != nullptr && p->key < dataToDelete)
  {
    pe = p;
    p = p->next;
  }

  if(p != nullptr && p->key == dataToDelete)
  {
    p == nullptr ? L = p->next : pe->next = p->next;
    delete p;
  }
}

/**
  Fejelem nélküli lista megfordítása
*/
void reverseList(E1* &L)
{
  E1* p = L;
  L = nullptr;

  while(p != 0)
  {
      E1* q = p;
      p = p->next;
      q -> next = L;
      L = q;
  }
}

/**
  Fejelemes lista szétbontása paritás alapján
*/
E1* seperateH1L(E1* L1)
{
  E1* L2 = new E1();
  E1* u = L2;

  E1* pe = L1;
  E1 *p = L1->next;

  while(p != nullptr)
  {
    if(p->key % 2 == 0)
    {
      pe = p;
      p = p->next;
    }
    else
    {
      pe->next = p->next;
      u ->next = p;
      p ->next = nullptr;
      u = p;
      p = pe->next;
    }
  }
  return L2;
}

/**
  Fejelem nélküli lista generálása a prímszitához
*/
E1* generateList(int n)
{
  E1* L = nullptr;

  for(int i = n; i > 1; --i)
  {
    E1* p = new E1();
    p->key = i;
    p->next = L;
    L = p;
  }
  return L;
}

/**
  Prímszita
*/
E1* primeList(int n)
{
  E1* L = generateList(n);
  E1* p = L;

  while(p != nullptr)
  {
    E1* qe = p;
    E1* q = p->next;

    while(q != nullptr)
    {
      if(q->key % p->key == 0)
      {
        qe->next = q->next;
        delete q;
        q = qe->next;
      }
      else
      {
        qe = q;
        q = q->next;
      }
    }
    p = p->next;
  }
  return L;
}
