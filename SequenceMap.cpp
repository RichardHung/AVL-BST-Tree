#include "SequenceMap.h"
using namespace std;
     
template <typename Comparable_1, typename Comparable_2>
bool SequenceMap<Comparable_1, Comparable_2>::isEmpty( ) const
{
     if ( avl.isEmpty( ) )
     {
          if ( bst.isEmpty( ) ){return cout << "Both AVL Tree and Binary Search Tree are empty.\n";}
          if ( ! bst.isEmpty( ) ){return cout << "AVL Tree is empty. Binary Search Tree is not empty.\n";}
     }
     else
     {
          if ( bst.isEmpty( ) ){return cout << "AVL Tree is not empty. Binary Search Tree is empty.\n";}
          if ( ! bst.isEmpty( ) ){return cout << "Both AVL Tree and Binary Search Tree are not empty.\n";}
     }
}

template <typename Comparable_1, typename Comparable_2>
void  SequenceMap<Comparable_1, Comparable_2>::insert(const string tree, const Comparable_1 & str )
{
	selectTree( tree, str);
}

template <typename Comparable_1, typename Comparable_2>
void  SequenceMap<Comparable_1, Comparable_2>::insert( const string & tree, const Comparable_1 & str, const Comparable_2 & set )
{
	selectTree( tree, str, set );
}

template <typename Comparable_1, typename Comparable_2>
void SequenceMap<Comparable_1, Comparable_2>::selectTree( const string & tree, const Comparable_1 & str )
{
     if ( (tree == "avl") || (tree == "AVL") )
         AVLinsert( str );
     else if ( (tree == "bst") || (tree == "BST"))
         BSTinsert( str );
     else 
          cout << "Wrong Enter.\n";
}

template <typename Comparable_1, typename Comparable_2>
void SequenceMap<Comparable_1, Comparable_2>::selectTree( const string & tree, const Comparable_1 & str, const Comparable_2 & set )
{
     if ( (tree == "avl") || (tree == "AVL") )
         AVLinsert( str, set );
     else if ( (tree == "bst") || (tree == "BST"))
         BSTinsert( str, set );
     else 
          cout << "Wrong Enter.\n";
}

template <typename Comparable_1, typename Comparable_2>
void SequenceMap<Comparable_1, Comparable_2>::AVLinsert( const Comparable_1 & str, const Comparable_2 & set )
{
    if ( avl.isEmpty( ) )        
    {
        key = str;
        value = set;
        avl.insert( key, value );
	}	
    else                        // check the enzy is duplicated or not
    {
        for( int i=0; i<set.size( ); i++ )
        {
            if ( avl.findEnzyme( key, set ) ) // if cannot find the enzy in the node
            {
                    merge( set );
                    avl.insert( key, value ); 
            } 
        }  
        // if find the same enzy in the node, do nothing to avoid duplicated.
    }
}

template <typename Comparable_1, typename Comparable_2>
void SequenceMap<Comparable_1, Comparable_2>::BSTinsert( const Comparable_1 & str, const Comparable_2 & set )
{
	if ( bst.isEmpty( ) )        
    {
        key = str;
        value = set;
        bst.insert( key, value );
    }
    else                        // check the enzy is duplicated or not
    {
        for( int i=0; i<set.size( ); i++ )
        {
            if ( bst.findEnzyme( key, set ) ) // if cannot find the enzy in the node
            {
                 merge( set );
                 bst.insert( key, value ); 
            } 
        }
        // if find the same enzy in the node, do nothing to avoid duplicated.
    }
}

template <typename Comparable_1, typename Comparable_2>
Comparable_2 SequenceMap<Comparable_1, Comparable_2>::merge( const Comparable_2 & set )
{
             value += set;
             return value;
}

template <typename Comparable_1, typename Comparable_2>
Comparable_1 SequenceMap<Comparable_1, Comparable_2>::find(const Comparable_1 & str ) const 
{
	if (! avl.isEmpty()){return avl.find( str );}
	else if (! bst.isEmpty()){return bst.find( str );}
}

