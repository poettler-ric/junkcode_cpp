cmake_minimum_required(VERSION 3.30)

project(test_types VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_ASAN "Enable AddressSanitizer" YES)
if (MSVC)
    # warning level 4
    add_compile_options(/W4)

    if(ENABLE_ASAN)
      string(REPLACE "/RTC1" "" CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
      string(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
      add_compile_options(/fsanitize=address /fsanitize-address-use-after-return)
    endif()
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
      -Wall
      -Wextra
      -Wpedantic
      -Wshadow
      -Wconversion
      -Werror
      -Wfloat-equal
      -Wformat-nonliteral
      -Wformat-security
      -Wformat-y2k
      -Wformat=2
      -Wimport
      -Winvalid-pch
      -Wlogical-op
      -Wmissing-declarations
      -Wmissing-field-initializers
      -Wmissing-format-attribute
      -Wmissing-include-dirs
      -Wmissing-noreturn
      -Wpacked
      -Wpointer-arith
      -Wredundant-decls
      -Wstack-protector
      -Wstrict-null-sentinel
      -Wswitch-enum
      -Wundef
      -Wwrite-strings
    )

    option(ENABLE_LSAN "Enable LeakSanitizer" NO)
    option(ENABLE_TSAN "Enable ThreadSanitizer" NO)
    option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" YES)
    if(NOT APPLE)
      option(ENABLE_MSAN "Enable MemorySanitizer" NO)
    endif()
    add_compile_options(
      -fno-omit-frame-pointer
      $<$<BOOL:${ENABLE_ASAN}>:-fsanitize=address>
      $<$<BOOL:${ENABLE_LSAN}>:-fsanitize=leak>
      $<$<BOOL:${ENABLE_MSAN}>:-fsanitize=memory>
      $<$<BOOL:${ENABLE_TSAN}>:-fsanitize=thread>
      $<$<BOOL:${ENABLE_UBSAN}>:-fsanitize=undefined>
    )
    add_link_options(
      $<$<BOOL:${ENABLE_ASAN}>:-fsanitize=address>
      $<$<BOOL:${ENABLE_LSAN}>:-fsanitize=leak>
      $<$<BOOL:${ENABLE_MSAN}>:-fsanitize=memory>
      $<$<BOOL:${ENABLE_TSAN}>:-fsanitize=thread>
      $<$<BOOL:${ENABLE_UBSAN}>:-fsanitize=undefined>
    )
endif()

add_executable(types src/main.cpp)

