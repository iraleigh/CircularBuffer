#include <iostream>
#include <vector>

using namespace std;

class circular_buffer {
private:
  int size;
  vector<int> buffer;
  int read_p {0};
  int write_p {0};
public:
  circular_buffer(int n) : size(n), buffer(n) {}

  int read() {
    int item = buffer[read_p++];
    read_p %= size;
    return item;
  }

  void write(int item) {
    buffer[write_p++] = item;
    write_p %= size;
  }
};

int main() {
  circular_buffer buffer { 5 };
  
  for (int i = 0; i < 11; i++) {
    buffer.write(i);
  }

  // [0,0,0,0,0]
  // [0,1,0,0,0]
  // [0,1,2,0,0]
  // [0,1,2,3,0]
  // [0,1,2,3,4]
  // [5,1,2,3,4]
  // [5,6,2,3,4]
  // [5,6,7,3,4]
  // [5,6,7,8,4]
  // [5,6,7,8,9]
  // [10,6,7,8,9]

  cout << buffer.read() << endl;
  cout << buffer.read() << endl;
}