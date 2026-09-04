# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build and Test Commands

### Prerequisites
- CMake 3.28.3+, Qt6 (Core + Widgets), GoogleTest
- A devcontainer is available with all dependencies pre-installed (Ubuntu 24.04, Clang 22, Qt6, GTest)

### Build
- Build the project: `cmake -B build && cmake --build build`
- Rebuild from scratch: `rm -rf build && cmake -B build && cmake --build build`

### Test
The project uses GoogleTest.
- Run all tests: `cmake --build build && ./build/test_json-visualize`
- Run a specific test: `./build/test_json-visualize --gtest_filter=TestSuite.TestName`

### Static Analysis
- `.clang-tidy` is configured with Google style, enabling bugprone, performance, portability, modernize, readability, and cppcoreguidelines checks.
- `.clang-format` uses Google style with ColumnLimit: 120.

## Project Structure

- `CMakeLists.txt`: Root CMake configuration. C++17, exports compile_commands.json, links Qt6 and nlohmann/json.
- `3dparty/json`: Git submodule for `nlohmann/json` (currently empty — run `git submodule update --init` to populate).
- `src/app`: Main Qt6 application.
    - `main.cpp`: Entry point. Creates QApplication and MainWindow.
    - `mainwindow.h`/`.cpp`/`.ui`: Single MainWindow subclassing QMainWindow. UI has a QScrollArea with a QPlainTextEdit and an empty top toolbar.
- `test/main_test.cpp`: Single GoogleTest test (placeholder).
- `.devcontainer/devcontainer.json`: Dev container config (Clang 22, Qt6, GTest, Ninja generator).
- `.clang-tidy`, `.clang-format`: Clang tooling configuration.

## Architecture

This is a minimal Qt6 desktop application scaffolded for a JSON visualizer. The app has:
- A single `MainWindow` with a `QMainWindow` base, using Qt's UI files (uic) for layout.
- The UI consists of a scrollable `QPlainTextEdit` (for displaying JSON content) and an empty toolbar/status bar.
- Dependencies: `nlohmann/json` (via git submodule) for JSON parsing, Qt6 Core/Widgets for the UI.
- The project is not yet functionally implemented — `main.cpp` and `mainwindow.cpp` are minimal scaffolding with no JSON parsing or UI logic wired up yet.
