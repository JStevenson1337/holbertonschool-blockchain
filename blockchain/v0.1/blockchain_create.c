#include "blockchain.h"
/**
 *
 *
 *
 */
blockchain_t *blockchain_create(void)
{
	block_t *nb;
	blockchain_t *nc;


	nb = malloc(sizeof(block_t));
	if (nb == NULL)
	{
		free(nb);
		return NULL;
	}
	




}
