## Setup (in VSCode)

First, download the source of SFML 3.0. Then, in the folder, run :

> sudo cmake -DBUILD_SHARED_LIBS=ON .

> sudo cmake .

> sudo make

> sudo make install

Then, add the path the `include` folder in `.vscode/c_cpp_properties.json`. Finally, update the library path in the Makefile.

## Installation

> sudo make clean install