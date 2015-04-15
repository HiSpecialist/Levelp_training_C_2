#include <iostream>

using namespace std;

//#define SHOW(X) cout << #X << X ;

// Элемент стека и очереди
struct Element {
  int value; // Значение элемента
  Element* next; // Указатель на следующий элемент
};





// стек структура данных " последним пришел - первым вышел " LIFO
struct MyStack {

  Element* top; // вершина стека

  MyStack() : top(NULL) {}  // конструктор

  int numberstack=0;

  void push(int value) {

    numberstack++;

    Element* curElementS = new Element;

    curElementS->value = value;

    curElementS->next=top;

    top = curElementS;

  }

  // Взять значение с вершины стека
  int pop() {


    if( numberstack != 0 ){

    numberstack--;

    int resultat = top->value;

    Element* e = top;

    top = top->next;

    delete e;

    return resultat;
    }
    else {  cout << "стек пуст"<< endl; }


  }
};


// очередь структура данных " первый пришел - первый вышел " FIFO


struct ElementQueue {
  int value; // Значение элемента
  ElementQueue *next,*last;// Указатель на следующий элемент
};

struct Queue {
  ElementQueue* head; // "Голова" - начало очереди
  ElementQueue* tail; // "Хвост" - конец очереди
  int total=0;
  // Конструктор
  Queue() : head(NULL), tail(NULL) {};

  void put(int value) {
    // Создаём новый элемент
    ElementQueue* newelement = new ElementQueue;
    newelement->value = value;
    total++;

    if(total == 1) {
    head=tail=newelement;
    newelement->last = NULL;// del
    newelement->next = NULL;// del
    }
    if(total > 1)  {
    newelement->next=tail;
    tail->last=newelement;
    tail=newelement;
    }
    }

  // Забрать первый элемент из очереди
  int get() {
  total--;
  if (total >= 0) {
  ElementQueue *fistelement = head;
  int temp = fistelement->value;

  if (total > 0)  {
  head = fistelement->last;
  head->next = NULL;
  }

  if (total == 0)  {
  head = NULL;
  tail = NULL;
  }

  delete fistelement;
  return temp;

  } else {cout << "Она уже пуста!" << endl; return 0; }

  }






};









int main()
{
  MyStack my;
  cout << "Stack" << endl;
  my.push(2);
  my.push(3);
  my.push(7);
  cout << "7 - " << my.pop() << endl;
  cout << "3 - " << my.pop() << endl;
  cout << "2 - " << my.pop() << endl;

  cout << "Queue" << endl;
  Queue myq;
  myq.put(6);
  myq.put(3);
  myq.put(1);
  myq.put(10);
  myq.put(10);
  myq.put(25);
  myq.put(25);
  myq.put(25);

  cout << "6 - " << myq.get() << endl;
  cout << "3 - " << myq.get() << endl;
  cout << "1 - " << myq.get() << endl;
  cout << "10- " << myq.get() << endl;
  cout << "10- " << myq.get() << endl;
  cout << "25- " << myq.get() << endl;
  cout << "25- " << myq.get() << endl;
  cout << "25- " << myq.get() << endl;
  myq.put(100);
  myq.put(1000);
  cout << "100-" << myq.get() << endl;
 //cout << "1000" << myq.get() << endl;
 // cout << "----" << myq.get() << endl;
  return 0;
}
