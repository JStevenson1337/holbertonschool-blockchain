#include <blockchain.h>

/**
 * blockchain_difficulty - calculaters difficulty to assign to next block
 * @blockchain: pointer to the chain
 * Return: difficulty to assign
 **/
uint32_t blockchain_difficulty(blockchain_t const *blockchain)
{
	block_t *block, *last_adjusted_block;
	uint64_t actual_time;

	if (!blockchain || !(block = llist_get_tail(blockchain->chain)))
		return (0);


	if (block->info.index && !(block->info.index % DIFFICULTY_ADJUSTMENT_INTERVAL))
	{
		last_adjusted_block = llist_get_node_at(blockchain->chain, block->info.index - DIFFICULTY_ADJUSTMENT_INTERVAL + 1);
		actual_time = block->info.timestamp - last_adjusted_block->info.timestamp;

		if (actual_time < EXPECTED_TIME_BETWEEN_ADJUSTMENTS / 2)
			return (block->info.difficulty + 1);

		if (actual_time > EXPECTED_TIME_BETWEEN_ADJUSTMENTS * 2)
			return (block->info.difficulty - !!block->info.difficulty);
	}

	return (block->info.difficulty);
}