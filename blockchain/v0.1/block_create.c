#include "blockchain.h"

/**
* block_create - Creates a new block on the chain
*
* @prev: pointer to the previous block
* @data: pointer to data to copy
* @data_len: lenght of data not exceeding BLOCKCHAIN_DATA_MAX
*
* Return: pointer to the block || NULL
*/
block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len)
{
	block_t *nb = NULL;

	nb = calloc(1, sizeof(*nb));

	if (nb == NULL)
	{
		return(NULL);
	}

	memcpy(&(nb->data.buffer), data,
	BLOCKCHAIN_DATA_MIN(data_len,
	BLOCKCHAIN_DATA_MAX));
	nb->data.len = BLOCKCHAIN_DATA_MIN(data_len, BLOCKCHAIN_DATA_MAX);
	nb->info.index = prev->info.index + 1;
	nb->info.timestamp = time(NULL);
	memcpy(&(nb->info.prev_hash), prev->hash, SHA256_DIGEST_LENGTH);
	return(nb);
}