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

	if (!block)
		return (1);
	if (block->info.index == 0)

	{
		if (block->data.len != NEW_GENESIS.data.len)
			return (1);
		if (memcmp(block->data.buffer, NEW_GENESIS.data.buffer,
			block->data.len))
			return (1);
		if (block->info.timestamp != NEW_GENESIS.info.timestamp)
			return (1);
		if (block->info.difficulty != NEW_GENESIS.info.difficulty)
			return (1);
		if (block->info.nonce != NEW_GENESIS.info.nonce)
			return (1);
		if (memcmp(block->info.prev_hash, NEW_GENESIS.info.prev_hash,
			SHA256_DIGEST_LENGTH))
			return (1);
		if (memcmp(block->hash, NEW_GENESIS.hash, SHA256_DIGEST_LENGTH))
			return (1);
		return (0);
	}
	if (!prev_block)
		return (1);
	if (block->info.index != prev_block->info.index + 1)
		return (1);
	if (!block_hash(prev_block, buff) ||
		memcmp(buff, block->info.prev_hash, SHA256_DIGEST_LENGTH))
		return (1);
	if (!block_hash(block, buff) ||
		memcmp(buff, block->hash, SHA256_DIGEST_LENGTH))
		return (1);
	if (block->data.len > BLOCKCHAIN_DATA_MAX)
		return (1);
	return (0);
}
