// Copyright (c) 2011 Cloudera, Inc. All rights reserved.

#ifndef IMPALA_EXPRS_LITERAL_PREDICATE_H_
#define IMPALA_EXPRS_LITERAL_PREDICATE_H_

#include <string>
#include "exprs/predicate.h"

namespace impala {

class TExprNode;

class LiteralPredicate: public Predicate {
 protected:
  friend class Expr;

  LiteralPredicate(const TExprNode& node);

  virtual void Prepare(RuntimeState* state);
  virtual std::string DebugString() const;

 private:
  static void* ComputeFunction(Expr* e, TupleRow* row);
  bool is_null_;
};

}

#endif
