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
        ariel::Tree randomali;
        ariel::Tree ourtree;
        ariel::Tree treeright;
        ariel::Tree bigtree;
//insert threetree
        threetree.insert(5);
        threetree.insert(7);
        threetree.insert(3);
//insert ourtre
        int random[5] = {rand()%100,rand()%100,rand()%100,rand()%100,rand()%100};
        for(int i =0; i<5; i++) {
                randomali.insert(random[i]);
        }
//insert ourtre1
        int arr[5] = {7,4,3,2,5};
        for(int i =0; i<5; i++) {
                ourtree.insert(arr[i]);
        }
//insert treeright
        treeright.insert(8);
        treeright.insert(9);
        treeright.insert(10);
        treeright.insert(11);
        treeright.insert(12);

// insert bigtree

        bigtree.insert(5);
        bigtree.insert(3);
        bigtree.insert(8);
        bigtree.insert(4);
        bigtree.insert(10);
        bigtree.insert(7);
        bigtree.insert(6);
        bigtree.insert(2);
        bigtree.insert(1);
        bigtree.insert(9);
        bigtree.insert(12);

//testing

//emptytree
        badkan::TestCase tc("Binary tree");
        tc
        .CHECK_EQUAL (emptytree.size(), 0)
        .CHECK_OK    (emptytree.insert(5))
        .CHECK_EQUAL (emptytree.size(), 1)
        .CHECK_EQUAL (emptytree.contains(5), true)
        .CHECK_OK (emptytree.remove(5))
        .CHECK_EQUAL (emptytree.contains(5), false)
        .CHECK_THROWS(emptytree.remove(5))
        .CHECK_EQUAL (emptytree.size(),0)
//threetree
        .CHECK_EQUAL (threetree.size(), 3)
        .CHECK_EQUAL (threetree.root(), 5)
        .CHECK_EQUAL (threetree.parent(3), 5)
        .CHECK_EQUAL (threetree.parent(7), 5)
        .CHECK_EQUAL (threetree.left(5), 3)
        .CHECK_EQUAL (threetree.right(5), 7)
        .CHECK_THROWS(threetree.insert(3))
        .CHECK_THROWS(threetree.left(6))
        .CHECK_OK    (threetree.print())
        .print();
//randomali
        for(int i =0; i<5; i++) {
                tc.CHECK_EQUAL (randomali.contains(random[i]),true);
        }
        tc.CHECK_EQUAL (randomali.size(),5);
        int j=5;
        for(int i =0; i<5; i++) {
                if(randomali.contains(random[i])) {
                        tc.CHECK_EQUAL (randomali.size(),j);
                        j--;
                        tc.CHECK_OK(randomali.remove(random[i]));
                }else{
                        tc.CHECK_THROWS(randomali.remove(random[i]));
                }
        }

//ourtree
        tc.CHECK_EQUAL (ourtree.parent(3), 4)
        .CHECK_EQUAL (ourtree.parent(5), 4)
        .CHECK_EQUAL (ourtree.left(3), 2);

//treeright
        for(int i =8; i<13; i++) {
                tc.CHECK_EQUAL (treeright.contains(i),true);
        }
        tc.CHECK_EQUAL (treeright.size(), 5)
        .CHECK_THROWS(treeright.left(8))
        .CHECK_THROWS(treeright.left(9))
        .CHECK_THROWS(treeright.left(10))
        .CHECK_THROWS(treeright.left(11))
        .CHECK_THROWS(treeright.left(12))
        .CHECK_EQUAL (treeright.right(8), 9)
        .CHECK_EQUAL (treeright.right(9), 10)
        .CHECK_EQUAL (treeright.right(10), 11)
        .CHECK_EQUAL (treeright.right(11), 12)
        .CHECK_OK  (treeright.remove(10))
        .CHECK_THROWS(treeright.remove(10))
        .CHECK_EQUAL (treeright.size(), 4)
        .CHECK_OK    (treeright.insert(10))
        .CHECK_THROWS(treeright.insert(10))
        .CHECK_EQUAL (treeright.parent(10), 11)
        .CHECK_EQUAL (treeright.left(11), 10)
        .CHECK_EQUAL (treeright.right(11), 12)
        .CHECK_THROWS(treeright.remove(0));
        int k=5;
        for(int i =8; i<13; i++) {
                tc.CHECK_EQUAL (treeright.size(), k);
                tc.CHECK_OK(treeright.remove(i));
                k--;
        }

        //bigtree
        tc.CHECK_EQUAL (bigtree.right(5), 8)
        .CHECK_EQUAL (bigtree.right(8), 10)
        .CHECK_EQUAL (bigtree.right(10), 12)
        .CHECK_EQUAL (bigtree.right(3), 4)
        .CHECK_EQUAL (bigtree.left(5), 3)
        .CHECK_EQUAL (bigtree.left(3), 2)
        .CHECK_EQUAL (bigtree.left(2), 1)
        .CHECK_EQUAL (bigtree.left(8), 7)
        .CHECK_EQUAL (bigtree.left(7), 6)
        .CHECK_EQUAL (bigtree.left(10), 9)
        .CHECK_THROWS(bigtree.left(4))
        .CHECK_THROWS(bigtree.left(6))
        .CHECK_THROWS(bigtree.left(9))
        .CHECK_THROWS(bigtree.left(12))
        .CHECK_THROWS(bigtree.left(1))
        .CHECK_THROWS(bigtree.right(4))
        .CHECK_THROWS(bigtree.right(7))
        .CHECK_THROWS(bigtree.right(6))
        .CHECK_THROWS(bigtree.right(4))
        .CHECK_THROWS(bigtree.right(9))
        .CHECK_THROWS(bigtree.right(12))
        .CHECK_THROWS(bigtree.right(2))
        .CHECK_THROWS(bigtree.right(1))
        .CHECK_EQUAL (bigtree.size(),11);
        for(int i =1; i<11; i++) {
                tc.CHECK_EQUAL (bigtree.contains(i),true);
        }
        tc.CHECK_EQUAL (bigtree.contains(12),true);
        int j2=11;
        for(int i =1; i<11; i++) {
                if(bigtree.contains(i)) {
                        tc.CHECK_EQUAL (bigtree.size(), j2);
                        j2--;
                        tc.CHECK_OK(bigtree.remove(i));
                }else{
                        tc.CHECK_THROWS(bigtree.remove(i));
                }
        }
        tc.CHECK_OK(bigtree.remove(12));
        tc.CHECK_EQUAL (bigtree.size(), 0);
        cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
