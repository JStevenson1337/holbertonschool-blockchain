# BLOCKCHAIN


## Resources

**Read or watch:**
[OpenSSL crypto library](https://intranet.hbtn.io/rltoken/uaP4WlPspoMWQ2uFa87FZg)
[Provided libraries and sources](https://intranet.hbtn.io/rltoken/PmVeCuu1InkxNbj9UJI6PA)

## Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of >Google:

### General

- How a Blockchain is considered “unbreakable”
- What is a hash algorithm
- What SHA stands for
- How hash algorithms apply to Blockchains
- What is asymmetric cryptography
- How asymmetric cryptography applies to cryptocurrencies
- What ECC stands for
- What ECDSA stands for
- What a digital signature is
- How digital signatures apply to cryptocurrencies


### Requirements
### General

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra, -pedantic and the linker flags -lssl and -lcrypto
- All your files should end with a new line
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- The prototypes of all your functions should be included in your header file called crypto/hblk_crypto.h
- All your header files should be include guarded

## More Info

### Dependencies

For this project, you will need to Install the OpenSSL library (if not already installed).

### Additional information
- Unless specified otherwise, you are allowed to use the C standard library
- You are free to use any data structure that suits you as long as their purpose is well defined
- You are free to print any information on stderr, this stream will be discarded during correction. Since you are going to use these utility functions in your Blockchain project, you are free to manage errors as you wish.
- At the end of this project, the structure of your repository should look like this (you may have additional files):

```

holbertonschool-blockchain
├── crypto
│   ├── ec_create.c
│   ├── ec_from_pub.c
│   ├── ec_load.c
│   ├── ec_save.c
│   ├── ec_sign.c
│   ├── ec_to_pub.c
│   ├── ec_verify.c
│   ├── hblk_crypto.h
│   ├── libhblk_crypto.a
│   ├── Makefile
│   ├── provided
│   │   └── _print_hex_buffer.c
│   ├── sha256.c
│   └── test
│       ├── ec_create-main.c
│       ├── ec_from_pub-main.c
│       ├── ec_load-main.c
│       ├── ec_save-main.c
│       ├── ec_sign-main.c
│       ├── ec_to_pub-main.c
│       ├── ec_verify-main.c
│       └── sha256-main.c
└── README.md

```