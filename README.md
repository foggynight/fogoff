# fogoff

File encryption utility.

Uses a rotate by character encryption algorithm with a variable length key, file
size is unchanged.

## Installation

1. Compile using the build.sh script

```
./build.sh
```

2. To run fogoff from anywhere, create a symlink

```
ln -s $(pwd)/fogoff /usr/local/bin/fogoff
```

## Usage

Input and output is done using the standard io streams i.e. the command
redirection and pipeline operators.

```
fogoff ${MODE} [-k|--key] ${KEY}

MODE:
- encrypt: [-e|--encrypt]
- decrypt: [-d|--decrypt]

KEY: Encryption key, if omitted, read from key.txt.

EXAMPLES:
fogoff -e <input.txt >output.txt
fogoff -d -k examplekey <input.txt >output.txt
```

Files can be encrypted multiple times with different keys, decrypt using
the keys in the reverse order they were input when encrypting.

```
fogoff -e -k key1 <input.txt | fogoff -e -k key2 | fogoff -e -k key3 >output.txt
```

**NOTE:** The encrypt and decrypt operations are inverse of each other, they can
be used in reverse order if desired.

## Dependencies

1. GNU C Compiler
