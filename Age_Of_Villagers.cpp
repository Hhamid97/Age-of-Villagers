#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

class Graphic {
public:
  virtual void draw() const = 0;
  virtual void remove(Graphic *g) {}
  virtual void add(Graphic *g) {}
  virtual void getChild(int) {}
  virtual ~Graphic() {}
};

class Line : public Graphic {
public:
  void draw() const {
    cout << "----------\n";
  }
};

class Strip : public Graphic {
public:
  void draw() const {
    cout << "##########\n";
  }
};

class Zigzag : public Graphic {
public:
  void draw() const {
    cout << "_-_-_-_-_-_\n";
  }
};

class Lineup : public Graphic {
public:
  void draw() const {
    cout << " |   |\n |   |\n |   |\n |   |\n";
  }
};

class Rectangle : public Graphic {
public:
  void draw() const {
    cout << "\n-------\n|     |\n|     |\n|     |\n|     |\n-------\n";
  }
};

class Circle : public Graphic {
public:
  void draw() const {
    cout << "  ***\n *   *\n*     *\n *   *\n  ***\n";
  }
};

class Triangle : public Graphic {
public:
  void draw() const {
    cout << "\n   *\n  * *\n *   *\n*******";
  }
};

// Composite
class Picture : public Graphic {
public:
  void draw() const {
    // for each element in gList, call the draw member function
    for_each(gList.begin(), gList.end(), mem_fun(&Graphic::draw));
  }

  void add(Graphic *aGraphic) {
    gList.push_back(aGraphic);
  }

private:
  vector<Graphic*> gList;
};

int main()
{
  cout<< "Primary Objects:\n";
  cout<< "line:\n";
  Line line;
  line.draw();
  cout<< "Line-Upwards:\n";
  Lineup lineup;
  lineup.draw();
  cout<< "Rectangle:\n";
  Rectangle rect;
  rect.draw();
  cout<< "Circle:\n";
  Circle circle;
  circle.draw();
  cout<< "Triangle:\n";
  Triangle triangle;
  triangle.draw();
  cout<< "Zigzag:\n";
  Zigzag zigzag;
  zigzag.draw();
  cout<< "Strips:\n";
  Strip strip;
  strip.draw();

  int n=5;

  while(n--){
    cout<<"enter 1 for house, 2 for tree, 3 for river, 4 for fence, 5 for hill\n";
    int p;
    cin>>p;
    if(p==1){
        cout<<"House consists of primary shapes: triangle, rectangle, line\n";
        Picture house;
        house.add(&triangle);
        house.add(&rect);
        house.add(&line);
        house.draw();
    }
    if(p==2){
        cout<<"Tree consists of primary shapes: circle, lineup, line\n";
        Picture tree;
        tree.add(&circle);
        tree.add(&lineup);
        tree.add(&line);
        tree.draw();

    }
    if(p==3){
        cout<<"Water consists of primary shapes: lines, zigzags\n";
        Picture water;
        water.add(&line);
        water.add(&zigzag);
        water.add(&zigzag);
        water.add(&line);
        water.draw();
    }
    if(p==4){
        cout<<"Fence consists of primary shapes: lines, strip\n";
        Picture fence;
        fence.add(&line);
        fence.add(&strip);
        fence.add(&line);
        fence.draw();
    }
    if(p==5){
        cout<<"Hills consists of primary shapes: triangles\n";
        Picture hill;
        hill.add(&triangle);
        hill.add(&triangle);
        hill.add(&triangle);
        hill.draw();
    }
  }
  return 0;
}
