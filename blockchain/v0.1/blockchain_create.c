#include "blockchain.h"
#include <llist.h>
#include <openssl/sha.h>
#include <string.h>

/**
* blockchain_create - creates a blockchain
*
* Return: pointer to Blochain || NULL
*/
blockchain_t *blockchain_create(void)
{
	blockchain_t *nbc = NULL;
	block_t *nb = NULL;
	llist_t *blist = NULL;

	nbc = calloc(1, sizeof(*nbc));
	nb = calloc(1, sizeof(*nb));
	blist = llist_create(MT_SUPPORT_TRUE);

	if (nbc == NULL || nb == NULL || blist == NULL)
	{
		free(nbc);
		free(nb);
		free(blist);
		return NULL;
	}
	nb->info.timestamp = 1537578000;
	memcpy(&(nb->data.buffer), "Holberton School", 16);
	nb->data.len = 16;
	memcpy(&(nb->hash), "\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03", SHA256_DIGEST_LENGTH);


	if (llist_add_node(blist, nb, ADD_NODE_FRONT))
	{
		free(nbc), free(nb), llist_destroy(blist, 1, NULL);
		return (NULL);
	}
	nbc->chain = blist;
	return (nbc);

}