#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>    // OPTION
#include <vector>    // read file and put in vector
using namespace std;

template <typename Comparable_1, typename Comparable_2> class BinarySearchTree;

template <typename Comparable_1, typename Comparable_2>
class BinaryNode
{
      Comparable_1 element1; // sequence
      vector<Comparable_2> element2; // enzy
      BinaryNode *left;
      BinaryNode *right;
      int height;
      bool exist;
      BinaryNode( const Comparable_1 & theElement1, const Comparable_2 & theElement2, BinaryNode *lt, BinaryNode *rt , int h = 0, bool ex = false): 
	  element1( theElement1 ),element2( theElement2 ), left( lt ), right( rt ), height(h), exist( ex ) { }
      friend class BinarySearchTree<Comparable_1, Comparable_2>;
};

template <typename Comparable_1, typename Comparable_2>
class BinarySearchTree
{
      public:
             BinarySearchTree(): root ( NULL ) { }
             ~BinarySearchTree( );
             void makeEmpty( );
             explicit BinarySearchTree( const Comparable_1 & notFound );
             BinarySearchTree( const BinarySearchTree & rhs );
             bool isEmpty( ) const;
             int height( ) const;
//             void insert( const Comparable_1 & x );
             void insert( const Comparable_1 & x , const Comparable_2 y);
             const Comparable_1 & findMin( ) const;
             const Comparable_1 & findMax( ) const;
             const Comparable_1 & find( const Comparable_1 & x ) const;
             const Comparable_1 & find( const Comparable_1 & x, const Comparable_2 y ) const;
             bool findEnzyme( const Comparable_1 & x, const Comparable_2 y ) const;
             const int & printNodeNumber( ) const;
             void print (const int order) const;
             const int & printDepth( ) const;
             void remove( const Comparable_1 & x );
             void lazydeletion ( const Comparable_1 & x);
             void stats(double &avgd, int &height);
             bool operator< ( const BinarySearchTree & rhs );
             const BinarySearchTree operator=( const BinarySearchTree & rhs );
             bool operator==( const BinarySearchTree & rhs );
             bool operator!=( const BinarySearchTree & rhs );
             
      private:
              BinaryNode<Comparable_1, Comparable_2> *root;
              const Comparable_1 ITEM_NOT_FOUND;
              const Comparable_1 & elementAt( BinaryNode<Comparable_1, Comparable_2> *t ) const;
//              void insert( const Comparable_1 & x, BinaryNode<Comparable_1, Comparable_2> * & t ) const;
              void insert( const Comparable_1 & x, const Comparable_2 y , BinaryNode<Comparable_1, Comparable_2> * & t ) const;
              BinaryNode<Comparable_1, Comparable_2> * findMin( BinaryNode<Comparable_1, Comparable_2> *t ) const;
              BinaryNode<Comparable_1, Comparable_2> * findMax( BinaryNode<Comparable_1, Comparable_2> *t ) const;
              BinaryNode<Comparable_1, Comparable_2> *
              find( const Comparable_1 & x, BinaryNode<Comparable_1, Comparable_2> *t ) const;
              BinaryNode<Comparable_1, Comparable_2> *
              find( const Comparable_1 & x, const Comparable_2 y, BinaryNode<Comparable_1, Comparable_2> *t ) const;
              bool findEnzyme( const Comparable_1 & x, const Comparable_2 y, BinaryNode<Comparable_1, Comparable_2> *t ) const;
              const int * printNodeNumber( BinaryNode<Comparable_1, Comparable_2> * & t ) const;
              const int * printDepth( BinaryNode<Comparable_1, Comparable_2> * t ) const;
              void printPre(BinaryNode<Comparable_1, Comparable_2> * t ) const;	// internal: preorder print
              void printIn(BinaryNode<Comparable_1, Comparable_2> * t ) const;	// internal: inorder print
              void printPost(BinaryNode<Comparable_1, Comparable_2> * t ) const;	// internal: postorder print
              void remove( const Comparable_1 & x, BinaryNode<Comparable_1, Comparable_2> * & t );
              void lazydeletion( const Comparable_1 & x, BinaryNode<Comparable_1, Comparable_2> * & t );
              void clone( BinaryNode<Comparable_1, Comparable_2> * & t );
              void makeEmpty( BinaryNode<Comparable_1, Comparable_2> * & t  );
              void stats( int &nnodes, int cdepth, int &tdepth, int &mdepth, BinaryNode<Comparable_1, Comparable_2> * & t );
              int max( int lhs, int rhs ) const;
              int height( BinaryNode<Comparable_1, Comparable_2> *t ) const;
};
#include "BST.cpp"
#endif
