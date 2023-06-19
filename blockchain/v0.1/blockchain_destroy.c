#include "blockchain.h"

/**
 * block_destroy - Destroy a block
 *
 * @block: pointer to the block to delete
 */
 void blockchain_destroy(blockchain_t *blockchain)
{
	llist_destroy(blockchain->chain, true, (node_dtor_t)block_destroy);
	free(blockchain);
}