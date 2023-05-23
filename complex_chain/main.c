#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef unsigned char byte;

void mine(char* block, byte* difficulty, int difficulty_length);
void hashs(char* block_with_nonce, byte* hash);
//void hash_block2(struct Block* block, byte* hash);

//task 2 
struct BlockHeader {
    byte previous_block_hash[SHA256_DIGEST_LENGTH];
    byte merkle_root[SHA256_DIGEST_LENGTH];
    uint32_t timestamp;
    uint32_t difficulty;
    uint32_t nonce;
};

struct Block {
    struct BlockHeader header;
    char* data;
};

void hash_block2(struct Block* block, byte* hash) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, block->header.previous_block_hash, SHA256_DIGEST_LENGTH);
    SHA256_Update(&sha256, block->header.merkle_root, SHA256_DIGEST_LENGTH);
    SHA256_Update(&sha256, &block->header.timestamp, sizeof(block->header.timestamp));
    SHA256_Update(&sha256, &block->header.difficulty, sizeof(block->header.difficulty));
    SHA256_Update(&sha256, &block->header.nonce, sizeof(block->header.nonce));
    SHA256_Update(&sha256, block->data, strlen(block->data));
    SHA256_Final(hash, &sha256);
}
//
void hashs(char* block_with_nonce, byte* hash) {
    SHA256((const byte*)block_with_nonce, strlen(block_with_nonce), hash);

}

void mine(char* block, byte* difficulty, int difficulty_length) {
    int nonce = 0;
    byte hash[SHA256_DIGEST_LENGTH];
    char block_with_nonce[100];
    
    //task1 
    uint64_t hash_64 = 0; // Initialize hash_64 to 0
    //
    while (1) {
        sprintf(block_with_nonce, "%s%d", block, nonce);
        hashs(block_with_nonce, hash);
        //task1 
        hash_64 = 0; // Reset hash_64 for each hash
        for (int i = 0; i < 8; i++) {
            hash_64 ^= ((uint64_t) hash[i]) << (i * 8);
        }
        //
        int is_valid_solution = 1;
        for (int i = 0; i < difficulty_length; i++) {
            if (hash[i] > difficulty[i]) {
                is_valid_solution = 0;
                break;
            } else if (hash[i] < difficulty[i]) {
                break;
            }
        }
        if (is_valid_solution) {
            printf("Mining successful! Nonce: %d, Hash: ", nonce);
            for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
                printf("%02x", hash[i]);
            }
            printf("\n");
            return;
        }
        nonce++;
    }
}
//task 2
void mining(struct Block* block)
{
     int mining = 1;
    while (mining) {
        block->header.nonce++;
        byte hash[SHA256_DIGEST_LENGTH];
        hash_block2(block, hash);
        int is_valid_solution = 1;
        for (int i = 0; i < 4; i++) {
            if (hash[i] > (block->header.difficulty >> (i * 8)) & 0xFF) {
                is_valid_solution = 0;
                break;
            }
        }
        if (is_valid_solution) {
            printf("Mining successful! Nonce: %u, Hash: ", block->header.nonce);
            for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
                printf("%02x", hash[i]);
            }
            printf("\n");
            mining = 0;
        }
    }
}
//
int main() {
    char block[] = "Hello, world!";
    byte difficulty[] = {0xff, 0xff, 0xff, 0xff}; // 32 bits of difficulty
    mine(block, difficulty, 4);
    //task2 
    struct Block blockmin = {
        .header = {
            .previous_block_hash = {0},
            .merkle_root = {0},
            .timestamp = 1234567890,
            .difficulty = 0xffffffff,
            .nonce = 0
        },
        .data = "Hello, world!"
    };
    mining(&blockmin);
    return 0;
}
