#include <iostream>

using namespace std;

//#define SHOW(X) cout << #X << X ;

// Элемент стека и очереди
struct Element {
  int value; // Значение элемента
  Element* next; // Указатель на следующий элемент
};



/*

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

*/
// очередь структура данных " первый пришел - первый вышел " FIFO


struct MyQueue {
  Element *head;
  Element *tail;
  int total=0;

  MyQueue():head(NULL),tail(NULL) {};


  void put(int value) {
    Element* QueueElement = new Element;
    QueueElement->value = value;
   // QueueElement->next = NULL;
        if(total == 0)  {
            head = QueueElement; tail =  QueueElement;
        } else {
        tail->next = QueueElement;
        }
   total++;
   }


  int get() {


  Element* firstQueue = head;
  int temp = firstQueue->value;
  head=head->next;
  if(head == NULL) tail = NULL;
  delete firstQueue;

  return temp;

  }


  };







int main()
{/*
  MyStack my;
  my.push(2);
  my.push(3);
  my.push(7);
  cout << "7 - " << my.pop() << endl;
  cout << "3 - " << my.pop() << endl;
  cout << "2 - " << my.pop() << endl;
*/
  cout << "Queue" << endl;
  MyQueue myq;
  myq.put(6);
  myq.put(3);
  myq.put(1);
 // myq.put(9); -< c 2мя работает с 3 мя нет
 // myq.put(10);
  cout << "6 - " << myq.get() << endl;
  cout << "3 - " << myq.get() << endl;
  cout << "1 - " << myq.get() << endl;
//   cout << "n - " << myq.get() << endl;












  return 0;
}
