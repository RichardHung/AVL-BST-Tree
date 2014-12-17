#include "SequenceMap.h"
#include <iostream>
#include <fstream>   // output file   
#include <istream>   // input file  
#include <string>    // OPTION
#include <unistd.h>  // for argc and argv[]

void command()
{
    cout << "?   ==> display this help information" << endl;
    cout << "d   ==> display average node depth and tree height" << endl;
    cout << "e   ==> empty the tree" << endl;
    cout << "l # ==> remove the node containing the given string by lazy deletion" << endl;
    cout << "m   ==> display minimum key in the tree" << endl;
    cout << "M   ==> display maximum key in the tree" << endl;
    cout << "p # ==> print the tree:" << endl;
    cout << "        # < 1 for preorder" << endl;
    cout << "        # = 1 for inorder" << endl;
    cout << "        # > 1 for postorder" << endl;
    cout << "r # ==> remove node containing the given string" << endl;
    cout << "q   ==> quit" << endl;
}

int openfail(ifstream *fin){	if (!fin)	{		cout << "file open fail\n";		system("PAUSE");		return -1;	}	return 0;}    

int main( )
{
    string tree = "AVL";				 // AVL, BST
    SequenceMap< string , string > map; 
	string sequence;
	string enzyme;    
    string x;			// movement command
    char action;		// the action character
    int p = 0;		    // which tree are we using (0 or 1)
    double avgd;		// average depth of nodes in tree
    int height;			// height of tree

    cout << "AVL Tree and BS Tree tree program ( with lazy deletion )\n\n" ;
    
    ifstream fin( "rebase210.txt" ); 
    openfail(&fin);		
    while( true ) 
    {
		while ( ! fin.eof( ) )
	    {			
	        if ( fin.peek( ) == '/' )
	        {
	        	fin.get();		// skip "/" and move ptr to next sequence
	            while ( fin.peek() != '\n' ) 
	            {
	            	getline(fin, sequence, '/');
					cout << "enzyme: " << enzyme << endl;
					cout << "sequence: " << sequence << endl;
					map.insert(tree, sequence, enzyme);
					sequence.clear();
					fin.get();	// skip "/" and move ptr to next sequence
		            if(fin.peek() == '/')
		            	fin.get();					
	            }
	            fin.get();
	            enzyme.clear();
	        }
	        else // if( enz != '/' )
	        {
	          	enzyme += fin.get( );
	        }

	    }
/*    
    command();   // Command list 
    

        cout << "$ ";
    	if ( cin >> action) 
    	{
                switch( action ) 	// get action and switch
                {
            	    // Compute and display average node depth and tree height
            	    case 'd':
            	    case 'D':
            		map.stats(avgd, height);
            		cout << "Average node depth = " << avgd << endl;
            		cout << "Tree height = " << height << endl;
            		continue;
                             
            	    // Empty a tree
            	    case 'e':
            	    case 'E':
            		map.makeEmpty();
            		continue;
                    
                    case 'l':
            	    case 'L':
                    cin >> x;
            		map.lazydeletion(x);
            		continue;
            
            	    case 'm':
                    case 'M':
            		if (map.isEmpty()) cout << "Tree is empty." << endl;
            		else cout << "Maximum key is " << map.findMax() << endl;
            		continue;
            
            	    case 'p':
            	    case 'P':
            	    cout << "0: Pre-Order. 1:In-Order. 2:Post-Order.\n"	;
            		cin >> p;				// get traveral order
            		map.print(p);			// print the tree
            		continue;
            
            	    // Terminate the program
            	    case 'q':
            	    case 'Q':
            		return 0;
            
            	    // Remove a node from the tree
            	    case 'r':
            	    case 'R':
            		cin >> x;
            		map.remove(x);
            		continue;
            
            	    // Display help information
            	    case '?':
            		command();
            		continue;
            
            	    // Unknown action character
            	    default:
            		cout << "Unknown action" << endl;
            		continue;
            
            	}
        }
        else 
        {
             break;
        }
*/    
	}


	
    fin.close();  
	return 0;
}
