# fogoff

File encryption utility.

Uses a rotate by character encryption algorithm with a variable length key, file
size is unchanged.

## Installation

By default fogoff will be installed in `~/.local/bin/`, although fogoff can also
be used directly from the repo directory.

```bash
git clone https://github.com/foggynight/fogoff
cd fogoff
make
cp fogoff ~/.local/bin/
```

**Note:** Should fogoff be called from the bin, the key must be provided as a
command line argument. Call fogoff from the repo directory to utilize
`key.txt`.

## Usage

Input and output is done using the standard IO streams. i.e. using the command
redirection and pipeline operators.

```bash
fogoff [MODE] [-k|--key KEY]
```

**MODE:**
- encrypt: `-e|--encrypt`
- decrypt: `-d|--decrypt`

**KEY:** If omitted, the key is read from `key.txt`.

**Examples:**
```bash
fogoff -e <input.txt >output.txt
fogoff -d -k examplekey <input.txt >output.txt
```

Files can be encrypted multiple times with different keys, decrypt using
the keys in the reverse order they were input when encrypting.

```bash
fogoff -e -k key1 <input.txt \
| fogoff -e -k key2 \
| fogoff -e -k key3 >output.txt
```

**Note:** The encrypt and decrypt operations are inverse of each other, they can
be used in reverse order if desired.

## Dependencies

- GNU C Compiler
