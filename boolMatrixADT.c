#include "boolMatrixADT.h"
#include <stdlib.h>


/*
 * Crea una matriz con todos los elementos en falso
 */
boolMatrixADT newBoolMatrix(void);

/*
** Si @value es true entonces m[row][col] = value
** Si @value es false entonces borra m[row][col]
*/
void setValue(boolMatrixADT m, size_t row, size_t col, boolean value);

/*
 * Retorna el valor almacenado en m[row][col]
 */
boolean getValue(const boolMatrixADT m, size_t row, size_t col);

/*
 * Libera toda la memoria reservada
 */
void freeBoolMatrix(boolMatrixADT m);