/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef ALLOY_COMPILER_COMPILER_H_
#define ALLOY_COMPILER_COMPILER_H_

#include <alloy/core.h>
#include <alloy/hir/hir_builder.h>

namespace alloy { namespace runtime { class Runtime; } }


namespace alloy {
namespace compiler {

class CompilerPass;


class Compiler {
public:
  Compiler(runtime::Runtime* runtime);
  ~Compiler();

  runtime::Runtime* runtime() const { return runtime_; }

  void AddPass(CompilerPass* pass);

  void Reset();

  int Compile(hir::HIRBuilder* builder);

private:
  runtime::Runtime* runtime_;

  typedef std::vector<CompilerPass*> PassList;
  PassList passes_;
};


}  // namespace compiler
}  // namespace alloy


#endif  // ALLOY_COMPILER_COMPILER_H_
