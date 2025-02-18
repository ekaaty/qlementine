# Usage

## Installation

1. Add the library as a dependency with CMake FetchContent.

   ```bash
   include(FetchContent)
   FetchContent_Declare(Qlementine GIT_REPOSITORY "https://github.com/oclero/qlementine.git")
   FetchContent_MakeAvailable(Qlementine)
   ```

2. Link with the library in CMake.

   ```cmake
   target_link_libraries(your_project oclero::qlementine)
   ```

## Usage in code

Define the `QStyle` on your `QApplication`.

```c++
#include <oclero/qlementine.hpp>

QApplication app(argc, argv);

auto* style = new oclero::qlementine::QlementineStyle(&app);
style->setThemeJsonPath(":/light.json");
QApplication::setStyle(style);
```
