#include "blockchain.h"


block_t const NEW_GENESIS = {
	{
		0 /* index */,
		0, /* difficulty */
		1537578000, /* timestamp */
		0, /* nonce */
		{0} /* prev_hash */
	},
	{ /* buffer */
		"Holberton School", /* buffer */
		16 /* len */
	},
	GENESIS_HASH /* hash */
};

/**
 * block_is_valid - verify that a Block is valid
 * @block: block to query
 * @prev_block: previous block
 *  or is NULL if block is the first Block of the chain
 * Return: 0 if valid, 1 if invalid
 */
int block_is_valid(block_t const *block, block_t const *prev_block)
{
	uint8_t buff[SHA256_DIGEST_LENGTH];

	if (!block || (!prev_block && block->info.index))
	{
		{
			return (1);
		}
	}
	if (block->info.index == 0)
		{
			return (is_genesis(block));
		}
	if (block->info.index != prev_block->info.index + 1)
		{
			return (1);
		}
	block_hash(prev_block, buff);
	if (memcmp(buff, prev_block->hash, sizeof(buff)) != 0)
		{
			return (1);
		}
	if (memcmp(prev_block->hash, block->info.prev_hash,
		   SHA256_DIGEST_LENGTH) != 0)
		{
			return (1);
		}
	block_hash(block, buff);
	if (memcmp(buff, block->hash, sizeof(buff)) != 0)
		{
			return (1);
		}
	if (block->data.len > BLOCKCHAIN_DATA_MAX)
		{
			return (1);
		}
	return (0);
}

/**
 * is_genesis - verify if a genesis block
 * @block: pointer to current block
 * Return: 0 if valid | 1 if invalid
 */
int is_genesis(block_t const *block)
{
	return (memcmp(block, &NEW_GENESIS, sizeof(NEW_GENESIS)));
}