<h1 align="center">Spaceship Operator Examples</h1>
<p align="center">How the <code><=></code> operator can be used to reduce boilerplate code.<br>
<p align="center">
    <a href="/../../actions/workflows/cmake.yml">
        <img src="/../../actions/workflows/cmake.yml/badge.svg">
    </a>
    <a href="LICENSE">
        <img src="https://img.shields.io/badge/License-MIT-yellow.svg">
    </a>
</p>

***


## Building and testing
### Manually
Build the project using cmake and a compiler with C++ 20 abilities. Most modern compilers should work. Making the file will result in the unit tests getting executed automatically.

```shell
git clone https://github.com/EliseBriers/spaceship-operator-examples
cd std-accumulate-examples
mkdir build
cd build
cmake ..
cmake --build .
```

### Visual Studio (Windows)
The easiest way to build and run the project on windows is opening it in a recent version of Vidual Studio. This project has been tested using Visual Studio 2022.
