<div align="center">
  <a align="center" href="https://www.youtube.com/watch?v=dUOLH_SjlHA">
    <img src="https://img.youtube.com/vi/dUOLH_SjlHA/mqdefault.jpg" width=30%>
  </a>
  <h1>The spaceship operator (<=>)</h1>
  <p>
    Git repo for the video <a href="https://www.youtube.com/watch?v=dUOLH_SjlHA">Reduce Boilerplate Code With The C++ Spaceship Operator (<=>)</a>.
    <br>
    <sub>By <a href="https://www.youtube.com/@ElisePlusPlus">Elise++</a></sub><br><br>
    <a href="/../../actions/workflows/cmake.yml">
      <img src="/../../actions/workflows/cmake.yml/badge.svg">
    </a>
    <a href="LICENSE">
      <img src="https://img.shields.io/badge/License-MIT-yellow.svg">
    </a>
  </p>
</div>

***

## Introduction
This repo contains all the code files shown in the video [Reduce Boilerplate Code With The C++ Spaceship Operator (<=>)](https://www.youtube.com/watch?v=dUOLH_SjlHA). It shows an example of how this new operator can reduce boilerplate code by auto generating most of the other operators.

## Building and testing
### Manually
Build the project using cmake and a compiler with C++ 20 abilities. Most modern compilers should work. Making the file will result in the unit tests getting executed automatically.

```shell
git clone https://github.com/EliseBriers/spaceship-operator-examples
cd spaceship-operator-examples
mkdir build
cd build
cmake ..
cmake --build .
```

### Visual Studio (Windows)
The easiest way to build and run the project on windows is opening it in a recent version of Vidual Studio. This project has been tested using Visual Studio 2022.
