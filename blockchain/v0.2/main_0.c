/* Description: Difficulty 255 bits (matches) */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "blockchain.h"

/**
 * _print_hex_buffer - Prints a buffer in its hexadecimal form
 *
 * @buf: Pointer to the buffer to be printed
 * @len: Number of bytes from @buf to be printed
 */
static void _print_hex_buffer(uint8_t const *buf, size_t len)
{
	size_t i;

	for (i = 0; buf && i < len; i++)
		printf("%02x", buf[i]);

	fflush(NULL);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	uint8_t hash[SHA256_DIGEST_LENGTH];
	uint32_t difficulty;

	memset(hash, 0, SHA256_DIGEST_LENGTH);
	hash[31] = 1;
	difficulty = SHA256_DIGEST_LENGTH * 8 - 1;
	printf("Hash: ");
	_print_hex_buffer(hash, SHA256_DIGEST_LENGTH);
	printf("\nDifficulty: %u\n", difficulty);
	if (hash_matches_difficulty(hash, difficulty))
		printf("Matches difficulty\n");
	else
		printf("Doesn't match difficulty\n");

	return (EXIT_SUCCESS);
}