#include <blockchain.h>
#include <string.h>

/**
 * is_genesis_block - checks if a block is the Genesis block
 * @block: pointer to block
 * Return: 1 if it is, 0 if it isn't
 **/
static int is_genesis_block(block_t const *block)
{
	static uint8_t buf[SHA256_DIGEST_LENGTH] = {0};

	return (
		block->data.len == sizeof(GENESIS_DATA) - 1 &&
		!memcmp(block->data.buffer, GENESIS_DATA, block->data.len) &&
		!block->info.index &&
		!block->info.difficulty &&
		!block->info.nonce &&
		block->info.timestamp == GENESIS_TIME &&
		!memcmp(block->info.prev_hash, buf, sizeof(buf))
	);
}

/**
 * block_is_valid - QUERIES THE VALIDITY OF A BLOCK
 * @block: POINTER TO CURRENT BLOCK
 * @prev_block: PREVIOUS BLOCK
 * Return: 1 IF VALID ||| 0
 **/
int block_is_valid(block_t const *block, block_t const *prev_block)
{
	uint8_t temp[SHA256_DIGEST_LENGTH];

	if (!block)
	{
		return (1);
	}
	if (!block->info.index)
	{
		return (prev_block || !is_genesis_block(block));
	}
	if (!prev_block)
	{
		return (1);
	}
	if (block->info.index != prev_block->info.index + 1)
	{
		return (1);
	}

	if (block->data.len > BLOCKCHAIN_DATA_MAX)
	{
		return (1);
	}
	if (!block_hash(block, tmp))
	{
		return (1);
	}

	if (memcmp(tmp, block->hash, sizeof(tmp)))
	{
		return (1);
	}
	if (!block_hash(prev_block, tmp))
	{
		return (1);
	}

	if (memcmp(tmp, block->info.prev_hash, sizeof(tmp)))
	{
		return (1);
	}
	return (0);
}
