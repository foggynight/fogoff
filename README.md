# fogoff

File encryption utility.

Uses a rotate by character encryption algorithm with a variable length key, file
size is unchanged.

## Installation

```
git clone https://github.com/foggynight/fogoff
cd fogoff
make
```

## Usage

Input and output is done using the standard IO streams. i.e. using the command
redirection and pipeline operators.

```
fogoff [MODE] [-k|--key] <KEY>

MODE:
- encrypt: -e | --encrypt
- decrypt: -d | --decrypt

KEY: If omitted, encryption key is read from key.txt.

EXAMPLES:
fogoff -e <input.txt >output.txt
fogoff -d -k examplekey <input.txt >output.txt
```

Files can be encrypted multiple times with different keys, decrypt using
the keys in the reverse order they were input when encrypting.

```
fogoff -e -k key1 <input.txt \
| fogoff -e -k key2 \
| fogoff -e -k key3 >output.txt
```

**NOTE:** The encrypt and decrypt operations are inverse of each other, they can
be used in reverse order if desired.

## Dependencies

- GNU C Compiler
