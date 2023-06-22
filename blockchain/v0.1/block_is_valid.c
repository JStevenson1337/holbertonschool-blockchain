#include "blockchain.h"


block_t const NEW_GENESIS = {
        {
                0 /* index */,
                0, /* difficulty */
                GENESIS_TIME, /* timestamp */
                0, /* nonce */
                {0} /* prev_hash */
        },
        { /* buffer */
                GENESIS_DATA, /* data */
                16 /* len */
        },
        GENESIS_HASH /* hash */
};
/**
 * block_is_valid - validates a block
 *
 * @block: block to validate
 * @ prev_block: previous block
 * @ Return: 0 if valid else 1
 */
int block_is_valid(block_t const *block, block_t const *prev_block)
{
        uint8_t buff[SHA256_DIGEST_LENGTH];

        if (!block || (!prev_block && block->info.index != 0))
                return (1);
        if (block->info.index == 0)
		return (memcmp(block, &NEW_GENESIS, sizeof(NEW_GENESIS)));
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
