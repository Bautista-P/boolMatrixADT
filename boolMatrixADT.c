#include "boolMatrixADT.h"
#include <stdlib.h>


typedef struct cols
{
    size_t col;
    struct node * tail;
}Tcol;

typedef Tcol * ListCol;


typedef struct row
{
    size_t row;
    ListCol firstCol;
    struct row * tail;
}Trow;

typedef Trow * ListRow;

typedef struct boolMatrixCDT
{
    ListRow FirstRow;
}boolMatrixCDT;



/*
 * Crea una matriz con todos los elementos en falso
 */
boolMatrixADT newBoolMatrix(void)
{
    boolMatrixADT new = calloc(1, sizeof(boolMatrixCDT));
    return new;
}

ListCol addCol(ListCol l , size_t col)
{
    if(l == NULL || col < l->col)
    {
        ListCol aux = malloc(sizeof(*aux));
        aux->col = col;
        aux->tail = l;
    }
    if(col > l->col)
        l->tail = addCol(l->tail, col);
    return l;
}

ListRow addRow(ListRow l , size_t row, size_t col)
{
    if(l == NULL || row < l->row)
    {
        ListRow aux = malloc(sizeof(*aux));
        aux->row = row;
        aux->tail = l;
        aux->firstCol = addCol(NULL, col); // le paso un null ya que al hacer un malloc nose que hay en el aux->firstColl;
        return aux;
    }
    if(row == l->row)
    {
        l->firstCol = addCol(l->firstCol, col);
        return l;
    }
    l->tail = addRow(l->tail , row , col);
    return l;
}

ListCol removeCol(ListCol l , size_t col)
{
    if(l == NULL || l->col > col)
        return l;
    if(l->col == col)
    {
        ListCol aux = l->tail;
        free(l);
        return aux;
    }
    l->tail = removeCol(l->tail, col);
    return l;
}

ListRow removeRow(ListRow l , size_t row, size_t col)
{
    if( l == NULL || l->row > row )
        return l;
    if(l->row == row)
    {
        l->firstCol = removeCol(l->firstCol, col);
        //si no quedan elementos en la fila entonces la elimino;
        if(l->firstCol == NULL){
            ListRow aux = l->tail;
            free(l);
            return aux;
        }
        return l;
    }
    l->tail = removeRow(l->tail, row, col);
    return l;
}

/*
** Si @value es true entonces m[row][col] = value
** Si @value es false entonces borra m[row][col]
*/
void setValue(boolMatrixADT m, size_t row, size_t col, boolean value)
{
    if(value)
    {
        m->FirstRow = addRow(m->FirstRow , row , col);
    }
    else 
        m->FirstRow = removeRow(m->FirstRow , row , col );

}

boolean belongsCol(ListCol l,size_t col)
{
    if(l == NULL || l->col > col)
        return false;
    if(l->col == col)
    {
        return true;
    }
    return belongsCol(l->tail, col);
}

boolean belongs(ListRow l,size_t row , size_t col)
{
    if(l == NULL || l->row > row)
        return false;
    if(l->row == row)
    {
        return belongsCol(l->firstCol , col);
    }
    return belongs(l->tail, row, col);
}

/*
 * Retorna el valor almacenado en m[row][col]
 */
boolean getValue(const boolMatrixADT m, size_t row, size_t col)
{
    return belongs(m->FirstRow, col, row);
}

void freeCol(ListCol l)
{
    if(l == NULL)
        return;
    freeCol(l->tail);
    free(l);
}

void freeRow(ListRow l)
{
    if(l == NULL)
        return;
    freeCol(l->firstCol);
    freeRow(l->tail);
    free(l);
}


/*
 * Libera toda la memoria reservada
 */
void freeBoolMatrix(boolMatrixADT m)
{
    freeRow(m->FirstRow);
    free(m);
}