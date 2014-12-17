#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <string>    // OPTION
#include <vector>    // read file and put in vector
using namespace std;

template <typename Comparable_1, typename Comparable_2> class AvlTree;

template <typename Comparable_1, typename Comparable_2>
class AvlNode
{
      Comparable_1 element1; // sequence
      vector<Comparable_2> element2; // enzy
      AvlNode *left;
      AvlNode *right;
      int height;
      bool exist;
      AvlNode( const Comparable_1 & theElement1, const Comparable_2 & theElement2, AvlNode *lt, AvlNode *rt, int h = 0, bool ex = false): 
	  element1( theElement1 ),element2( theElement2 ), left( lt ), right( rt ), height( h ), exist( ex ) { }
      friend class AvlTree<Comparable_1, Comparable_2>;
};

template <typename Comparable_1, typename Comparable_2>
class AvlTree
{
      public:
             AvlTree() : root ( NULL ) { }
             ~AvlTree( );
             explicit AvlTree( const Comparable_1 & notFound );
             AvlTree( const AvlTree & rhs);
             const Comparable_1 & findMin( ) const;
             const Comparable_1 & findMax( ) const;
             const Comparable_1 & find( const  Comparable_1 &x ) const;
             const Comparable_1 & find( const Comparable_1 & x, const Comparable_2 y  ) const;
             bool isEmpty( ) const;
             bool findEnzyme( const Comparable_1 & x, const Comparable_2 y  ) const;
             int height( ) const;
             void stats(double &avgd, int &height);	// compute statistics
             void print (const int order) const;
             const int printNodeNumber( ) const;
             const int & printDepth( ) const;
//             void insert( const  Comparable_1 & x ); 
             void insert( const Comparable_1 & x, const Comparable_2 y );
             void remove( const  Comparable_1 &x );
             void lazydeletion ( const Comparable_1 & x);
			 void lazydeletion ( const  Comparable_1 &x, AvlNode<Comparable_1, Comparable_2> * & t );
			 void makeEmpty(  );
			 const AvlTree operator=( const AvlTree & rhs );
			 bool operator==( const AvlTree & rhs );     // This is compare the whole node
			 bool operator!=( const AvlTree & rhs );
			 bool operator< ( const AvlTree & rhs );
			 
      private:
              AvlNode<Comparable_1, Comparable_2> *root;
              const Comparable_1 ITEM_NOT_FOUND;
              const Comparable_1 & elementAt( AvlNode<Comparable_1, Comparable_2> *t ) const;
//              void insert( const  Comparable_1 &x, AvlNode<Comparable_1, Comparable_2> * & t );
              void insert( const Comparable_1 & x, const Comparable_2 y , AvlNode<Comparable_1, Comparable_2> * & t );
              AvlNode<Comparable_1, Comparable_2> * findMin( AvlNode<Comparable_1, Comparable_2> *t ) const;
              AvlNode<Comparable_1, Comparable_2> * findMax( AvlNode<Comparable_1, Comparable_2> *t ) const;
              AvlNode<Comparable_1, Comparable_2> * find( const  Comparable_1 &x, AvlNode<Comparable_1, Comparable_2> *t ) const;
              AvlNode<Comparable_1, Comparable_2> * find( const Comparable_1 & x, const Comparable_2 y, AvlNode<Comparable_1, Comparable_2> *t ) const;
              bool findEnzyme( const Comparable_1 & x, const Comparable_2 y, AvlNode<Comparable_1, Comparable_2> *t ) const;
              void printPre(AvlNode<Comparable_1, Comparable_2> *t) const;
              void printPost(AvlNode<Comparable_1, Comparable_2> *t) const;
              void printIn(AvlNode<Comparable_1, Comparable_2> *t) const;
              int height( AvlNode<Comparable_1, Comparable_2> *t ) const;
              void stats( int &nnodes, int cdepth, int &tdepth, int &mdepth, AvlNode<Comparable_1, Comparable_2> *t );
              const int printNodeNumber( AvlNode<Comparable_1, Comparable_2> * & t ) const;
              const int * printDepth( AvlNode<Comparable_1, Comparable_2> * t ) const;
              void remove( const  Comparable_1 &x , AvlNode<Comparable_1, Comparable_2> * & t );
              int max( int lhs, int rhs ) const;
              void rotateWithLeftChild( AvlNode<Comparable_1, Comparable_2> * & k2 ) const;
              void rotateWithRightChild( AvlNode<Comparable_1, Comparable_2> * & k1 ) const;
              void doubleWithLeftChild( AvlNode<Comparable_1, Comparable_2> * & k3 ) const;
              void doubleWithRightChild( AvlNode<Comparable_1, Comparable_2> * & k1 ) const;
              void clone( AvlNode<Comparable_1, Comparable_2> * & t );
              void makeEmpty( AvlNode<Comparable_1, Comparable_2> * & t );
};
#include "AVL.cpp"
#endif
