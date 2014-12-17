#include "AVL.h"
#include <iostream>
#include <string>    // OPTION
#include <vector>    // read file and put in vector
using namespace std;


template <typename Comparable_1, typename Comparable_2>
bool AvlTree<Comparable_1, Comparable_2>::isEmpty( ) const
{
     if (root == NULL){return true; }
     else if ((root != NULL )) {return false;}
     else{ return false;}
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 & AvlTree<Comparable_1, Comparable_2>::elementAt( AvlNode<Comparable_1, Comparable_2> *t ) const
{
           return t == NULL ? ITEM_NOT_FOUND : t->element1;
}

template <typename Comparable_1, typename Comparable_2>
AvlTree<Comparable_1, Comparable_2>::AvlTree( const AvlTree & rhs)
{
	root = new AvlNode<Comparable_1, Comparable_2> (rhs->element1, rhs->element2, rhs->left, rhs->right, rhs->height, rhs->exist);

}
/*
template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::insert( const Comparable_1 & x ) 
{
     insert( x, root );
}

template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::insert( const  Comparable_1 &x, AvlNode<Comparable_1, Comparable_2> * & t )
{
     if( t == NULL )
     {
         t = new AvlNode<Comparable_1, Comparable_2>;
         t->element1 = x ;
         t->element2 = NULL;
         t->right = NULL;
         t->left = NULL;
         t->height = 0;
         t->exist = true;
     }
     else if( x < t->element1 )
     {
          insert( x, t->left );
          if( height( t->left ) - height( t->right ) == 2 )
              if( x < t->left->element1 )
                  rotateWithLeftChild( t );
              else
                  doubleWithLeftChild( t );
     }
     else if( t->element1 < x )
     {
          insert( x, t->right );
          if( height( t->right ) - height( t->left ) == 2 )
              if( x < t->right->element1 )
                  rotateWithRightChild( t );
              else
                  doubleWithRightChild( t );
     }
     else
         ; // Duplicate; do nothing
     t->height = max( height( t->left ), height( t->right ) ) + 1;
}
*/
template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::insert( const Comparable_1 & x, const Comparable_2 y )
{
     insert( x, y, root );                        // x = key, y = value
}

template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::insert( const Comparable_1 & x, const Comparable_2 y, AvlNode<Comparable_1, Comparable_2> * & t )
{
     if( t == NULL )
         t = new AvlNode<Comparable_1, Comparable_2>( x, y, NULL, NULL, true );
     else if( x < t->element1 )
     {
          insert( x, y, t->left );
          if( height( t->left ) - height( t->right ) == 2 )
              if( x < t->left->element1 )
                  rotateWithLeftChild( t );
              else
                  doubleWithLeftChild( t );
     }
     else if( x > t->element1 )
     {
          insert( x, y, t->right );
          if( height( t->right ) - height( t->left ) == 2 )
              if( x < t->right->element1 )
                  rotateWithRightChild( t );
              else
                  doubleWithRightChild( t );
     }
     else // ( x == t->element1 )
     {
         t->element2 = y ;
     }
     t->height = max( height( t->left ), height( t->right ) ) + 1;
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 & AvlTree<Comparable_1, Comparable_2>::findMin( ) const
{
      return elementAt( findMin( root ) );
}

template <typename Comparable_1, typename Comparable_2>
AvlNode<Comparable_1, Comparable_2> * AvlTree<Comparable_1, Comparable_2>::findMin( AvlNode<Comparable_1, Comparable_2> *t ) const
{
                       if( t == NULL )
                           return NULL;
                       if( t->left == NULL )
                           return t;
                       return findMin( t->left );
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 & AvlTree<Comparable_1, Comparable_2>::findMax( ) const
{
      return elementAt ( findMin( root ) );
}

template <typename Comparable_1, typename Comparable_2>
AvlNode<Comparable_1, Comparable_2> *AvlTree<Comparable_1, Comparable_2>::findMax( AvlNode<Comparable_1, Comparable_2> *t ) const
{
                       if( t == NULL )
                           return NULL;
                       if( t->right == NULL )
                           return t;
                       return findMin( t->right );
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 & AvlTree<Comparable_1, Comparable_2>::find( const  Comparable_1 &x ) const
{
	return elementAt( find( x, root ) );
}

template <typename Comparable_1, typename Comparable_2>
AvlNode<Comparable_1, Comparable_2> *AvlTree<Comparable_1, Comparable_2>::find( const  Comparable_1 &x, AvlNode<Comparable_1, Comparable_2> *t ) const
{
	if( t == NULL )
		return NULL;
	else if( t->exist == false )
	{
		cout << x << " is not exist in the list.\n";
		return 0;
	}
	else if( x < t->element1 )
		return find( x, t->left );
	else if( x > t->element1 )
		return find( x, t->right );
	else
		return t; // Match
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 & AvlTree<Comparable_1, Comparable_2>::find( const Comparable_1 & x, const Comparable_2 y ) const
{
      return  elementAt( find( x, y, root ) );
}

template <typename Comparable_1, typename Comparable_2>
AvlNode<Comparable_1, Comparable_2> *AvlTree<Comparable_1, Comparable_2>::find( const Comparable_1 & x, const Comparable_2 y, AvlNode<Comparable_1, Comparable_2> *t ) const
{
                       if( t == NULL )
                           return NULL;
                       else if( t->exist == false ) // for lazydeletion
                       {
                            return NULL;
                       }
                       else if( x < t->element1 )
                            return find( x, t->left );
                       else if( x > t->element1 )
                            return find( x, t->right );
                       else // find the key node and looking for the new enzyme
                       {
                            cout << "Sequence: "<< t->element1 << endl;
                            cout << "Enzyme: "<< t->element2 << endl;
                            return t; // Match
                       }
}

template <typename Comparable_1, typename Comparable_2>
bool AvlTree<Comparable_1, Comparable_2>::findEnzyme( const Comparable_1 & x, const Comparable_2 y ) const
{
      return findEnzyme( x, y, root );
}

template <typename Comparable_1, typename Comparable_2>
bool AvlTree<Comparable_1, Comparable_2>::findEnzyme( const Comparable_1 & x, const Comparable_2 y, AvlNode<Comparable_1, Comparable_2> *t ) const
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
const int AvlTree<Comparable_1, Comparable_2>::printNodeNumber( ) const
{
      return printNodeNumber ( root );
}

template <typename Comparable_1, typename Comparable_2>
const int AvlTree<Comparable_1, Comparable_2>::printNodeNumber( AvlNode<Comparable_1, Comparable_2> * & t ) const
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
const int & AvlTree<Comparable_1, Comparable_2>::printDepth( ) const
{
      return printDepth ( root );
}

template <typename Comparable_1, typename Comparable_2>
const int *AvlTree<Comparable_1, Comparable_2>::printDepth( AvlNode<Comparable_1, Comparable_2> * t ) const
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

// Print the tree in preorder (order < 0), inorder (order == 0),
// or postorder (order > 0), one value in one line
template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::print (const int order) const
{
    if (order < 1) printPre(root);
    else if (order == 1) printIn(root);
    else printPost(root);
}

//  Printing tree in preorder
template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::printPre(AvlNode<Comparable_1, Comparable_2> * t) const
{
    if (t == NULL){};			    // base case
    cout << t->element2
    	 << t->element1;			// print the key
    if (t->exist) 
       cout << " [d]" << endl;		// (if deleted)
    if (t->left != NULL)
    	printPre(t->left);				// then the left subtree
    if (t->right != NULL)
        printPre(t->right);				// and then the right subtree
}

// Printing tree in postorder 
template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::printPost(AvlNode<Comparable_1, Comparable_2> *t) const
{
    if (t == NULL){};			    // base case
    if (t->left != NULL)
    	printPost(t->left);				// First print the left subtree
    if (t->right != NULL)
    	printPost(t->right);			// then the right subtree
    cout << t->element2
    	 << t->element1;			// print the key
    if (t->exist)
       cout << " [d]" << endl;		// (if deleted)
}

// Printing tree in inorder
template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::printIn(AvlNode<Comparable_1, Comparable_2> *t) const
{
    if (t == NULL){};			    // base case
    if(t->left != NULL)
        printIn(t->left);			    // First print the left subtree
    cout << t->element2
    	 << t->element1;			// print the key
    if (t->exist) 
       cout << " [d]" << endl;		// (if deleted)
    if(t->right != NULL)
    	printIn(t->right);				// and then the right subtree
}

template <typename Comparable_1, typename Comparable_2>
int AvlTree<Comparable_1, Comparable_2>::height( ) const
{
    height ( root );
}

template <typename Comparable_1, typename Comparable_2>
int AvlTree<Comparable_1, Comparable_2>::height( AvlNode<Comparable_1, Comparable_2> *t ) const
{
    if (t == NULL) {return -1;}
    else {return t->height;}
}

template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::stats(double &avgd, int &height)
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
void AvlTree<Comparable_1, Comparable_2>::stats( int &nnodes, int cdepth, int &tdepth, int &mdepth, AvlNode<Comparable_1, Comparable_2> *t)
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

template <typename Comparable_1, typename Comparable_2>
int AvlTree<Comparable_1, Comparable_2>::max( int lhs, int rhs ) const
{
    if (lhs < rhs) 
       return rhs;
    return lhs;
}

template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::remove( const  Comparable_1 &x )
{
     remove( x, root );
}

template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::remove( const  Comparable_1 &x, AvlNode<Comparable_1, Comparable_2> * & t )
{
     if ( t == NULL )
     // can't delete from an empty tree
        return;
     if ( x < t->element1 )
     {
     // delete from the left subtree
     remove( x, t->left );
     // check if the heights of the subtrees are now too different
     if ( height( t->right ) - height( t->left ) == 2 ) // unbalanced
     // right subtree too tall relative to left
     // Which rotation to use depends on whether the left subtree of the
     // right subtree is larger, or the right of the right is larger.
     // If the left is larger we MUST use
        if ( height((t->right)->right) >= height((t->right)->left) )
           rotateWithRightChild( t );
        else
            doubleWithRightChild( t );
     }
     else if( x > t->element1 )
     {
          // delete from the right subtree
          remove( x, t->right );
          if( height( t->left ) - height( t->right ) == 2 ) // unbalanced
          // left subtree too tall
             if( height((t->left)->left) >= height((t->left)->right) )
                 rotateWithLeftChild( t );
             else
                 doubleWithLeftChild( t );
     }
     else { // delete this node
          if ((t->left != NULL) && (t->right != NULL) ) // two non-empty subtrees
          {
                       t->element1 = findMin(t->right)->element1;
                       remove(t->element1, t->right);
                       if ( height( t->left ) - height( t->right ) == 2 ) // unbalanced
                       // left subtree too tall
                          if ( height((t->left)->left) >= height((t->left)->right) )
                             rotateWithLeftChild( t );
                          else
                              doubleWithLeftChild( t );
          }
          else {
               AvlNode<Comparable_1, Comparable_2>* OldNode = t;
               t = (t->left != NULL)? t->left : t->right;
               delete OldNode;
               }
          }
          if ( NULL != t )
          t->height = max( height( t->left ), height( t->right ) ) + 1;
}

template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::lazydeletion ( const  Comparable_1 &x)
{
	lazydeletion(x, root);
}
template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::lazydeletion ( const  Comparable_1 &x, AvlNode<Comparable_1, Comparable_2> * & t )
{
     if( t == NULL )
         return; // Item not found; do nothing
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
         AvlNode<Comparable_1, Comparable_2> *oldNode = t;
         t = ( t->left != NULL ) ? t->left : t->right;
         oldNode -> exist = false;
     }
}

template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::rotateWithLeftChild( AvlNode<Comparable_1, Comparable_2> * & k2 ) const
{
     AvlNode<Comparable_1, Comparable_2> *k1 = k2->left;
     k2->left = k1->right;
     k1->right = k2;
     k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
     k1->height = max( height( k1->left ), k2->height ) + 1;
     k2 = k1;
}

/**
* Rotate binary tree node with right child.
* For AVL trees, this is a single rotation for case 4.
* Update heights, then set new root.
*/
template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::rotateWithRightChild( AvlNode<Comparable_1, Comparable_2> * & k1 ) const
{
     AvlNode<Comparable_1, Comparable_2> *k2 = k1->right;
     k1->right = k2->left;
     k2->left = k1;
     k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
     k2->height = max( height( k2->right ), k1->height ) + 1;
     k1 = k2;
}

/**
* Double rotate binary tree node: first left child.
* with its right child; then node k3 with new left child.
* For AVL trees, this is a double rotation for case 2.
* Update heights, then set new root.
*/
template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::doubleWithLeftChild( AvlNode<Comparable_1, Comparable_2> * & k3 ) const
{
     rotateWithRightChild( k3->left );
     rotateWithLeftChild( k3 );
}

/**
* Double rotate binary tree node: first right child.
* with its left child; then node k1 with new right child.
* For AVL trees, this is a double rotation for case 3.
* Update heights, then set new root.
*/
template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::doubleWithRightChild( AvlNode<Comparable_1, Comparable_2> * & k1 )const
{
     rotateWithLeftChild( k1->right );
     rotateWithRightChild( k1 );
}

template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::makeEmpty( )
{
     makeEmpty( root );
     
}

template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::makeEmpty( AvlNode<Comparable_1, Comparable_2> * & t )
{
     if (t != NULL)
     {
     	makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
     }
     t = NULL;
}

template <typename Comparable_1, typename Comparable_2>
AvlTree<Comparable_1, Comparable_2>::~AvlTree(  )
{
    makeEmpty( root );
}


template <typename Comparable_1, typename Comparable_2>
const AvlTree<Comparable_1, Comparable_2> AvlTree<Comparable_1, Comparable_2>::operator=( const AvlTree & rhs )
{
    if (this != &rhs) {
	makeEmpty();
	root = clone(rhs.root);
    }
    return *this;
}

template <typename Comparable_1, typename Comparable_2>
void AvlTree<Comparable_1, Comparable_2>::clone( AvlNode<Comparable_1, Comparable_2> * & t )
{
     if ( t == NULL )
        return NULL;
     else
         return new AvlNode<Comparable_1, Comparable_2> (t->element1, t->element2, t->left, t->right, t->height, t->exist);
}

template <typename Comparable_1, typename Comparable_2>
bool AvlTree<Comparable_1, Comparable_2>::operator< ( const AvlTree & rhs )
{
     if (this->element2 > rhs->element2){return true;}
     else{ return false;}
}

template <typename Comparable_1, typename Comparable_2>
bool AvlTree<Comparable_1, Comparable_2>::operator== ( const AvlTree & rhs )
{
     return this->element1 == rhs.element1 && this->element2 == rhs.element2;
}

template <typename Comparable_1, typename Comparable_2>
bool AvlTree<Comparable_1, Comparable_2>::operator!= ( const AvlTree & rhs )
{
          return !(this->element1 == rhs.element1) || !(this->element2 == rhs.element2);
}
