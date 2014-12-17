#include "BST.h"
#include <iostream>
#include <string>    // OPTION
#include <vector>    // read file and put in vector
using namespace std;

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 & BinarySearchTree<Comparable_1, Comparable_2>::
elementAt( BinaryNode<Comparable_1, Comparable_2> *t ) const
{
           return t == NULL ? ITEM_NOT_FOUND : t->element1;
}

template <typename Comparable_1, typename Comparable_2>
BinarySearchTree<Comparable_1, Comparable_2>::BinarySearchTree( const BinarySearchTree & rhs)
{
	root = new BinaryNode<Comparable_1,Comparable_2> (rhs->element1, rhs->element2, rhs->left, rhs->right, rhs->height, rhs->exist);
}
	
template <typename Comparable_1, typename Comparable_2>
bool BinarySearchTree<Comparable_1, Comparable_2>::isEmpty( ) const
{
     if (root == NULL){return true;}
     else if (root != NULL){return false;}
     else {return false;}
}

template <typename Comparable_1, typename Comparable_2>
int BinarySearchTree<Comparable_1, Comparable_2>::max( int lhs, int rhs ) const
{
    if (lhs < rhs) 
       return rhs;
    return lhs;
}

template <typename Comparable_1, typename Comparable_2>
int BinarySearchTree<Comparable_1, Comparable_2>::height( ) const
{
    height ( root );
}

template <typename Comparable_1, typename Comparable_2>
int BinarySearchTree<Comparable_1, Comparable_2>::height( BinaryNode<Comparable_1, Comparable_2> *t ) const
{
    if (t == NULL) {
          return -1;}
    else {
         return t->height;}
}

