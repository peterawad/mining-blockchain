
## <center> Assignment 2 </center>

# needed library for 2 tasks 
stdio.h, stdlib.h, string.h ,openssl/sha.h

## Task 1 - Hashing

we are going to implement a “miner” using SHA-256 hashing.
so we need to  :
# declare function named " hashs" 
- take parameters pointer called block_with_nonce,length of string 
block_with_nonce and hash.
- using SHA-256 (cryptographic hash function) take 3 parmeters and outputs 
a value that is 256 bits long.

# we need to define
- unsigned char named "byte" 

# make function named "mine"
- take 3 parameters two pointer block and difficulty and difficulty length.
- intilize integer varabile define nonce ,and unsiged char named hash with 
SHA256 DIGEST LENGTH, charachter array called block_with_nonce with length 100.
- Initialize  unsigned integers "hash_64" and set to 0 
- make loop:
    - use function sprintf that sends (block,nonce) formatted output to a string 
    pointed to, by block_with_nonce.
    - calling hashs function and (block_with_nonce, hash);
    - Reset hash_64 for each hash
    - make aloop make xor all of the bytes of the 256-bit hash together
    - check valdition if hash less than difficulty is valid else not valid
    - after we sure is valid we print nonce and hash 
    - increment nonce

# calling in main :
- define array called block
- define array form byte type called  difficulty( 32 bits of difficulty)
- calling function "mine" and give parameter block, difficulty, 4 as length of difficulity

## Task 2 - Mining 

# we need to define
- struct BlockHeader has previous_block_hash , merkle_root 
(simple method for make a tree),timestamp,difficulty,nonce
- struct Block contains BlockHeader , pointer of Data
    
# make function "hash_block2":
- take parmeter two pointer block and  hash
- define SHA256_CTX 
- update previous_block_hash,merkle_root with SHA256_DIGEST_LENGTH
- Update timestamp as header.timestamp
- Update difficulty as header.difficulty
- Update header as header.nonce
- update the block data 
- after all data updater store in hash

# make function "mining":
- take parmeter block
- intilize mining with 1
- make aloop :
    - increment block header nonce with one.
    - define hash with SHA256 DIGEST LENGTH.
    - calling function hash_block2 and send parameter block and hash.
    - check valdition if hash less than difficulty is valid else not valid
    - after we sure is valid we print nonce and hash        

# calling in main 
- define struct Block called blockmin: 
    - with data and header (previous_block_hash, merkle_root, timestamp , difficulty , nonce ) 
- calling function called "mining" and send blockmin as a parameter.
