# Chunkbiomes

This is a limited port of certain [Chunkbase](https://www.chunkbase.com/apps/seed-map) search filters to standalone [Cubiomes](https://www.github.com/Cubitect/cubiomes)-esque functions. This way, they can be used in C/C++ programs to check thousands of seeds per second for various features, which is impossible to do with the website alone.

For an (unfinished) GUI implementing certain functions from this library, see [ChunkbiomesGUI](https://github.com/MZEEN2424/ChunkBiomesGUI) by MZEEN2424.

## C/C++ Compiling
A static archive of this library can be created by
1. Installing [CMake](https://cmake.org/download) and a Makefile generator of your choice (such as [GNU Make](https://www.gnu.org/software/make/#download) for Linux or [MinGW](https://www.mingw-w64.org/downloads) for Windows).
2. Downloading and extracting this repository, or cloning it via Git.
3. Opening a terminal of your choice, navigating to the folder containing this repository's files, and running
```bash
cmake -G "[Makefile generator to use]" .
```
4. After CMake finishes, running your makefile generator (e.g. `make` if using GNU Make or `mingw32-make.exe` if using MinGW). That should create a file similar to `chunkbiomes_static.a` or `chunkbiomes_static.dll.a`.

At this point, you can link the archive to your own C/C++ program by
1. Installing a C/C++ compiler of your choosing (such as [gcc](https://gcc.gnu.org/install/binaries.html)), and
- Running
```bash
gcc "path/to/your/program" "path/to/the/Chunkbiomes/static/archive" -o "desiredProgramExecutableName"
```
in your terminal of choice.

## Notices and Acknowledgements
Logic differentiating between Bastion Remnants and Fortresses has not been added yet.

As stated in [the license](.\LICENSE), this library is a port of code originally written by [Alexander Gundermann and any other developers of Chunkbase](<https://www.chunkbase.com/legal-notice>). Rights to ported code therefore belong to him, not myself.

This is not an official Minecraft product and has not been endorsed by Mojang A.B. or Microsoft Corporation.

Thank you to Fragrant_Result_186 for calculating the salt, region size, and separation of Ancient Cities.