template <typename Comparable_1, typename Comparable_2>
Comparable_2 SequenceMap<Comparable_1, Comparable_2>::find(const Comparable_1 & str, const Comparable_2 & set ) const 
{
	if (! avl.isEmpty()){return avl.find( str, set );}	
	else if (! bst.isEmpty()){return bst.find( str, set );
	}
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 SequenceMap<Comparable_1, Comparable_2>::findMin( ) const
{
	if (! avl.isEmpty()){return avl.findMin(  );}
	else if (! bst.isEmpty( ) ){return bst.findMin( );}
}

template <typename Comparable_1, typename Comparable_2>
const Comparable_1 SequenceMap<Comparable_1, Comparable_2>::findMax( ) const
{
	if (! avl.isEmpty()){return avl.findMax(  );}
	else if (! bst.isEmpty( ) ){return bst.findMax( );}
}

template <typename Comparable_1, typename Comparable_2>
bool SequenceMap<Comparable_1, Comparable_2>::findEnzyme( const Comparable_1 & x, const Comparable_2 & y ) const
{
	if (! avl.isEmpty()){return avl.findEnzyme( y );}
	else if (! bst.isEmpty( ) ){return bst.findEnzyme( y );}	
}

template <typename Comparable_1, typename Comparable_2>
bool SequenceMap<Comparable_1, Comparable_2>::operator< ( const Comparable_1 & rhs )
{
     if(this->key > rhs ){return true;}
     else{ return false;}
}

template <typename Comparable_1, typename Comparable_2>
SequenceMap<Comparable_1, Comparable_2>::~SequenceMap( )
{
     if (! avl.isEmpty()){ avl.makeEmpty(); }
     if (! bst.isEmpty()){ bst.makeEmpty(); }
}

template <typename Comparable_1, typename Comparable_2>
const int SequenceMap<Comparable_1, Comparable_2>::printNodeNumber( ) const
{
     if (! avl.isEmpty()){ avl.printNodeNumber(); }
     if (! bst.isEmpty()){ bst.printNodeNumber(); }
}
template <typename Comparable_1, typename Comparable_2>
void SequenceMap<Comparable_1, Comparable_2>::print (int order) const
{
     if (! avl.isEmpty()){ avl.print( order ); }
     if (! bst.isEmpty()){ bst.print( order ); }
}
template <typename Comparable_1, typename Comparable_2>
const int SequenceMap<Comparable_1, Comparable_2>::printDepth( ) const
{
     if (! avl.isEmpty()){ avl.printDepth(  ); }
     if (! bst.isEmpty()){ bst.printDepth(  ); }	
}
template <typename Comparable_1, typename Comparable_2>
void SequenceMap<Comparable_1, Comparable_2>::remove( const Comparable_1 & x )
{
     if (! avl.isEmpty()){ avl.remove( x ); }
     if (! bst.isEmpty()){ bst.remove( x ); }
}
template <typename Comparable_1, typename Comparable_2>
void SequenceMap<Comparable_1, Comparable_2>::lazydeletion ( const Comparable_1 & x) 
{
     if (! avl.isEmpty()){ avl.lazydeletion( x ); }
     if (! bst.isEmpty()){ bst.lazydeletion( x ); }
}
template <typename Comparable_1, typename Comparable_2>
void SequenceMap<Comparable_1, Comparable_2>::stats(double &avgd, int &height)
{
	 if (! avl.isEmpty()){ avl.stats( avgd, height ); }
     if (! bst.isEmpty()){ bst.stats( avgd, height ); }
}

template <typename Comparable_1, typename Comparable_2>
void SequenceMap<Comparable_1, Comparable_2>::makeEmpty( )
{
     if ( ! avl.isEmpty( ) ){ avl.makeEmpty( );}
     if ( ! bst.isEmpty( ) ){ bst.makeEmpty( );}
}
