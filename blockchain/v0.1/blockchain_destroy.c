#include "blockchain.h"

/**
 * block_destroy - Destroy a block
 *
 * @block: pointer to the block to delete
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	if (!blockchain)
		return;
	llist_destroy(blockchain->chain, 1, NULL);
	free(blockchain);
}