/*
template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::insert( const Comparable_1 & x )
{
     insert( x, root );
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::insert( const Comparable_1 & x, BinaryNode<Comparable_1, Comparable_2> * & t ) const
{
     if( t == NULL )
         t = new BinaryNode<Comparable_1, Comparable_2>( x, NULL, NULL, NULL );
     else if( x < t->element1 )
          insert( x, t->left );
     else if( x > t->element1 )
          insert( x, t->right );
     else
         t->height = max( height( t->left ), height( t->right ) ) + 1;
}
*/
template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::insert( const Comparable_1 & x, const Comparable_2 y )
{
     insert( x, y, root );
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::insert( const Comparable_1 & x, const Comparable_2 y , BinaryNode<Comparable_1, Comparable_2> * & t ) const
{
     if( t == NULL )
         t = new BinaryNode<Comparable_1, Comparable_2>( x, y, NULL, NULL );
     else if( x < t->element1 )
          insert( x, y, t->left );
     else if( x > t->element1 )
          insert( x, y, t->right );
     else // ( x == > t->element1 )
          t->element2.insert( t->element2.end(), y.begin(), y.end() );
          t->height = max( height( t->left ), height( t->right ) ) + 1;
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 & BinarySearchTree<Comparable_1, Comparable_2>::find( const Comparable_1 & x ) const
{
      return elementAt( find( x, root ) );
}

template <typename Comparable_1, typename Comparable_2>
BinaryNode<Comparable_1, Comparable_2> *BinarySearchTree<Comparable_1, Comparable_2>:: find( const Comparable_1 & x,BinaryNode<Comparable_1, Comparable_2> *t ) const
{
                       if( t == NULL )
                           return NULL;
                       else if( x < t->element1 )
                            return find( x, t->left );
                       else if( x > t->element1 )
                            return find( x, t->right );
                       else if( t->exist == false )
                       { // lazydeletion
                            cout << x << " is not exist in the list.\n";
                            return NULL;
                       }     
                       else // find the key node
                           return t; // Match
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 & BinarySearchTree<Comparable_1, Comparable_2>::find( const Comparable_1 & x, const Comparable_2 y ) const
{
      return elementAt( find( x, y, root ) );
}

template <typename Comparable_1, typename Comparable_2>
BinaryNode<Comparable_1, Comparable_2> *BinarySearchTree<Comparable_1, Comparable_2>:: find( const Comparable_1 & x, const Comparable_2 y, BinaryNode<Comparable_1, Comparable_2> *t ) const
{
                       if( t == NULL )
                           return NULL;
                       else if( x < t->element1 )
                            return find( x, t->left );
                       else if( x > t->element1 )
                            return find( x, t->right );
                       else if( t->exist == false ) // for lazydeletion
                       {
                            return NULL;
                       }     
                       else // find the key node and looking for the new enzyme
                       {
                            for (vector<int>::iterator it = t->element2.begin() ; it != t->element2.end(); ++it)
                            {
                                 if ( *it == y ) 
                                 {
                                      return t; // Match
                                 }
                                 else
                                 {
                                     return NULL;
                                 }
                            }
                       }
}

template <typename Comparable_1, typename Comparable_2>
bool BinarySearchTree<Comparable_1, Comparable_2>::findEnzyme( const Comparable_1 & x, const Comparable_2 y ) const
{
      return  findEnzyme( x, y, root );
}

template <typename Comparable_1, typename Comparable_2>
bool BinarySearchTree<Comparable_1, Comparable_2>::findEnzyme( const Comparable_1 & x, const Comparable_2 y, BinaryNode<Comparable_1, Comparable_2> *t ) const
{
                       if( t == NULL )
                           return false;
                       else if( t->exist == false ) // for lazydeletion
                       {
                            return false;
                       }
                       else if( x < t->element1 )
                            return find( x, t->left );
                       else if( x > t->element1 )
                            return find( x, t->right );
                       else // find the key node and start looking for the new enzyme
                       {
                            if (t->element2 == y)
                            {
                               return true; // found
                            }
                       }
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 & BinarySearchTree<Comparable_1, Comparable_2>::findMin( ) const
{
      return elementAt( findMin( root ) );
}

template <typename Comparable_1, typename Comparable_2>
BinaryNode<Comparable_1, Comparable_2> *BinarySearchTree<Comparable_1, Comparable_2>::findMin( BinaryNode<Comparable_1, Comparable_2> *t ) const
{
                       if( t == NULL )
                           return NULL;
                       if( t->left == NULL )
                           return t;
                       return findMin( t->left );
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 & BinarySearchTree<Comparable_1, Comparable_2>::findMax( ) const
{
      return elementAt( findMin( root ) );
}

template <typename Comparable_1, typename Comparable_2>
BinaryNode<Comparable_1, Comparable_2> *BinarySearchTree<Comparable_1, Comparable_2>::findMax( BinaryNode<Comparable_1, Comparable_2> *t ) const
{
                       if( t == NULL )
                           return NULL;
                       if( t->right == NULL )
                           return t;
                       return findMin( t->right );
}

template <typename Comparable_1, typename Comparable_2>
const int & BinarySearchTree<Comparable_1, Comparable_2>::printNodeNumber( ) const
{
      return printNodeNumber ( root );
}

template <typename Comparable_1, typename Comparable_2>
const int *BinarySearchTree<Comparable_1, Comparable_2>::printNodeNumber( BinaryNode<Comparable_1, Comparable_2> * & t ) const
{
      if (t!=NULL)
      {
                 int r,l;
                 r = printNodeNumber(t->right);
                 l = printNodeNumber(t->left);
                 return r+l+1;
      }
      else
      {
          return 0;
      }
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::print (const int order) const
{
     if (order < 1) printPre(root);
     else if (order == 1) printIn(root);
     else printPost(root);
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::printPre(BinaryNode<Comparable_1, Comparable_2> * t) const
{
    if (t == NULL) 
       return;			
    cout << t->element2
    	 << t->element1;			// print the key
    if (t->exist) 
       cout << " [d]" << endl;		// (if deleted)
    if (t->left != NULL)
        printPre(t->left);				// then the left subtree
    if (t->right != NULL)
        printPre(t->right);				// then the right subtree
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::printPost(BinaryNode<Comparable_1, Comparable_2> * t) const
{
    if (t == NULL) 
       return;	
	if (t->left != NULL)		
    	printPost(t->left);			// print the left subtree
    if (t->right != NULL)
    	printPost(t->right);		// then the right subtree
    cout << t->element2
    	 << t->element1;			// print the key
    if (t->exist) 
       cout << " [d]" << endl;		// (if deleted)
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::printIn(BinaryNode<Comparable_1, Comparable_2> * t) const
{
    if (t == NULL) 
       return;			 
    if (t->left != NULL)
		printIn(t->left);			// print the left subtree
    cout << t->element2
    	 << t->element1;			// print the key
    if (t->exist) 
       cout << " [d]" << endl;		// (if deleted)
    if (t->right != NULL)
		printIn(t->right);			// then the right subtree
}

template <typename Comparable_1, typename Comparable_2>
const int & BinarySearchTree<Comparable_1, Comparable_2>::printDepth( ) const
{
      return printDepth ( root );
}

template <typename Comparable_1, typename Comparable_2>
const int *BinarySearchTree<Comparable_1, Comparable_2>::printDepth( BinaryNode<Comparable_1, Comparable_2> * t ) const
{
    if ( t != NULL )
    {
                int r, l;
                r = printDepth( t->right );
                l = printDepth( t->left );
                if ( r > l )
                {
                        return r + 1;
                }
                else
                {
                    return l + 1;
                }
    }
    return 0;
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::remove( const  Comparable_1 &x )
{
      remove ( x , root );
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::remove( const  Comparable_1 &x, BinaryNode<Comparable_1, Comparable_2> * & t ) 
{
     if( t == NULL )
         ; // Item not found; do nothing
     if( x < t->element1 )
         remove( x, t->left );
     else if( t->element1 < x )
          remove( x, t->right );
     else if( t->left != NULL && t->right != NULL ) // Two children
     {
          t->element1 = findMin( t->right )->element1;
          remove( t->element1, t->right );
     }
     else
     {
         BinaryNode<Comparable_1, Comparable_2> *oldNode = t;
         t = ( t->left != NULL ) ? t->left : t->right;
         delete oldNode;
     }
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::lazydeletion( const  Comparable_1 &x )
{
	lazydeletion ( x , root );          
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::lazydeletion( const  Comparable_1 &x, BinaryNode<Comparable_1, Comparable_2> * & t ) 
{
     if( t == NULL )
         ; // Item not found; do nothing
     if( x < t->element1 )
         remove( x, t->left );
     else if( x > t->element1 )
          remove( x, t->right );
     else if( t->left != NULL && t->right != NULL ) // Two children
     {
          t->element1 = findMin( t->right )->element1;
          remove( t->element1, t->right );
     }
     else
     {
         BinaryNode<Comparable_1, Comparable_2> *oldNode = t;
         t = ( t->left != NULL ) ? t->left : t->right;
         oldNode -> exist = false;
     }
}

template <typename Comparable_1, typename Comparable_2>
BinarySearchTree<Comparable_1, Comparable_2>::~BinarySearchTree( )
{
    makeEmpty( );
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::makeEmpty( )
{
     makeEmpty( root );
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::makeEmpty( BinaryNode<Comparable_1, Comparable_2> * & t )
{
     if (t != NULL)
     {
     	if (t->left!=NULL)
     		makeEmpty(t->left);
		if(t->right!=NULL)
			makeEmpty(t->right);
		delete t;
     }
     t = NULL;
}

template <typename Comparable_1, typename Comparable_2>
const BinarySearchTree<Comparable_1, Comparable_2> BinarySearchTree<Comparable_1, Comparable_2>::operator=( const BinarySearchTree & rhs )
{
    if (this != &rhs) {
	makeEmpty();
	root = clone(rhs.root);
    }
    return *this;
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::clone( BinaryNode<Comparable_1, Comparable_2> * & t )
{
     if ( t == NULL )
        return NULL;
     else
         return new BinaryNode<Comparable_1, Comparable_2> (t->element1, t->element2, t->left, t->right, t->height, t->exist);
}

template <typename Comparable_1, typename Comparable_2>
bool BinarySearchTree<Comparable_1, Comparable_2>::operator<( const BinarySearchTree & rhs )
{
     if (this->element2 > rhs->element2){return true;}
     else{ return false;}
}

template <typename Comparable_1, typename Comparable_2>
bool BinarySearchTree<Comparable_1, Comparable_2>::operator==( const BinarySearchTree & rhs )
{
     return (this->element1 == rhs.element1) , (this->element2 == rhs.element2);
}

template <typename Comparable_1, typename Comparable_2>
bool BinarySearchTree<Comparable_1, Comparable_2>::operator!=( const BinarySearchTree & rhs )
{
          return !(this->element1 == rhs.element1), !(this->element2 == rhs.element2);
}

template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::stats(double &avgd, int &height)
{
    int nnodes = 0;		// total # of nodes in the tree
    int cdepth = 0;
    int tdepth = 0;		// sum of depths of all nodes in the tree
    int mdepth = -1;	// maximum depth of any node in the tree
    
    stats(nnodes, cdepth, tdepth, mdepth, root);
    height = mdepth;
    if (nnodes > 0) avgd = double(tdepth) / nnodes;
    else avgd = 0.0;
}


template <typename Comparable_1, typename Comparable_2>
void BinarySearchTree<Comparable_1, Comparable_2>::stats( int &nnodes, int cdepth, int &tdepth, int &mdepth, BinaryNode<Comparable_1, Comparable_2> * & t )
{
    if (t != NULL)
    {
	    nnodes++;
	    tdepth += cdepth;
	    if (cdepth > mdepth) mdepth = cdepth;
	    stats(nnodes,cdepth+1,tdepth,mdepth,t->left);
	    stats(nnodes,cdepth+1,tdepth,mdepth,t->right);    
	}
}
