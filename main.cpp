#include <iostream>
#include "Deques.h"

using namespace std;
int main()
{
    Deques<float> dq1;
    //Testing implementation of empty() function
      cout << dq1.empty() << " - 1" << endl;
    //Testing insert from front and back into dq1
      dq1.insert_front(42);
      dq1.insert_back(103);
      dq1.insert_back(216);
    //Checking proper insertion into front and back and size of queue
      cout << dq1.peek_front() << " - 42" << endl;
      cout << dq1.peek_back() << " - 216" << endl;
      cout << dq1.size() << " - 3" << endl;
    //Testing copy constructor and assignment operator
      Deques<float> dq2(dq1);
      Deques<float> dq3;
      dq3 = dq1;
    //Testing removal operations
      cout << dq1.remove_front() << " - 42" << endl;
      cout << dq1.remove_back() << " - 216" << endl;
    //Testing proper insertion and front and back of the copy constructor and assignment operator
      cout << dq2.peek_front() << " - 42" << endl;
      cout << dq2.peek_back() << " - 216" << endl;
      cout << dq3.peek_front() << " - 42" << endl;
      cout << dq3.peek_back() << " - 216" << endl;
    return 0;
}
