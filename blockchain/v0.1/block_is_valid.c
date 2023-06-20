#include <blockchain.h>

block_t const NEW_GENESIS = {
	{
		0,
		0,
		1537578000,
		0,
		{0}
	},
	{
		GENESIS_DATA,
		16
	},
	GENESIS_HASH
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
	if ((block->info.index != NEW_GENESIS.info.index) ||
	    (block->info.difficulty != NEW_GENESIS.info.difficulty) ||
	    (block->info.timestamp != NEW_GENESIS.info.timestamp) ||
	    (block->info.nonce != NEW_GENESIS.info.nonce) ||
	    (memcmp(block->info.prev_hash, NEW_GENESIS.info.prev_hash,
		    SHA256_DIGEST_LENGTH)) ||
	    (block->data.len != NEW_GENESIS.data.len) ||
	    (memcmp(block->data.buffer, NEW_GENESIS.data.buffer,
		    NEW_GENESIS.data.len) != 0) ||
	    (memcmp(block->hash, NEW_GENESIS.hash, SHA256_DIGEST_LENGTH) != 0))
		return (1);
	return (0);
}