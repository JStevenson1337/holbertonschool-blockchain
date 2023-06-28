#include "hqq
/**
 *
 * hash_matches_difficulty - Check if a hash matches the mining difficulty
 *
 * @hash: Hash to check
 * @difficulty: Difficulty to match
 *
 * Return: 1 if hash matches difficulty, otherwise 0
 */

int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH], uint32_t difficulty)
{
        uint32_t i, bit, bits;

        for (i = 0; i < difficulty / 8; i++)
        {
                if (hash[i] != 0)
                        return (0);
        }

        if (difficulty % 8 == 0)
                return (1);

        bit = 128;
        bits = difficulty % 8;

        while (bits--)
        {
                if (!(hash[i] & bit))
                        return (0);

                bit >>= 1;
        }

<<<<<<< HEAD
	return (1);
=======
        return (1);
>>>>>>> c92208d (Add: Test files)
}
