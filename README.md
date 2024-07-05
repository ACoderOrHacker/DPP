<div align="center">

# D++
[![license](https://badgen.net/github/license/ACoderOrHacker/DPP)](https://github.com/ACoderOrHacker/DPP/blob/master/LICENSE)
[![releases](https://badgen.net/github/releases/ACoderOrHacker/DPP)](https://github.com/ACoderOrHacker/DPP/releases/)
[![branches](https://badgen.net/github/branches/ACoderOrHacker/DPP)]()
[![tags](https://badgen.net/github/tags/ACoderOrHacker/DPP)](https://github.com/ACoderOrHacker/DPP/tags)
[![version](https://badgen.net/github/release/ACoderOrHacker/DPP)]()

</div>

---
**D++** is a power, fast programming language.

### Overview

This repository is structured into the following directories.
Refer to their respective `README.md` for more in-depth information.

| Directory                                | Description                                      |
|------------------------------------------|--------------------------------------------------|
| [changelog](CHANGELOG)                   | changelog entries for the upcoming release       |
| [src/compiler](src/compiler)             | source code, build system and build instructions |
| [src/compiler/test](src/compiler/test)   | tests and testing infrastructure                 |
| [docs](doc/compiler/index.md)            | man pages and internal documentation             |
| [compiler/samples](src/compiler/samples) | Various code examples                            |
| [runtime](src/runtime/)                  | root of runtime                                  |

### Build

#### Windows(MSVC)
```
python tools/build.py --msvc
```

#### Linux
```
python tools/build.py
```

### IDES

