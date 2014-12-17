#ifndef SEQUENCEMAP_H
#define SEQUENCEMAP_H

#include <iostream>
#include <string>
#include <vector>
#include "AVL.h"
#include "BST.h"
using namespace std;

template <typename Comparable_1, typename Comparable_2>
class SequenceMap
{
      public:
                 
             Comparable_1 key; 						
			 Comparable_2 value;			
             AvlTree < Comparable_1, Comparable_2 > avl;
             BinarySearchTree < Comparable_1, Comparable_2 > bst;
             SequenceMap(){};
             ~SequenceMap();
             bool isEmpty( ) const;

             void insert(const string tree, const Comparable_1 & str ); 
             void insert( const string & tree, const Comparable_1 & str, const Comparable_2 & set );
             
             void selectTree( const string & tree, const Comparable_1 & str ); 
             // insert one element in one node and build the tree
             
             void selectTree( const string & tree, const Comparable_1 & str, const Comparable_2 & set );
			 // this auto insert to the tree with 2 element in the node
			 
             Comparable_1 find(const Comparable_1 & str) const; 
             Comparable_2 find(const Comparable_1 & str, const Comparable_2 & set) const;
             
             const Comparable_1 findMin( ) const;
             const Comparable_1 findMax( ) const;
             bool findEnzyme( const Comparable_1 & x, const Comparable_2 & y ) const;
             const int printNodeNumber( ) const;
             void print (int order) const;
             const int printDepth( ) const;
             void remove( const Comparable_1 & x ) ;
             void lazydeletion ( const Comparable_1 & x) ;
             void stats(double &avgd, int &height);
             void makeEmpty( );
             bool operator< ( const Comparable_1 & rhs );

      private:
              void AVLinsert( const Comparable_1 & str, const Comparable_2 & set );
              void BSTinsert( const Comparable_1 & str, const Comparable_2 & set );
              Comparable_2 merge( const Comparable_2 & set );    // if find() new enzy in the same 
                                                                 // node append it into the set
              void makeEmpty( AvlNode<Comparable_1, Comparable_2> & avl);
              void makeEmpty( BinarySearchTree<Comparable_1, Comparable_2> & bst );
};

#include "SequenceMap.cpp"
#endif


