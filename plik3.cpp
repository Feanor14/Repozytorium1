//role of friend function.
#include <iostream>
using namespace std;
class x
{
  protected:
  int x1;
  public:
  x(int a1):x1(a1){}
};
class y:public x
{
  private:
  int y1;
  public:
  y(int a1, int a2):x::x(a1),y1(a2){ }
  friend void disp(y&);
};
void disp(y &os)
{
    cout << "x1 = " << os.x1 << "  y1 = " << os.y1 << endl;
}

int main()
{
    y oop(12,24);
    disp(oop);
    return 0;
}
