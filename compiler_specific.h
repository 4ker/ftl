// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef LIB_FTL_COMPILER_SPECIFIC_H_
#define LIB_FTL_COMPILER_SPECIFIC_H_

// Annotate a variable indicating it's ok if the variable is not used.
// (Typically used to silence a compiler warning when the assignment
// is important for some other reason.)
// Use like:
//   int x = ...;
//   ALLOW_UNUSED_LOCAL(x);
#define FTL_ALLOW_UNUSED_LOCAL(x) false ? (void)x : (void)0

// Annotate a typedef or function indicating it's ok if it's not used.
// Use like:
//   typedef Foo Bar ALLOW_UNUSED_TYPE;
#define FTL_ALLOW_UNUSED_TYPE __attribute__((unused))

// Annotate a function indicating it should not be inlined.
// Use like:
//   NOINLINE void DoStuff() { ... }
#define FTL_NOINLINE __attribute__((noinline))

// Specify memory alignment for structs, classes, etc.
// Use like:
//   class ALIGNAS(16) MyClass { ... }
//   ALIGNAS(16) int array[4];
#define FTL_ALIGNAS(byte_alignment) __attribute__((aligned(byte_alignment)))

// Return the byte alignment of the given type (available at compile time).
// Use like:
//   ALIGNOF(int32)  // this would be 4
#define FTL_ALIGNOF(type) __alignof__(type)

// Annotate a function indicating the caller must examine the return value.
// Use like:
//   int foo() WARN_UNUSED_RESULT;
// To explicitly ignore a result, see |ignore_result()| in base/macros.h.
#define FTL_WARN_UNUSED_RESULT __attribute__((warn_unused_result))

// Tell the compiler a function is using a printf-style format string.
// |format_param| is the one-based index of the format string parameter;
// |dots_param| is the one-based index of the "..." parameter.
// For v*printf functions (which take a va_list), pass 0 for dots_param.
// (This is undocumented but matches what the system C headers do.)
#define FTL_PRINTF_FORMAT(format_param, dots_param) \
  __attribute__((format(printf, format_param, dots_param)))

#endif  // LIB_FTL_COMPILER_SPECIFIC_H_
