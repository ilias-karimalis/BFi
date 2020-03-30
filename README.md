# BFi

BFi is a brainfuck interpreter written in C. More information can be found at
[https://en.wikipedia.org/wiki/Brainfuck]

## How to build

See `Makefile` for the build script.

To build the interpreter, simply run `make` or `make BFi`
at the command line in the current directory.

By default, this will generate an executable name `BFi`, which is the name bound
to it in the `Makefile`. To then run the program, run


```bash
./BFi <brainfuck file>
```

in the project directory.

## Example Usage

```bash
./BFi programs/helloworld.bf
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
