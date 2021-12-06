#ifndef __FIR_AST_WHILE_NODE_H__
#define __FIR_AST_WHILE_NODE_H__

#include <cdk/ast/expression_node.h>

namespace fir {

  /**
   * Class for describing while-cycle nodes.
   */
  class while_node: public cdk::basic_node {
    cdk::expression_node *_condition;
    fir::block_node *_block;
    fir::block_node *_finalBlock = nullptr;

  public:
    inline while_node(int lineno, cdk::expression_node *condition, fir::block_node *block, fir::block_node *finalBlock = nullptr) :
        basic_node(lineno), _condition(condition), _block(block), _finalBlock(finalBlock) {
    }

  public:
    inline cdk::expression_node *condition() {
      return _condition;
    }
    inline fir::block_node *block() {
      return _block;
    }
    inline fir::block_node *finalBlock() {
      return _finalBlock;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_while_node(this, level);
    }

  };

} // fir

#endif
