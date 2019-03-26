/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"
#include <cstdlib>
int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  ariel::Tree ourtree;
  ariel::Tree mytree;

  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

int random[5] = {rand()%100,rand()%100,rand()%100,rand()%100,rand()%100};
   for(int i =0;i<5;i++){
   ourtree.insert(random[i]);
   }
 

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
 //.CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  //.CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)

  //.CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .print();
   
    for(int i =0;i<5;i++){
   tc.CHECK_EQUAL (ourtree.contains(random[i]),true);
   }
   tc.CHECK_EQUAL (emptytree.size() ,5);
    for(int i =0;i<5;i++){
    tc.CHECK_THROWS(emptytree.remove(random[i]));
    tc.CHECK_EQUAL (emptytree.size(), 5-i);
   }
   



  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
