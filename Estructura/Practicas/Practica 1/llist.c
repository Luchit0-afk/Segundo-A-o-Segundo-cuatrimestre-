/*
 * Copyright (c) 2018 Valentin Cassano.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * The header list.h is used in files which need to know of the interface.
 * The main idea is to keep this whole file as a standalone implementation
 * of the interface.
 */

// object of an incomplete type
typedef struct list_s* list_t;

typedef struct linkable_s* linkable_t;

struct linkable_s
{
	int content;
	struct linkable_s *next;
};

/* struct list_s is the realization of list_t (declared in list.h) */
struct list_s
{
	linkable_t head;
	int size;
};

linkable_t create( int element )
{
	linkable_t linkable = ( linkable_t ) malloc ( sizeof( struct linkable_s ) );

	linkable->content = element;
	linkable->next    = NULL;

	return linkable;
}

// returns an empty list
list_t make( void )
{
	list_t llist = ( list_t ) malloc ( sizeof( struct list_s ) );

	llist->head = NULL;
	llist->size = 0;

	return llist;
}

// is the list empty?
int is_empty( list_t llist )
{
	return ( llist->size == 0 );
}

int length( list_t llist )
{
	return llist->size;
}

// adds an element at the beginning of the list
list_t add( list_t llist, int element )
{
	linkable_t linkable = create( element );

	linkable->next = llist->head;
	llist->head = linkable;
	llist->size = (llist->size) + 1;

	return llist;
}

// inserts an element in a particular position in the list
/*  0 if successful              
 * -1 if the position is invalid */
int ins( list_t llist, int element, int position)
{
	if ( position < 0 || position > llist->size )
	{
		return -1;
	};

	if ( !position )
	{
		add( llist, element );
		return 0;
	}

	/* move the cursor to the indicated position */
	linkable_t cursor = llist->head;

	for ( int i = 0; i < position - 1; i++ )
	{
		cursor = cursor->next;
	};

	/* create the new node */
	linkable_t linkable = create( element );

	/* link the two nodes */
	linkable->next = cursor->next;
	cursor->next = linkable;

	/* increase the number of elements in the list */
	llist->size = (llist->size) + 1;

	return 0;
}

// adds an element at the end of the list
list_t end( list_t llist, int element )
{
	ins( llist, element, llist->size );

	return llist;
}

// removes the head of the list (deletes its first element)
/*  0 if successful
 * -1 if the list is empty */
list_t bhd( list_t llist )
{
	if ( is_empty( llist ) )
	{
		return NULL;
	}

	linkable_t cursor = llist->head;
	llist->head = (llist->head)->next;

	// frees the memory that has been allocated using malloc
	free( cursor );

	llist->size = (llist->size) - 1;

	return llist;
}

// returns the element at the indicated position
/* the position must be valid */
int at( list_t llist, int position )
{
	linkable_t cursor = llist->head;

	for ( int i = 0; i < position ; i++ )
	{
		cursor = cursor->next;
	};

	return cursor->content;
}

// deletes an element in a particular position in the list
/*  0 if successful
 * -1 if the position is invalid or the list is empty */
int del( list_t llist, int position)
{
	if ( position < 0 || position > llist->size )
	{
		return -1;
	};

	if ( is_empty( llist ) )
	{
		return -1;
	}

	if ( !position )
	{
		bhd( llist );

		return 0;
	}

	/* move the cursor to the indicated position */
	linkable_t cursor = llist->head;

	for ( int i = 0; i < position - 1; i++ )
	{
		cursor = cursor->next;
	};

	linkable_t linkable = cursor->next;
	cursor->next = (cursor->next)->next;
	// frees the memory that has been allocated using malloc for list node
	free( linkable );

	llist->size = (llist->size) - 1;

	return 0;
}

// the reverse of a list
list_t reverse( list_t llist )
{
	list_t result = make();

	for ( int i = 0; i < llist->size ; i++ )
	{
		add( result, at( llist, i ));
	};

	return result;
}

// the concatenation of the lists
list_t cat( list_t front, list_t rear )
{
	list_t result = make();

	for ( int i = 0; i < front->size ; i++ )
	{
		end( result, at( front, i ));
	};

	for ( int i = 0; i < rear->size ; i++ )
	{
		end( result, at( rear, i ));
	};

	return result;
}

// the sub-list starting at 'from' and ending at 'to'
list_t sub( list_t llist, int s, int e )
{
	list_t result = make();

	for ( int i = s; i < e ; i++ )
	{
		end( result, at( llist, i ));
	};

	return result;
}

// a copy of the list
list_t cpy( list_t llist )
{
	return sub( llist, 0, llist->size );
}

// the first element of a non-empty list
int hd( list_t llist )
{
	return (llist->head)->content;
}

// all but the first element of a list
list_t tl( list_t llist )
{
	return sub( llist, 1, llist->size );
}

// displays the content of the list on the std output
void show( list_t llist)
{
	printf( "[ " );

	for ( int i = 0; i < llist->size; i++ )
	{
		printf( "%i ", at( llist, i ) );
	};

	printf( "]" );
}

//reemplazar que dada una lista l, un elemento e y una posición i,
//la función deberá reemplazar el elemento que estaba en la
//posición i de l con e y retornar el elemento que estaba
//previamente en la posición i.
int reemplazar(list_t list , int elem , int pos){
//Local lexicon
	int elemR;
//start the action
	elemR = at(list,pos);
	ins(list,elem,pos);
	del(list,pos++);
	return elemR;
}

//intercambiar, que dada una lista l y dos posiciones de elementos
//enteros p1 y p2, la función los intercambia.
int intercambiar(list_t list,int pos1,int pos2){
//local lexicon
	int elemPos1;
	int elemPos2;
//start the action
	elemPos1 = at(list,pos1);
	elemPos2 = at(list,pos2);
	reemplazar(list,elemPos1,pos2);
	reemplazar(list,elemPos2,pos1);
}

