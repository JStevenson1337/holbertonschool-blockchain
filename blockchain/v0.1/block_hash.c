#include "blockchain.h"
/**
 * block_hash - computes the hash of a Block
 * @block: pointer to block to be hashed
 * @hash_buf: where hash will be stored
 * Return: pointer to hash_buf
 **/
uint8_t *block_hash(block_t const *block, uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	if (!block)
		return (NULL);
	
	SHA256((const unsigned char *)block, sizeof(block->info) + block->data.len, hash_buf);
	return (hash_buf);
}
