# 📖 Kompletny Tutorial CMake

## 🔹 Wstęp
CMake to narzędzie do zarządzania procesem budowania oprogramowania. Pozwala na przenośną konfigurację i kompilację kodu źródłowego na różnych platformach.

---

## 🛠 Instalacja CMake

**Linux (Ubuntu/Debian):**
```sh
sudo apt update && sudo apt install cmake
```

**macOS (Homebrew):**
```sh
brew install cmake
```

**Windows:** Pobierz instalator z [cmake.org](https://cmake.org/download/) i dodaj go do PATH.

---

## 📁 Struktura Projektu

```
HelloLibrary/
├── CMakeLists.txt
├── src/
│   ├── hello.c
│   ├── hello.h
│   ├── main.c
└── build/
```

---

## 📌 Tworzenie Pliku `CMakeLists.txt`
### 🔹 Podstawowa konfiguracja
```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloLibrary C)

set(CMAKE_C_STANDARD 99)
```

### 🔹 Katalogi dla plików wynikowych
```cmake
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
```

### 🔹 Dodanie biblioteki statycznej i dynamicznej
```cmake
add_library(hello_library_static STATIC src/hello.c)
add_library(hello_library_shared SHARED src/hello.c)
```

### 🔹 Tworzenie pliku wykonywalnego
```cmake
add_executable(hello_app src/main.c)
```

### 🔹 Połączenie pliku wykonywalnego z biblioteką
```cmake
target_link_libraries(hello_app PRIVATE hello_library_static)
```

### 🔹 Dodanie katalogu z nagłówkami
```cmake
target_include_directories(hello_app PRIVATE src)
```

---

## 🏗 Budowanie Projektu
### 🔹 Tworzenie katalogu `build` i uruchomienie CMake
```sh
mkdir build && cd build
cmake ..
make
```

---

## 🔎 Sprawdzanie Zawartości

### 🔹 Pliki wynikowe
Po kompilacji pliki będą w `build/`:
- `bin/hello_app` – plik wykonywalny
- `lib/libhello_library_static.a` – biblioteka statyczna
- `lib/libhello_library_shared.so` – biblioteka dynamiczna

### 🔹 Uruchamianie aplikacji
```sh
./bin/hello_app
```

---

## 🛠 CMake w Praktyce
### 🔹 Sprawdzanie zmiennych CMake
```sh
cmake --help-variable CMAKE_C_COMPILER
```

### 🔹 Czyszczenie katalogu build
```sh
rm -rf build/
```

### 🔹 Debugowanie konfiguracji
```sh
cmake -DCMAKE_VERBOSE_MAKEFILE=ON ..
```

---